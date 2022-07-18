#pragma once
#ifndef DOCTORS_H
#define DOCTORS_H
#include <fstream>

#include "user.h"
#include "appointments.h"
#include "videoconsultation.h"
#include "inperson.h"


string getbackstringtime();


class doctors :public user				//assumption each appointment is 15 min and no doctor works more than 12 hours
{
private:
	char Timings[50];

	char MonTimings[50];
	char TueTimings[50];
	char WedTimings[50];
	char ThurTimings[50];
	char FriTimings[50];
	char SatTimings[50];
	char SunTimings[50];

	char FullName[50];
	char location[50];
	char Hospital[50];
	char Experience[50];
	char docID[50];
	float Balance;
	float HourlyCharge;
	appointments* app;
public:
	doctors();
	void LoginUser(user);
	void displayapp();

	char* getHospital();
	char* getFullName();
	char* getExperience();
	char* getDocID();
	float getHourlyCharge();

	void setHourlyCharge(float);
	void setHospital(string);



	void setlocation(string);
	char* getlocation();

	char* GetMonTimings();
	char* GetTueTimings();
	char* GetWedTimings();
	char* GetThurTimings();
	char* GetFriTimings();
	char* GetSatTimings();
	char* GetSunTimings();






};

void writeCheck(string file_name, doctors obj);
void readCheck(string file_name);

#endif