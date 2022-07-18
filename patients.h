#pragma once
#ifndef PATIENTS_H
#define PATIENTS_H
#include "user.h"
#include "appointments.h"


class patients :public user
{
private:
	char FullName[50];
	char gender[50];
	char allergeies[50];
	char patID[50];
	char height[50];
	char weight[50];
	char age[50];
	appointments* app;
	appointments temp;
public:
	patients();
	void LoginUser(user);
	void setGender(string);
	void setAllergies(string);
	void setHeight(string);
	void setWeight(string);
	char* getpatID();
	char* getFullName();
	char* getGender();
	char* getAllergies();
	char* getHeight();
	char* getWeight();
	char* getAge();




	void displayPatientsDetails();



};

void UpdateGender(string, string, string);
void UpdateAllergies(string, string, string);
void UpdateHeight(string, string, string);
void UpdateWeight(string, string, string);
void writePatientsData(string, patients);
void readPatientsData(string);

#endif