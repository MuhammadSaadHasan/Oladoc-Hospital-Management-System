#pragma once
#ifndef OLADOC_H
#define OLADOC_H
#include <iostream>
#include <cstring>
#include <string>
#include "user.h"
#include "doctors.h"
#include "patients.h"




class oladoc
{
private:
	user* u;	
	user MainAccessObject;
public:
	oladoc();
	string Register();
	void login(string);
	
};

void writeUserData(string file_name, user obj);
void readUserData(string file_name);
bool SearchForPassword(string);
bool SearchForEmail(string);
bool SearchForUserName(string);
bool SearchForCNIC(string,char);
#endif