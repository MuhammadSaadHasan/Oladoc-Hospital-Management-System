#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

#include "appointments.h"
#include "user.h"


appointments::appointments()
{
	AppointmentMode = 'P';

	

}

void appointments::book(appointments temp)
{
	cout << "----------------Appointments" << endl;
	
}

bool appointments::setDateAndTime(string date, string time)
{




	DT.setDate(date);
	DT.setTime(time);


	



	return false;







}
void appointments::SetAppDocName(string str)
{
	strcpy_s(this->AppDocName, str.c_str());
}
void appointments::SetAppPatName(string str)
{
	strcpy_s(this->AppPatName, str.c_str());

}
void appointments::SetAppPatID(string str)
{
	strcpy_s(this->AppPatID, str.c_str());
}
void appointments::SetAppDocID(string str)
{
	strcpy_s(this->AppDocID, str.c_str());

}
void appointments::SetCaseRegarding(string str)
{
	strcpy_s(this->CaseRegarding, str.c_str());

}
void appointments::SetAppointmentMode(char ch)
{
	this->AppointmentMode = ch;
}
char* appointments::GetAppDocName()
{
	return AppDocName;
}
char* appointments::GetAppPatName()
{
	return AppPatName;
}
char* appointments::GetAppPatID()
{
	return AppPatID;
}
char* appointments::GetAppDocID()
{
	return AppDocID;
}
char* appointments::GetCaseRegarding()
{
	return CaseRegarding;
}
char appointments::GetAppointmentMode()
{
	return AppointmentMode;
}
