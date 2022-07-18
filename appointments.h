#pragma once
#ifndef APPOINTMENTS_H
#define APPOINTMENTS_H


#include "DateAndTime.h"
#include "user.h"

class appointments
{

	private:
		DateAndTime DT;
		char AppDocName[50];
		char AppPatName[50];
		char AppPatID[50];
		char AppDocID[50];
		char CaseRegarding[50];
		char AppointmentMode;

	public:
		appointments();
		void virtual book(appointments);
		bool setDateAndTime(string,string);


		void SetAppDocName(string);
		void SetAppPatName(string);
		void SetAppPatID(string);
		void SetAppDocID(string);
		void SetCaseRegarding(string);
		void SetAppointmentMode(char);

		char* GetAppDocName();
		char* GetAppPatName();
		char* GetAppPatID();
		char* GetAppDocID();
		char* GetCaseRegarding();
		char GetAppointmentMode();


};





#endif



































//#pragma once
//#ifndef APPOINTMENTS_H
//#define APPOINTMENTS_H
//
//#include "DateAndTime.h"
//#include "patients.h"
//#include "doctors.h"
//
//
//class appointments
//{
//
//	protected:
//		DateAndTime DT;
//		char docID[50];
//		char patID[50];
//		char docFullName[50];
//		char patFullName[50];
//		char Case[50];
//		char AppointmentType;
//		char AppointmentMode;
//
//	public:
//		appointments();
//		void virtual book();
//
//		
//
//
//
//
//
//
//
//
//};
//
//
//
//
//
//
//
//
//#endif