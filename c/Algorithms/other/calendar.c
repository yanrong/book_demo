#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long int ulong;

#define WeekLen 7		//һ�ܵĳ���
#define MonthLen 12		//һ���·ݵĳ���
#define YearDays 365		//һ�������
#define PntWidth 4		//��ӡ�Ŀ��
#define ChineseWidth 2		//���Ĵ�ӡ���

//ϵͳ����ռ�õ��ֽ���
const int ChineseSize = sizeof("��") - 1;

//���ڵ�����
char const *Week_str[WeekLen] = {"��", "һ", "��", "��", "��", "��", "��"};
//�·�����
char const *Month_str[MonthLen] = {"ʮ��", "һ", "��", "��", "��", "��", "��", "��", "��", "��", "ʮ", "ʮһ"};
//ÿ�µ�����
int const MonthDays[MonthLen] =  {31,28,31,30,31,30,31,31,30,31,30,31};

//����
typedef struct
{
	int year,month,day;
}Date;

//��׼����
const Date Std_Date = {1991,11,10};
//��׼ʱ�������
const int Std_Date_Weekday = 0;
//һ�ܿ�ʼ������
const int Week_Start = 0;

//��ӡ����
void PntTitle(int year,int month)
{
	char fmt[10];
	//������ӡ���
	int width = PntWidth * (WeekLen-1) + ChineseWidth;

	month = month % MonthLen;

	width -= strlen(Month_str[month]) / ChineseSize * ChineseWidth;
	width -= ChineseWidth *  2;
	width -= 4 + 1 + PntWidth/2;
	width /= 2;

	//��ӡ�հ�
	while (width--)
	{
		printf(" ");
	}

	printf("%d��",year);
	sprintf(fmt,"%%%ds",PntWidth/2);
	printf(fmt,"");
	printf("%s��\n",Month_str[month]);
}

//��ӡ����

void PntWeekday(int w_start)
{
	int i = w_start;
	char fmt[10];

	//�����ӡ���
	sprintf(fmt,"%%-%ds",ChineseSize + PntWidth - ChineseWidth);
	do
	{
		printf(fmt,Week_str[i]);
		i = (i+1) % WeekLen;
	} while (i != w_start);
	printf("\n");
}

//��ӡ����
void PntDate(int w_start,int d_start,int d_len)
{
	int i,week;
	char fmt[10];

	//�ݴ���
	w_start = w_start % WeekLen;
	d_start = d_start % WeekLen;

	//��ӡ�հ�
	sprintf(fmt,"%%-%ds",PntWidth);
	for (i = w_start,week = 0;i != d_start && week < 7;i = (i+1) % WeekLen,week++)
	{
		printf(fmt,"");
	}

	//��ʽ��ӡ
	sprintf(fmt,"%%%dd%%-%ds",2,PntWidth-2);
	for (i = 1;i <= d_len;i++,week++)
	{
		if (week == WeekLen)
		{
			week = 0;
			printf("\n");
		}
		printf(fmt,i,"");
	}
	printf("\n");
}

//�ж�����
int isLeapYear(int year)
{
	if (!(year%100))
	{
		year /= 100;
	}
	return !(year%4);
}

//�������ڲ�,d1Ӧ����d2֮ǰ
ulong GetDays(Date d1,Date d2)
{
	int i;
	ulong days = 0;

	//���ڶ���
	days = d2.day - d1.day;

	//�·ݶ���
	for (i = 1;i < d2.month;i++)
	{
		if (i == 2)
		{
			days += isLeapYear(d2.year);
		}
		days += MonthDays[i-1];
	}
	for (i = 1;i < d1.month;i++)
	{
		if (i ==2)
		{
			days -= isLeapYear(d1.year);
		}
		days -= MonthDays[i-1];
	}

	for (i = d1.year;i < d2.year;i++)
	{
		days += YearDays + isLeapYear(i);
	}
	return days;
}

//��������
inline int _setDate(int year,int month,int day,Date *d1,Date *d2)
{
	d1->year = Std_Date.year;
	d1->month = Std_Date.month;
	d1->day = Std_Date.day;

	d2->year = year;
	d2->month = month;
	d2->day = day;
	return 1;
}

//��ȡ��Ӧ���ڵ�����
int GetWeekDay(int year,int month,int day)
{
	Date d1,d2;
	int week;
	int flag = 0;

	d1.year = year;
	d1.month = month;
	d1.day = day;

	d2.year = Std_Date.year;
	d2.month = Std_Date.month;
	d2.day = Std_Date.day;

	if (year > Std_Date.year)
	{
		flag = _setDate(year,month,day,&d1,&d2);
	}
	else if (year == Std_Date.year)
	{
		if (month > Std_Date.month)
		{
			flag = _setDate(year,month,day,&d1,&d2);
		}
		else if (month == Std_Date.month && day > Std_Date.day)
		{
			flag = _setDate(year,month,day,&d1,&d2);
		}
	}

	week = GetDays(d1,d2) % WeekLen;

	if (flag)
	{
		return (int)((week + Std_Date_Weekday) % WeekLen);
	}
	return WeekLen - (week + Std_Date_Weekday);
}

//��������
void Calendar(int year,int month)
{
	int d_start = GetWeekDay(year,month,1);
	int d_len = MonthDays[month-1];

	if (month == 2)
	{
		d_len += isLeapYear(year);
	}

	PntTitle(year,month);
	PntWeekday(Week_Start);
	PntDate(Week_Start,d_start,d_len);
}

int main(int argc, char* argv[])
{
	int year = 0,month = 0;
	char buf[128];

	if (argc >= 3)
	{
		year = atoi(argv[1]);
		month = atoi(argv[2]);
	}
	else
	{
		printf("Please input the Date like YYYY-MM-DD:");
		fgets(buf,sizeof(buf)-1,stdin);
		sscanf(buf,"%d-%d-%*d",&year,&month);
	}
	if (month > 0 && month <= MonthLen)
	{
		Calendar(year,month);
		return 0;
	}
	else
	{
		printf("Date Err!\n");
		return -1;
	}
}
