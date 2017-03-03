#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long int ulong;

#define WeekLen 7		
#define MonthLen 12		
#define YearDays 365		
#define PntWidth 4		
#define ChineseWidth 2		

const int ChineseSize = sizeof("聪") - 1;
char const *Week_str[WeekLen] = {"日", "一", "二", "三", "四", "五", "六"};
char const *Month_str[MonthLen] = {"十二", "一", "二", "三", "四", "五", "六", "七", "八", "九", "十", "十一"};
int const MonthDays[MonthLen] =  {31,28,31,30,31,30,31,31,30,31,30,31};

typedef struct
{
	int year,month,day;
}Date;

const Date Std_Date = {1991,11,10};
const int StdDateWeekday = 0;
const int WeekStart = 0;

void PntTitle(int year,int month)
{
	char fmt[10];
	//get all print Title length
	int width = PntWidth * (WeekLen-1) + ChineseWidth;
	//get month 
	month = month % MonthLen;

	width -= strlen(Month_str[month]) / ChineseSize * ChineseWidth;
	width -= ChineseWidth *  2;
	width -= 4 + 1 + PntWidth/2;
	width /= 2;

	while (width--)
	{
		printf(" ");
	}

	printf("%d年",year);
	sprintf(fmt,"%%%ds",PntWidth/2);
	printf(fmt,"");
	printf("%s月\n",Month_str[month]);
}

void PntWeekday(int w_start)
{
	int i = w_start;
	char fmt[10];
	sprintf(fmt,"%%-%ds",ChineseSize + PntWidth - ChineseWidth);
	do
	{
		printf(fmt,Week_str[i]);
		i = (i+1) % WeekLen;
	} while (i != w_start);
	printf("\n");
}


void PntDate(int w_start,int d_start,int d_len)
{
	int i,week;
	char fmt[10];
	
	w_start = w_start % WeekLen;
	d_start = d_start % WeekLen;

	sprintf(fmt,"%%-%ds",PntWidth);
	for (i = w_start,week = 0;i != d_start && week < 7;i = (i+1) % WeekLen,week++)
	{
		printf(fmt,"");
	}

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

int isLeapYear(int year)
{
	if (!(year%100))
	{
		year /= 100;
	}
	return !(year%4);
}


ulong GetDays(Date d1,Date d2)
{
	int i;
	ulong days = 0;

	days = d2.day - d1.day;

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
		return (int)((week + StdDateWeekday) % WeekLen);
	}
	return WeekLen - (week + StdDateWeekday);
}


void Calendar(int year,int month)
{
	int d_start = GetWeekDay(year,month,1);
	int d_len = MonthDays[month-1];

	if (month == 2)
	{
		d_len += isLeapYear(year);
	}

	PntTitle(year,month);
	PntWeekday(WeekStart);
	PntDate(WeekStart,d_start,d_len);
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
