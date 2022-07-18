#include <windows.h>
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;

#include "patients.h"
#include "doctors.h"
#include "videoconsultation.h"
#include "inperson.h"

patients::patients()
{
	
	
	for (int i = 0; i < 50; i++)
	{
		gender[i] = '\0';
		allergeies[i] = '\0';
		height[i] = '\0';
		weight[i] = '\0';
		age[i] = '\0';

	}

}

void patients::LoginUser(user MainAccessObject)
{

	system("CLS");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "****************************WELCOME TO ";SetConsoleTextAttribute(hConsole, 6);cout << "MAIN ";SetConsoleTextAttribute(hConsole, 1);cout << "PAGE";SetConsoleTextAttribute(hConsole, 15);cout << " ****************************" << endl << endl << endl;

	bool loggedin = true;
	bool empty = true;
	while (loggedin == true)
	{


		temp.SetAppPatID(MainAccessObject.getID());
		patients obj;
		string check = MainAccessObject.getID();
		ifstream fin("PatientsData.dat", ios::binary | ios::app);
		while (fin.read((char*)&obj, sizeof(obj)))
		{
			if (obj.patID == check)
			{
				empty = false;
			}
		}
		//pat id and stuff isnt being stored
		fin.close();


		if (empty == true)

		{
			system("CLS");
			string choice;
			cout << "\n\nYour Registration is complete, however it seem your Profile hasnt been filled" << endl;
			cout << "Would you like to finish setting up your account? (Y/N)" << endl;
			cout << "Input: ";
			cin >> choice;

			while (choice != "y" && choice != "yes" && choice != "YES" && choice != "Yes" && choice != "Y" && choice != "n" && choice != "no" && choice != "NO" && choice != "No" && choice != "N")
			{
				SetConsoleTextAttribute(hConsole, 4);
				cout << "*Please enter Yes or No" << endl;
				SetConsoleTextAttribute(hConsole, 15);
				cout << "Input: ";
				cin >> choice;
			}

			if (choice == "y" || choice == "yes" || choice == "YES" || choice == "Yes" || choice == "Y")
			{
				patients obj;
				string s = MainAccessObject.getID();
				strcpy_s(obj.patID, s.c_str());


				string str;
				string id = MainAccessObject.getID();
				strcpy_s(obj.patID, id.c_str());
				cout << "ID == " << obj.patID << endl;


				temp.SetAppPatID(id);

				cout << "Enter you Full Name -- This name will be available to doctors" << endl;
				cout << "Input: ";
				cin.ignore();
				getline(cin, str);

				strcpy_s(obj.FullName, str.c_str());

				temp.SetAppPatName(str);

				cout << "***********************************FullName == " << obj.FullName << endl;




				cout << "Enter your Gender (M/F/Other): ";
				cin >> str;
				while (str != "M" && str != "F" && str != "Other" && str != "m" && str != "other" && str != "o")
				{
					SetConsoleTextAttribute(hConsole, 4);
					cout << "*Please enter only from the following options" << endl;
					cout << "Input: ";
					cin >> str;
					SetConsoleTextAttribute(hConsole, 15);

				}


				strcpy_s(obj.gender, str.c_str());



				cout << "Gender == " << obj.gender << endl;


				cout << "Enter your Age: ";
				cin >> str;

				strcpy_s(obj.age, str.c_str());

				int f;
				float i;
				cout << "Enter your Height" << endl;
				cout << "Feet: ";
				cin >> f;
				cout << "Inches: ";
				cin >> i;
				while (i < 0 || i > 12)
				{
					cout << "Please enter a valid height (inches can be from 0-11): ";
					cin >> i;
				}
				string in = to_string(i);
				str = to_string(f) + " feet and " + in[0] + in[1] + in[2] + " inches.";
				strcpy_s(obj.height, str.c_str());

				cout << "Height == " << obj.height << endl;

				int ch;
				cout << "Enter your Weight" << endl;
				cout << "Would you like to enter in lbs or kg";
				cout << "1 - lbs" << endl;
				cout << "2 - kg" << endl;
				cout << "Input: ";
				cin >> ch;
				if (ch == 1)
				{
					cout << "Please enter your weight in lbs: ";
					cin >> str;
					str = str + " lbs";
				}
				if (ch == 2)
				{
					cout << "Please enter your weight in kg: ";
					cin >> str;
					str = str + " kg";
				}
				strcpy_s(obj.weight, str.c_str());
				cout << obj.weight << endl;

				cout << "Write about the allergies you may have: ";
				cin.ignore();
				getline(cin, str);
				strcpy_s(obj.allergeies, str.c_str());

				cout << "Allegries === " << obj.allergeies << endl;


				SetConsoleTextAttribute(hConsole, 2);
				cout << "\n\n    Profile has been successfully set up!" << endl << endl << endl;
				SetConsoleTextAttribute(hConsole, 15);

				writePatientsData("PatientsData.dat", obj);

				//readPatientsData("PatientsData.dat");
				empty = false;
			}

		}
		if (empty == false)
		{
			cout << "**********" << endl;
			cout << temp.GetAppDocID() << endl;
			cout << temp.GetAppDocName() << endl;
			cout << temp.GetAppointmentMode() << endl;
			cout << temp.GetAppPatID() << endl;
			cout << temp.GetAppPatName() << endl;
			system("CLS");
			string choice;
			cout << "\n\nChoose from the following: " << endl;
			cout << "1 - Book an Appointment" << endl;
			cout << "2 - Cancel an Appointment" << endl;
			cout << "3 - Edit Profile Details" << endl;
			cout << "4 - View Appointments" << endl;
			cout << "5 - View Profile" << endl;
			cout << "6 - Logout" << endl;
			cout << "Input: ";
			cin >> choice;

			while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6")
			{
				SetConsoleTextAttribute(hConsole, 4);
				cout << "*Please enter from the following list provided" << endl;
				SetConsoleTextAttribute(hConsole, 15);
				cout << "Input: ";
				cin >> choice;
			}


			if (choice == "1")
			{
				system("CLS");
				string c;
				cout << "\n\nChoose from the following: " << endl;
				cout << "1 - Search by Hospitals" << endl;
				cout << "2 - Search by doctors" << endl;
				cout << "3 - Search by Specilization" << endl;
				cout << "4 - Search by location" << endl;
				cout << "Input: ";
				cin >> c;

				if (c == "1")
				{
					doctors obj;
					SetConsoleTextAttribute(hConsole, 3);
					cout << endl << "\n\n**List of Hospitals**\n\n" << endl;
					SetConsoleTextAttribute(hConsole, 15);
					ifstream r("DoctorsData.dat", ios::binary | ios::app);
					while (r.read((char*)&obj, sizeof(obj)))
					{
						cout << "  " << obj.getHospital() << endl;
					}
					r.close();

					string str;
					string spec;
					cout << "\n\nChoose from the above Hospitals" << endl;
					cout << "\n\nEnter the Name of the Hospital: " << endl;
					cin.ignore();
					getline(cin, str);

					SetConsoleTextAttribute(hConsole, 3);
					cout << endl << "\n\n**Doctors Available in the Hospital**\n\n" << endl;
					SetConsoleTextAttribute(hConsole, 15);
					ifstream out("DoctorsData.dat", ios::binary | ios::app);
					string check;
					while (out.read((char*)&obj, sizeof(obj)))
					{
						check = obj.getHospital();
						if (str == check)
						{
							cout << "  " << obj.getDocID() << endl;
							cout << "  " << obj.getHourlyCharge() << endl;
						}
					}
					out.close();


					cout << "\n\nWhich doctor would you like to book you Appointment with." << endl;
					cout << "Please Enter the doctors ID:  ";
					cin >> str;

					ifstream R("DoctorsData.dat", ios::binary | ios::app);
					while (R.read((char*)&obj, sizeof(obj)))
					{
						check = obj.getDocID();
						if (str == check)
						{
							temp.SetAppDocID(obj.doctors::getDocID());
							temp.SetAppDocName(obj.doctors::getFullName());
						}
					}
					R.close();

					patients obj2;
					ifstream rd("PatientsData.dat", ios::binary | ios::app);
					while (rd.read((char*)&obj2, sizeof(obj2)))
					{
						check = obj2.getpatID();
						if (MainAccessObject.getID() == check)
						{
							temp.SetAppPatID(obj2.getpatID());
							temp.SetAppPatName(obj2.getFullName());

						}
					}
					rd.close();

					string a;
					cout << "\n\n\nVideo Consultation or In-Person" << endl;
					cout << "What kind of apppointment do you want to book: ";
					cin >> a;


					if (a == "v")
					{
						app = new videoconsultation();
						app->book(temp);
						app = new appointments();
						

					}
					else
					{
						app = new inperson();
						app->book(temp);
					}

				}
				if (c == "2")
				{
					system("CLS");
					doctors obj;
					SetConsoleTextAttribute(hConsole, 3);
					cout << endl << "\n\n**List of Doctors**\n\n" << endl;
					SetConsoleTextAttribute(hConsole, 15);
					int count = 1;
					ifstream r("DoctorsData.dat", ios::binary | ios::app);
					while (r.read((char*)&obj, sizeof(obj)))
					{
						cout << count << " -- " << obj.getFullName() << " -- " << obj.getDocID() << endl;
						count++;
					}
					r.close();

					string str;
					cout << "Choose one of the following doctors" << endl;
					cout << "\n\nEnter the ID of rhe doctor you want to choose" << endl;
					cout << "Input: ";
					cin >> str;

					//doctors obj;
					ifstream fin("DoctorsData.dat", ios::binary | ios::app);
					while (fin.read((char*)&obj, sizeof(obj)))
					{
						if (obj.getDocID() == str)
						{
							cout << "\n\n\\nDetails" << endl;
							cout << obj.getDocID() << endl;
							cout << obj.getExperience() << endl;
							cout << obj.getHourlyCharge() << endl;

						}
					}
					fin.close();
				}
				if (c == "4")
				{








				}

				if (c == "4")
				{
					doctors obj;
					SetConsoleTextAttribute(hConsole, 3);
					cout << endl << "\n\n**LOCATIONS**\n\n" << endl;
					SetConsoleTextAttribute(hConsole, 15);
					int count = 1;
					ifstream r("DoctorsData.dat", ios::binary | ios::app);
					while (r.read((char*)&obj, sizeof(obj)))
					{
						cout << count << " -- " << obj.getlocation() << endl;
						count++;
					}
					r.close();

					string str;
					cout << "Choose from one of the follwing locations" << endl;
					cout << "\n\nEnter the location you want to choose" << endl;
					cout << "Input: ";
					cin >> str;

					//doctors obj;
					ifstream fin("DoctorsData.dat", ios::binary | ios::app);
					while (fin.read((char*)&obj, sizeof(obj)))
					{
						if (obj.getDocID() == str)
						{
							cout << "\n\n\\nDetails" << endl;
							cout << obj.getHospital() << endl;
							cout << obj.getDocID() << endl;
							cout << obj.getExperience() << endl;
							cout << obj.getHourlyCharge() << endl << endl << endl;

						}
					}
					fin.close();

				}
				if (c == "4")
				{

				}


			}



			if (choice == "3")
			{
				system("CLS");
				cout << "\n\nChoose from the following: " << endl;
				cout << "1 - Update Name" << endl;
				cout << "2 - Update Gender" << endl;
				cout << "3 - Update Height" << endl;
				cout << "4 - Update Weight" << endl;
				cout << "5 - Update Allergies" << endl;
				cout << "Input: ";
				cin >> choice;
				if (choice == "1")
				{
				}
				if (choice == "2")
				{
					string str;
					cout << "What would you like to change it to" << endl;
					cout << "Input: ";
					cin >> str;
					UpdateGender((*this).ID, str, "PatientsData.dat");
				}
				if (choice == "3")
				{
					string num;
					cout << "What would you like to change it to" << endl;
					cout << "Input: ";
					cin >> num;
					UpdateHeight((*this).ID, num, "PatientsData.dat");
				}
				if (choice == "4")
				{
					string num;
					cout << "What would you like to change it to" << endl;
					cout << "Input: ";
					cin >> num;
					UpdateWeight((*this).ID, num, "PatientsData.dat");
				}
				if (choice == "5")
				{
					string str;
					cout << "What would you like to change it to" << endl;
					cout << "Input: ";
					cin >> str;
					UpdateAllergies((*this).ID, str, "PatientsData.dat");
				}
			}
			if (choice == "5")
			{
				readPatientsData("PatientsData.dat");
			}
			if (choice == "6")
			{
				loggedin = false;
			}


		}
	}
}

