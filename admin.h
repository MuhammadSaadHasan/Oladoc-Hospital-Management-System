#pragma once

#ifndef ADMIN_H
#define ADMIN_H


#include "appointments.h"
#include "user.h"

class admin:public user
{
private:
	

public:
	void LoginUser(user);


};



bool UpdateCNIC(string,string,string);
bool UpdateEmail(string,string,string);
bool UpdateID(string,string,string);
bool UpdatePassword(string,string,string);
bool UpdateUsername(string,string,string);





#endif