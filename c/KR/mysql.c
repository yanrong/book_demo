
#include <stdio.h>
#include "mysql.h"

int main()
{
    MYSQL conn;
    int res;
    mysql_init(&conn);
    if(mysql_real_connect(&conn,"localhost","username","password","your's DB",0,NULL,CLIENT_FOUND_ROWS))
    {
        printf("Linke Mysql success!\n");
        res=mysql_query(&conn,"insert into children values('20124400','male',22)");
        if(res)
        {
            printf("语句执行失败\n");
            mysql_close(&conn);//记得关闭连接
        }
        else
        {
             printf("语句执行成功\n");
            mysql_close(&conn);
        }
    }
    return 0;
}