void patients::setGender(string str)
{
	strcpy_s(this->gender, str.c_str());
}
void patients::setAllergies(string str)
{
	strcpy_s(this->allergeies, str.c_str());
}
void patients::setHeight(string str)
{
	strcpy_s(this->height, str.c_str());
}
void patients::setWeight(string str)
{
	strcpy_s(this->weight, str.c_str());
}
char* patients::getpatID()
{
	return patID;
}
char* patients::getFullName()
{
	return FullName;
}
char* patients::getGender()
{
	return gender;
}
char* patients::getAllergies()
{
	return allergeies;
}
char* patients::getHeight()
{
	return height;
}
char* patients::getWeight()
{
	return weight;
}
char* patients::getAge()
{
	return age;
}
void patients::displayPatientsDetails()
{
	cout << "Gender == " << gender << endl;
	cout << "Allergies == " << allergeies<< endl;
	cout << "Height == " << height << endl;
	cout << "Weight == " << weight << endl;
	cout << "Age == " << age<< endl;

}

void writePatientsData(string file_name, patients obj)
{
	ofstream fout(file_name, ios::binary | ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();


}
void readPatientsData(string file_name)
{
	patients obj;
	ifstream fin(file_name, ios::binary | ios::app);
	while (fin.read((char*)&obj, sizeof(obj)))
	{
		obj.displayPatientsDetails();
	}
	fin.close();


}

void UpdateGender(string id, string updated_name, string file_name)
{
	patients obj;
	fstream f(file_name, ios::out | ios::in | ios::binary);
	while (f.read((char*)&obj, sizeof(obj)))
	{
		if (obj.getpatID() == id)
		{
			obj.setGender(updated_name);
			int a = f.tellg();
			int s = sizeof(patients);
			f.seekp(a - s, ios::beg);
			f.write((char*)&obj, sizeof(obj));
			break;
		}
	}
	f.close();
}
void UpdateAllergies(string id, string updated_name, string file_name)
{
	patients obj;
	fstream f(file_name, ios::out | ios::in | ios::binary);
	while (f.read((char*)&obj, sizeof(obj)))
	{
		if (obj.getpatID() == id)
		{
			obj.setAllergies(updated_name);
			int a = f.tellg();
			int s = sizeof(patients);
			f.seekp(a - s, ios::beg);
			f.write((char*)&obj, sizeof(obj));
			break;
		}
	}
	f.close();
}
void UpdateHeight(string id, string num, string file_name)
{

	patients obj;
	fstream f(file_name, ios::out | ios::in | ios::binary);
	while (f.read((char*)&obj, sizeof(obj)))
	{
		if (obj.getpatID() == id)
		{
			obj.setHeight(num);
			int a = f.tellg();
			int s = sizeof(patients);
			f.seekp(a - s, ios::beg);
			f.write((char*)&obj, sizeof(obj));
			break;
		}
	}
	f.close();


}
void UpdateWeight(string id, string num, string file_name)
{

	patients obj;
	fstream f(file_name, ios::out | ios::in | ios::binary);
	while (f.read((char*)&obj, sizeof(obj)))
	{
		if (obj.getpatID() == id)
		{
			obj.setWeight(num);
			int a = f.tellg();
			int s = sizeof(patients);
			f.seekp(a - s, ios::beg);
			f.write((char*)&obj, sizeof(obj));
			break;
		}
	}
	f.close();


}


