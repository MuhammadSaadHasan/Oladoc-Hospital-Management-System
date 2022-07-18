#pragma once
#ifndef DATEANDTIME_H
#define DATEANDTIME_H

#include <iostream>
#include <cstring>
using namespace std;


class DateAndTime
{

	private:
		char time[50];
		char day[50];
		char date[50];
		
	public:
		void setTime(string);
		void setDate(string);

		
		char* getTime();
		char* getDay();
		char* getDate();
		



};





#endif