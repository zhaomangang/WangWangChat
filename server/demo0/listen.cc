#include "listen.h"
#include "protocol.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int Listen::count = 0;  //初始化连接数
Listen::Listen(/* args */)
{
    //初始化

    for(int i=0;i<100;i++)
    {
        use[i].connect_fd = -1;
        use[i].id =-1;
    }
    listen_sock = socket(AF_INET,SOCK_STREAM,0);    //监听本地所有端口
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = INADDR_ANY;
    local_addr.sin_port = htons(8888);  //设置端口

    res = bind(listen_sock, (struct sockaddr*)&local_addr, sizeof(local_addr));
    if(res < 0)
    {
		//绑定套接字失败
        cout << "bind error!\n";
        exit(1);
    }

    res = listen(listen_sock, 5);
    if(res < 0)
    {
        cout << "listen error!\n";
        exit(2);
    }

    int epollfd = epoll_create(10);
    if(epollfd < 0)
    {
        cout << "epoll_create error!\n";
        exit(3);
    }
    event.events = EPOLLIN;
    event.data.fd = listen_sock;
    res = epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &event);       //向epoll中添加监视事件(哪个文件描述符上的哪个事件)
    if(res < 0)
    {
        cout << "epoll_ctl error!\n";
        exit(4);
    }

   for(;;)
    {
        int size = epoll_wait(epollfd, events, sizeof(events)/sizeof(events[0]), -1);
        if(size < 0)
        {
            cout << "epoll_wait error!\n";
            continue;
        }

        if(size == 0)
        {
            cout << "timeout\n";
            continue;
        }
        for(int i = 0; i < size; ++i)
        {
            if(!(events[i].events & EPOLLIN))
                continue;

            if(events[i].data.fd == listen_sock)
            {
                ProcessConnect(listen_sock, epollfd);           //处理连接请求
                
            }
            else
                ProcessRequest(events[i].data.fd, epollfd);     //处理已有连接上的数据
        }

    }
    //初始化数据库
    //initData();
}

int Listen::getFd(int id)
{
    for(int i=0;i<count;i++)
    {
        if(use[i].id == id)
        {
            return use[i].connect_fd;
        }
    }
    return -1;

}
Listen::Listen(const Listen & c)   //拷贝构造函数
{
    for(int i=0;i<count;i++)
    {
        this->use[i].id = c.use[i].id;
        this->use[i].connect_fd = c.use[i].connect_fd;
    }

}
Listen::~Listen()
{

}
void Listen::ProcessConnect(int listen_sock, int epollfd)
{
	//处理连接请求
    struct sockaddr_in client_addr;	//
    socklen_t addrlen = sizeof(client_addr);

    int connect_fd = accept(listen_sock, (struct sockaddr*)&client_addr, &addrlen);
    if(connect_fd < 0)
    {
        cout << "accept error!\n";
        return;
    }
    cout << "client " << inet_ntoa(client_addr.sin_addr) << ":" << ntohs(client_addr.sin_port) << " connect!\n" << endl;
    
    struct epoll_event ev;
    ev.data.fd = connect_fd;
    ev.events = EPOLLIN;
    //protocol.addUser(connect_fd);   //添加到已连接用户列表
    int res = epoll_ctl(epollfd, EPOLL_CTL_ADD, connect_fd, &ev);       //将新建立的连接也添加进epoll监视事件中
    if(res < 0)
    {
        cout << "epoll_ctl error!\n";
    }
}

void Listen::ProcessRequest(int connect_fd, int epollfd)
{
	//处理已经建立连接的请求
    char buf[1024] = {0};
    ssize_t read_size = recv(connect_fd, buf, sizeof(buf) - 1, 0);
    if(read_size < 0)
    {
        cout << "recv error!\n";
        return;
    }

    if(read_size == 0)
    {
        cout << "client say bye bye" << endl;
        delUse(connect_fd);
        close(connect_fd);
        epoll_ctl(epollfd, EPOLL_CTL_DEL, connect_fd, NULL);            //从epoll监视事件中删除该对连接的监视
        
        
        return;
    }
    cout << "client say: " << buf << endl;

    
    judgementInfo(buf,connect_fd); //处理客户端消息

    
}

void Listen::judgementInfo(char info[1024],int connect_fd)
{
    //处理客户端消息
    char type[20]={0};
    int temp_type = -1;
    for(int i=0;i<strlen(info);i++)
    {
        //从客户端发来的字符串中取出消息类型
        if(info[i] == ' ') break;
        type[i] = info[i];
    }
    cout<<"type is"<<type<<endl;
    //对消息类型进行编码
    if(0==strcmp(type,"login"))
    {
        //登录信息
        temp_type = 0;
    }
    else if(0==strcmp(type,"inituser"))
    {
        //主界面加载用户图像等信息
        temp_type = 1;
    }
    else if(0==strcmp(type,"message"))
    {
        temp_type = 2;
    }
    else if(0==strcmp(type,"initfriend"))
    {
        temp_type = 3;
        //cout<<"line 165 init type = 3"<<endl;
    }
    else if(0==strcmp(type,"register"))
    {
        temp_type = 4;
    }else if(0==strcmp(type,"groupmessage"))
    {
        temp_type = 5;
    }
    //cout<<"judge"<<endl;
    int id_temp=0;
    switch (temp_type)
    {
    case 0:
        //cout<<"case 0"<<endl;
        id_temp = loginDeal(info,connect_fd);
        if(0!=id_temp) addUse(id_temp,connect_fd);
        break;
    case 1:
        initDeal(info,connect_fd);
        break;
    case 2:
        messageDeal(info,connect_fd,*this);
        //cout<<"case 2"<<endl;
        //protocol.messageDeal(info,csonnect_fd);
        break;
    case 3:
        //加载好友
        initFriendDela(info,connect_fd);
        break;
    case 4:
        registerDeal(info,connect_fd);
        break;
    case 5:
        groupMessageDeal(info,connect_fd,*this);
        break;

    default:
       
        break;
    }
    //login User Password
    //return false;      
}
user Listen::getUser(int i)
{
    return use[i];
}
void Listen::addUse(int id,int con_fd)
{
    this->use[count].id = id;
    this->use[count].connect_fd = con_fd;
    count++;
    for(int i=0;i<count;i++)
    {
        cout<<"add user id is"<<use[i].id<<"\t"<<"fd is"<<use[i].connect_fd<<endl;
    }
}

void Listen::delUse(int con_fd)
{
    int i;
    char str[10];
    string sql = "UPDATE `user`.`user_info` SET `status`='0' WHERE `id`=;";
    for(i=0;i<count;i++)
    {
        if(use[i].connect_fd == con_fd)
        {
            //string te;
           // int k = use[i].id;
            sprintf(str,"%d",use[i].id);
            sql.insert(54,str);
            database.query(sql);
            cout<<"delete user id is"<<use[i].id<<"\t"<<"fd is"<<use[i].connect_fd<<endl;
            break;
        }
    }
    for(;i<count-1;i++)
    {
        use[i].connect_fd = use[i+1].connect_fd;
        use[i].id = use[i+1].id;
    }
    use[i+1].connect_fd = -1;
    use[i+1].id = -1;
    count--;

}