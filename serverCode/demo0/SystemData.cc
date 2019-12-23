#include "SystemData.h"
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<errno.h>
#include<mysql/mysql.h>
using namespace std;
SystemData::SystemData(/* args */)
{
    //初始化连接句柄
    connect = mysql_init(NULL);
    if(connect == NULL)
    {
        //返回null初始化失败
        printf("mysql_init failed!\n");
        exit(0);
    }

   connectMysql("localhost","root","Z001221z","user");
}

SystemData::~SystemData()
{
    mysql_close(connect);
}

void SystemData::connectMysql(char *ip,char * user,char* password,char* database)
{
    //连接数据库
    connect =mysql_real_connect(connect,ip,user,password,database,0,NULL,0);
    if (connect) {
    printf("Connection success!\n");
  } else {
    printf("Connection failed!\n");
  }
  mysql_query(connect,"set names utf8");//防止乱码。设置和数据库的编码一致就不会乱码
}

int SystemData::LastId()
{
    //查询数据库中最后一个用户id
    int id;
    string sql = "select id from user_info;";
    if(!mysql_query(connect,sql.data()))
    {
        //把查询结果给res_ptr
        res_ptr = mysql_store_result(connect);
        //cout<<"line49"<<endl;
        //如果结果不为空,则输出
        if(res_ptr!=NULL)
        {
            //cout<<"line53"<<endl;
            //cout<<"chax xun hao"<<endl;
            //cout<<"查询结果"<<endl;
            while(result_row=mysql_fetch_row(res_ptr))
            {
                for(int t=0;t<mysql_num_fields(res_ptr);t++)
                {
                    id = atoi(result_row[t]);
                }
              //  cout<<"line66 result is: "<<result<<endl;
            }
            mysql_free_result(res_ptr);
            
        }
        else{
            //查询结果空
            return 0; 
        }

    }   
    else{
        perror("my_query");
        mysql_close(connect);
        exit(0);
    }
    printf("最后一个 id %d\n",id);//row就是个数组
    return id;
}
bool SystemData::query_sql(string sql)
{
    if(!mysql_query(connect,sql.data()))
    {
        return true;
    }
    else{
        cout<<"执行sql出错"<<endl;
        mysql_close(connect);
        exit(0);
    }


}

string SystemData::queryFriend(string sql)
{
     string temp = "error";
     string result = "#";
   // cout<<"line44 sql.data "<<sql.data()<<endl;;
    //传入sql语句，将查询结果以char×返回
    
    if(!mysql_query(connect,sql.data()))
    {
        //把查询结果给res_ptr
        res_ptr = mysql_store_result(connect);
        //cout<<"line49"<<endl;
        //如果结果不为空,则输出
        if(res_ptr!=NULL)
        {
            //cout<<"line53"<<endl;
            //cout<<"chax xun hao"<<endl;
            //cout<<"查询结果"<<endl;
            while(result_row=mysql_fetch_row(res_ptr))
            {
                for(int t=0;t<mysql_num_fields(res_ptr);t++)
                {
                    printf("%s\n",result_row[t]);//row就是个数组
                    result.insert(result.size(),result_row[t]);
                    result.insert(result.size()," ");
                }
                result.insert(result.size(),"#");
               // cout<<"line66 result is: "<<result<<endl;
            }
            mysql_free_result(res_ptr);
            
        }
        else{
            //查询结果空
            return temp; 
        }

    }   
    else{
        perror("my_query");
        mysql_close(connect);
        exit(0);
    }
    return result;
    
}
string SystemData::query(string sql)
{
    string temp = "error";
   // cout<<"line44 sql.data "<<sql.data()<<endl;;
    //传入sql语句，将查询结果以char×返回
    if(!mysql_query(connect,sql.data()))
    {
        //把查询结果给res_ptr
        res_ptr = mysql_store_result(connect);
        //cout<<"line49"<<endl;
        //如果结果不为空,则输出
        if(res_ptr!=NULL)
        {
            //cout<<"line53"<<endl;
            //cout<<"chax xun hao"<<endl;
            result_row = mysql_fetch_row(res_ptr);
            if(result_row!=NULL)
            {
              //  cout<<"line58"<<endl;
                temp = result_row[0];
            }
            mysql_free_result(res_ptr);
            
        }
        else{
            //查询结果空
            return temp; 
        }

    }   
    else{
        perror("my_query");
        mysql_close(connect);
        exit(0);
    }
    return temp;
    
}
