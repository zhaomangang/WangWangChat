#ifndef  __LISTEN_H__

#define   __LISTEN_H__

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <string.h>
#include "SystemData.h"
using namespace std;
typedef struct Use
{
    int connect_fd;
    int id;
    /* data */
}user;


class Listen
{
private:
    /* data */
    int listen_sock;    //监听套接字
    sockaddr_in local_addr;
    int res;
    epoll_event event;
    epoll_event events[100];
    user use[100];
    static int count;   //当前连接数
    

public:
    Listen(/* args */);
    ~Listen();
    void ProcessConnect(int listen_sock, int epollfd);  //新的连接处理
    void ProcessRequest(int connect_fd, int epollfd);   //已建立的连接请求处理
    void judgementInfo(char info[1024],int connect_fd); //处理客户端消息
    void addUse(int id,int con_fd);
    void delUse(int con_fd);
    int getFd(int id);  //根据id返回套接字
    user getUser(int i);
    Listen(const Listen & c);   //拷贝构造函数
    int getCount()
    {
        return count;
    }
};



#endif