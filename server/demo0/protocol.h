 #ifndef  __PROTOCOL_H__

#define   __PROTOCOL_H__
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <unistd.h>
#include "SystemData.h"
#include "listen.h"
using namespace std;
SystemData database;    //数据库
void initData()
{
    //database.connectMysql("localhost","root","Z001221z","user");
}



bool logininfo(string id,string password)
{
    //判断登录信息，正确返回true
   // id = "100001";
    string sql = "select password from user_info where(id=);";
    sql.insert(40,id);
    string pass = database.query(sql);
    if(pass == "error")
    {
        return false;
    }
    else if(pass == password)
    {
        return true;
    }
    return false;
}


int loginDeal(char info[1024],int connect_fd)
{
    //消息类型为登录.成功返回id
    char user[10]={0};
    char password[16]={0};
    int i = 0;
    for(int j=0;i<strlen(info);i++,j++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        }
    }
    for(int j = 0;i<strlen(info);i++,j++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        }
        user[j] = info[i]; 
        cout<<info[i];
    }
   // cout<<endl;

    for(int j = 0;i<strlen(info);i++,j++)
    {
        if(info[i] == ' ')
        {
            break;
        }
        password[j] = info[i]; 
        cout<<info[i];
    }
    //cout<<endl;
    //cout<<"user is:"<<user<<endl;
    //cout<<"pass is:"<<password<<endl;
    //判断登录信息
    char temp[18] = "success ";
    char temp_error[6] = "error";
    int id;
    string sql = "UPDATE `user`.`user_info` SET `status`='1' WHERE `id`=;";
    if(logininfo(user,password))
    {
        for(int i=0,j=8;i<strlen(user);i++,j++)
        {
            temp[j] = user[i];
        }
        sql.insert(54,user);
        database.query(sql);
        send(connect_fd,&temp,sizeof(temp),0);
        id = atoi(user);
        //cout<<"line 96 char to int "<<id<<endl;
        return id;
    }
    else{
        send(connect_fd,&temp_error,sizeof(temp_error),0);
        return 0;
    }

}
void messageDeal(char info[1024],int connect_fd,Listen lis)
{
    //处理消息
    char sendid[10] = {0};
    char recv[10] = {0};
    char data[1024] = {0};
    char temp[1024] = "message ";
    int i = 0;
    for(i=0;i<strlen(info);i++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        } 
    }
    for(int j = 0;i<strlen(info);i++,j++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        }
        sendid[j] = info[i]; 
    }
    for(int j = 0;i<strlen(info);i++,j++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        }
        recv[j] = info[i]; 
    }
    for(int j = 0;j<1024;i++,j++)
    {
        data[j] = info[i]; 
    }
    cout<<"data is: "<<data<<endl;
    int j;
    for(i=8,j=0;j<strlen(sendid);i++,j++)
    {
        temp[i] = sendid[j];
    }
    temp[i] = ' ';
    i++;
    for(j=0;i<1024;j++,i++)
    {
        temp[i] = data[j];
    }
    int temp_id = atoi(recv);
    int temp_fd = lis.getFd(temp_id);
    //send(temp_fd,&info,sizeof(info),0);
    //info = "message 10001 10003 sdfdsf";
    if(-1!=temp_fd)
    {
        //接收者在线
        send(temp_fd,&temp,sizeof(temp),0);
        cout<<sendid<<"发送给"<<temp_id<<"data is :"<<temp<<endl;

    }
    else{
        //接收者离线
    }


}

