#pragma once
#ifndef INPERSON_H
#define INPERSON_H
#include "patients.h"
#include "doctors.h"
#include "appointments.h"


class inperson: public appointments
{

private:


public:
	void book(appointments);


};


#endif




























//#pragma once
//#ifndef INPERSON_H
//#define INPERSON_H
//
//
//#include <fstream>
//#include "appointments.h"
//#include "videoconsultation.h"
//#include "inperson.h"
//
//class inperson :public appointments
//{
//
//	private:
//
//
//	public:
//		void book();
//
//
//
//};
//
//#endif
