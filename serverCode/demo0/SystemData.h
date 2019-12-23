#ifndef __SYSTEMDATA_H__
#define __SYSTEMDATA_H__
#include<errno.h>
#include <string>
#include<mysql/mysql.h>
using namespace std;
class SystemData
{
private:
    /* data */
    MYSQL *connect; //数据库链接指针
    MYSQL_RES *res_ptr;//指向查询结果的指针
    MYSQL_FIELD *field;//字段结构指针
    MYSQL_ROW result_row;//按行返回查询信息
public:
    SystemData(/* args */);
    ~SystemData();
    void connectMysql(char *ip,char * user,char* password,char* database);   //连接数据库
    string query(string sql);    //执行sql语句接口
    string queryFriend(string sql);
    bool query_sql(string sql);
    int LastId();   //查询最后一个用户id
};


#endif