void registerDeal(char info[1024],int connect_fd)
{
    //注册请求处理
    char name[10] = {0};
    char user[20] = {0};
    char reist[50] = {0};
    char email[20] = {0};
    char password[20] = {0};
    char icon[3] = {0};
    int i = 0;
    for(i=0;i<strlen(info);i++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        } 
    }
    for(int j = 0;i<strlen(info);i++,j++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        }
        name[j] = info[i]; 
    }
    for(int j = 0;i<strlen(info);i++,j++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        }
        user[j] = info[i]; 
    }
    for(int j = 0;i<strlen(info);i++,j++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        }
        reist[j] = info[i]; 
    }
    for(int j = 0;i<strlen(info);i++,j++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        }
        email[j] = info[i]; 
    }
    for(int j = 0;i<strlen(info);i++,j++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        }
        password[j] = info[i]; 
    }
    for(int j = 0;i<strlen(info);i++,j++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        }
        icon[j] = info[i]; 
    }
    int id = database.LastId()+3;
    string sqltemp = "INSERT INTO `user`.`user_info` (`id`, `password`, `name`, `user`, `signature`, `e-mail`, `icon`, `status`) VALUES ('";
    char id_str[10] = {0};
    sprintf(id_str,"%d",id);

    sqltemp.append(id_str);
    sqltemp.append("', '");
    sqltemp.append(password);
    sqltemp.append("', '");
    sqltemp.append(name);
    sqltemp.append("', '");
    sqltemp.append(user);
    sqltemp.append("', '");
    sqltemp.append(reist);
    sqltemp.append("', '");
    sqltemp.append(email);
    sqltemp.append("', '");
    sqltemp.append(icon);
    sqltemp.append("', '");
    sqltemp.append("0'");
    sqltemp.append(");");

    cout<<"sql is "<<sqltemp<<endl;
    char str[30] = "register_su ";
    int j;
    for(i = 12,j=0;j<strlen(id_str);j++,i++)
    {
        str[i] = id_str[j];
    }
    if(database.query_sql(sqltemp))
    {
        //写入成功
        cout<<"发送给客户端的是 "<<str<<endl;
        send(connect_fd,&str,sizeof(str),0);
        sqltemp = "INSERT INTO `user`.`friend` (`id_my`, `id_friend`) VALUES ('100001', '');";
        //cout<<"line279 sql is: "<<sqltemp<<endl;
        sqltemp.insert(70,id_str);
        cout<<"line279 sql is: "<<sqltemp<<endl;
        database.query_sql(sqltemp);
        sqltemp = "INSERT INTO `user`.`friend` (`id_my`, `id_friend`) VALUES ('', '100001');";
        sqltemp.insert(60,id_str);
        cout<<"line279 sql is: "<<sqltemp<<endl;
        database.query_sql(sqltemp);
    }




}
void initDeal(char info[1024],int connect_fd)
{
    //处理加载信息请求
    char user[10]={0};
    int i = 0;
    for(int j=0;i<strlen(info);i++,j++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        }
    }
    for(int j = 0;i<strlen(info);i++,j++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        }
        user[j] = info[i]; 
    }
    //找到对应的信息
    //char user_name[10] = "kid ";
    //char user_icon[3] = "01";
    string sql = "select icon from user_info where(id=);";
    sql.insert(36,user);
    string icon = database.query(sql);
    sql = "select user from user_info where(id=);";
    sql.insert(36,user);
    string username = database.query(sql);
    sql = "select signature from user_info where(id=);";
    sql.insert(41,user);
    string sig = database.query(sql);
    //组包
    char temp[128] = "userinfo ";
    int j;
    for(i=9,j=0;i<sizeof(temp)&&j<strlen(user);i++,j++)
    {
        temp[i] = user[j];
    }
    temp[i] = ' ';
    i++;
    for(j=0;i<sizeof(temp)&&j<username.size();i++,j++)
    {
        temp[i] = username.at(j);
    }
    temp[i] = ' ';
    i++;
    for(j=0;i<sizeof(temp)&&j<icon.size();i++,j++)
    {
        temp[i] = icon.at(j);
    }
    temp[i] = ' ';
    i++;
    for(j=0;i<sizeof(temp)&&j<sig.size();i++,j++)
    {
        temp[i] = sig.at(j);
    }

    cout<<"user:"<<user<<endl;
    cout<<temp<<endl;
    send(connect_fd,&temp,sizeof(temp),0);
    
}

void initFriendDela(char info[1024],int connect_fd)
{
    string temp = "friendinfo ";
    string temp_group = "groupinfo ";
    //处理好友列表加载请求
    char user[10]={0};
    int i = 0;
    for(int j=0;i<strlen(info);i++,j++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        }
    }
    for(int j = 0;i<strlen(info);i++,j++)
    {
        if(info[i] == ' ')
        {
            i++;
            break;
        }
        user[j] = info[i]; 
    }
    //返回好友
    //cout<<"init fronmde dela"<<endl;
    string sql = "select id,user,signature,icon,status from user_info where(id in(select id_friend from friend where id_my =));";
    sql.insert(106,user);
    temp.insert(11,database.queryFriend(sql));
    //cout<<"line 198 frinedn: "<<temp<<endl;
    send(connect_fd,temp.data(),temp.size(),0);
    //返回群组
    string sql_ = "select group_id,group_name,signature,icon,status from group_info where(group_id in(select group_id from `group` where id =));";
    sql_.insert(122,user);
    cout<<"line 205sql: "<<sql_<<endl;
    temp_group.insert(10,database.queryFriend(sql_));
    cout<<"zhun bei send"<<endl;
    send(connect_fd,temp_group.data(),temp_group.size(),0);


}

#endif