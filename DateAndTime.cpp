#include <windows.h>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

#include "DateAndTime.h"

//void DateAndTime::setStartHour(int sh)
//{
//	starthour = sh;
//}
//void DateAndTime::setStartMin(int sm)
//{
//	startmin = sm;
//}
//void DateAndTime::setEndHour(int eh)
//{
//	endhour = eh;
//}
//void DateAndTime::setEndMin(int em)
//{
//	endmin = em;
//}
//int DateAndTime::getStartHour()
//{
//	return starthour;
//}
//int DateAndTime::getStartMin()
//{
//	return startmin;
//}
//int DateAndTime::getEndHour()
//{
//	return endhour;
//}
//int DateAndTime::getEndMin()
//{
//	return endmin;
//}

void DateAndTime::setTime(string t)
{
	strcpy_s(this->time, t.c_str());


}


void DateAndTime::setDate(string t)
{
	strcpy_s(this->date, t.c_str());
}

char* DateAndTime::getTime()
{
	return time;
}

char* DateAndTime::getDay()
{
	return day;
}

char* DateAndTime::getDate()
{
	return date;
}
