#pragma once
#ifndef VIDEOCONSULTATION_H
#define VIDEOCONSULTATION_H
#include "patients.h"
#include "doctors.h"
#include "appointments.h"




class videoconsultation: public appointments
{

private:


public:
	void book(appointments);


};

#endif





