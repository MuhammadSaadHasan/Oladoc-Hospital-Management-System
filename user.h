#pragma once
#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


#include "user.h"


class user
{
protected:
	char username[50];
	char CNIC[50];
	char ID[50];
	char password[50];
	char email[50];
	char idType;
public:
	user();
	string virtual RegisterUser(char);
	void virtual LoginUser(user);
	void displayalldata();
	

	char* getID();
	char* getPassword();
	char* getCNIC();
	char* getUserName();
	char* getEmail();

	void setID(string);
	void setPassword(string);
	void setCNIC(string);
	void setUserName(string);
	void setEmail(string);

	char getIDtype();
	void setIDtype(char);

};

int DoctorsPatientsCounter(char);


#endif