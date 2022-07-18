#include <windows.h>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

#include "doctors.h"
#include "oladoc.h"
#include "videoconsultation.h"
#include "inperson.h"


doctors::doctors()
{
	Balance = 0.0;
	HourlyCharge = 0.0;
	for (int i = 0; i < 50; i++)
	{
		location[i] = 'x';
		Hospital[i] = 'x';
		Timings[i] = 'x';
		Experience[i] = 'x';
		
	}
}

void doctors::LoginUser(user MainAccessObject)
{
		system("CLS");
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "****************************WELCOME TO ";SetConsoleTextAttribute(hConsole, 6);cout << "MAIN ";SetConsoleTextAttribute(hConsole, 1);cout << "PAGE";SetConsoleTextAttribute(hConsole, 15);cout << " ****************************" << endl << endl << endl;

	/*cout << "normal -- " << username << endl;
	cout << "MAB -- " << MainAccessObject.getPassword() << endl;
	cout << "MAB -- " << MainAccessObject.getID() << endl;
	cout << "MAB -- " << MainAccessObject.getEmail() << endl;
	cout << "MAB -- " << MainAccessObject.getCNIC() << endl;*/
	bool loggedin = true;

	while (loggedin == true)
	{


		bool empty = false;
		doctors obj;
		string check = MainAccessObject.getID();
		ifstream fin("DoctorsData.dat", ios::binary | ios::app);
		while (fin.read((char*)&obj, sizeof(obj)))
		{
			if (obj.docID == check)
			{
				empty = true;
			}
		}
		fin.close();




		if (empty == false)
		{
			string choice;
			cout << "\n\n    Your Registration is complete, however it seems like your Profile hasnt been filled" << endl;
			cout << "    Would you like to finish setting up your account? (Y/N)" << endl;
			cout << "    Input: ";
			cin >> choice;

			system("CLS");
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
				doctors obj;
				string str;


				string id = MainAccessObject.getID();

				strcpy_s(obj.docID, id.c_str());


				cout << "Enter your Full Name." << endl;
				cout << "\nInput: ";
				cin.ignore();
				getline(cin, str);
				strcpy_s(obj.FullName, str.c_str());


				cout << "Enter the name of the Hospital you work at" << endl;
				cout << "\nInput: ";
				getline(cin, str);
				strcpy_s(obj.Hospital, str.c_str());


				cout << "Enter the city the Hospital is located in" << endl;
				cin >> str;
				strcpy_s(obj.location, str.c_str());



				cout << "\nEnter Timings(if you dont work on this day please enter 'x') : " << endl;
				cout << "Monday: ";
				str = getbackstringtime();
				strcpy_s(obj.MonTimings, str.c_str());

				cout << "Tuesday" << endl;
				str = getbackstringtime();

				strcpy_s(obj.TueTimings, str.c_str());

				cout << "Wednesday: " << endl;
				str = getbackstringtime();
				strcpy_s(obj.WedTimings, str.c_str());

				cout << "Thursday: " << endl;
				str = getbackstringtime();
				strcpy_s(obj.ThurTimings, str.c_str());

				cout << "Friday: " << endl;
				str = getbackstringtime();
				strcpy_s(obj.FriTimings, str.c_str());

				cout << "Saturday :" << endl;
				str = getbackstringtime();
				strcpy_s(obj.SatTimings, str.c_str());

				cout << "Sunday: " << endl;
				str = getbackstringtime();
				strcpy_s(obj.SunTimings, str.c_str());



				cout << "How many years of experience do you have" << endl;
				cout << "\nInput: ";
				cin.ignore();
				getline(cin, str);
				strcpy_s(obj.Experience, str.c_str());

				float num;
				cout << "\nEnter how much you will charge for 1 appointment per hour" << endl;
				cout << "Input: ";
				cin >> num;
				obj.HourlyCharge = num;

				writeCheck("DoctorsData.dat", obj);

				readCheck("DoctorsData.dat");

				SetConsoleTextAttribute(hConsole, 2);
				cout << "\n\n     Profile has been successfully set up!" << endl << endl << endl;
				SetConsoleTextAttribute(hConsole, 15);


			}


		}


		system("CLS");
		string choice;
		cout << "\n\nChoose from the following: " << endl;
		cout << "1 - Edit Profile Details" << endl;
		cout << "2 - View Appointments" << endl;
		cout << "3 - Logout" << endl;
		cout << "Input: ";
		cin >> choice;
		while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5")
		{
			SetConsoleTextAttribute(hConsole, 4);
			cout << "*Please enter from the following list provided" << endl;
			SetConsoleTextAttribute(hConsole, 15);
			cout << "Input: ";
			cin >> choice;

		}
		if (choice == "1")
		{
			cout << "Press 1 to change Hourly Charge" << endl;
			cout << "Press 2 to change Password" << endl;
			cout << "Press 1 to change Hospital" << endl;
			cin >> choice;
			if (choice == "1")
			{
				cout << "What would you like to change it to: ";
				float updated_name;
				cin >> updated_name;
				doctors obj;
				fstream f("DoctorsData.dat", ios::out | ios::in | ios::binary);
				while (f.read((char*)&obj, sizeof(obj)))
				{
					if (obj.getID() == MainAccessObject.getID())
					{
						obj.setHourlyCharge(updated_name);
						int a = f.tellg();
						int s = sizeof(doctors);
						f.seekp(a - s, ios::beg);
						f.write((char*)&obj, sizeof(obj));
						break;
					}
				}
				f.close();
			}
			if (choice == "2")
			{
				cout << "What would you like to change it to: ";
				string updated_name;
				cin >> updated_name;
				user obj;
				fstream f("UserData.dat", ios::out | ios::in | ios::binary);
				while (f.read((char*)&obj, sizeof(obj)))
				{
					if (obj.getID() == MainAccessObject.getID())
					{
						obj.setPassword(updated_name);
						int a = f.tellg();
						int s = sizeof(user);
						f.seekp(a - s, ios::beg);
						f.write((char*)&obj, sizeof(obj));
						break;
					}
				}
				f.close();
			}
			if (choice == "3")
			{
				cout << "What would you like to change it to: ";
				string updated_name;
				cin >> updated_name;
				doctors obj;
				fstream f("DoctorsData.dat", ios::out | ios::in | ios::binary);
				while (f.read((char*)&obj, sizeof(obj)))
				{
					if (obj.getID() == MainAccessObject.getID())
					{
						obj.setHospital(updated_name);
						int a = f.tellg();
						int s = sizeof(doctors);
						f.seekp(a - s, ios::beg);
						f.write((char*)&obj, sizeof(obj));
						break;
					}
				}
				f.close();
			}
		}
		if (choice == "2")
		{

			//doctors obj;
			//ifstream fin(file_name, ios::binary | ios::app);
			//while (fin.read((char*)&obj, sizeof(obj)))
			//{
			//	obj.displayapp();
			//}
			//fin.close();
		}

		if (choice == "3")
		{
			loggedin = false;
		}




	}
	

}

void doctors::displayapp()
{
	cout << "Hospital == " << Hospital << endl;
	cout << "ID == " << docID << endl;
	cout << "Location == " << location << endl;
	cout << "Timings == " << Timings << endl;
	cout << "Experience == " << Experience << endl;
	cout << "Balance == " << Balance << endl;
	cout << "Hourlycharge == " << HourlyCharge << endl;

}
char* doctors::getHospital()
{
	return Hospital;
}
char* doctors::getFullName()
{
	return FullName;
}
char* doctors::getExperience()
{
	return Experience;
}
char* doctors::getDocID()
{
	return docID;
}
float doctors::getHourlyCharge()
{
	return HourlyCharge;
}
void doctors::setHourlyCharge(float x)
{
	HourlyCharge = x;
}
void doctors::setHospital(string str)
{
	strcpy_s(this->Hospital, str.c_str());
}
void doctors::setlocation(string str)
{
	strcpy_s(this->location, str.c_str());
}
char* doctors::getlocation()
{
	return location;
}
char* doctors::GetMonTimings()
{
	return MonTimings;
}
char* doctors::GetTueTimings()
{
	return TueTimings;
}
char* doctors::GetWedTimings()
{
	return WedTimings;
}
char* doctors::GetThurTimings()
{
	return ThurTimings;
}
char* doctors::GetFriTimings()
{
	return FriTimings;
}
char* doctors::GetSatTimings()
{
	return SatTimings;
}
char* doctors::GetSunTimings()
{
	return SunTimings;
}
string getbackstringtime()
{
	string str;
	string h;
	string m;
	string ampm;
	int size= 0;
	cout << "\nStart Time" << endl;
	cout << "Hour: ";
	cin >> h;
	size = 0;
	while (h[size] != '\0')
	{
		size++;
	}
	while (size != 2 || int(h[0])-48 > 1 || int(h[1])-48 > 5)
		/*|| h[5]!= 'p' || int(h[7]) - 48 > 1 || int(h[10]) - 48 > 5 || h[12] != 'a' || h[13] != 'm' || h[12] != 'p')*/
	{
		cout << "*Please Enter again following the format (03 - hour   40 - min)";
		cout << "Hour: ";
		cin >> h;
		size = 0;
		while (h[size] != '\0')
		{
			size++;
		}
	}
	size = 0;
	cout << "Min: ";
	cin >> m;
	while (m[size] != '\0')
	{
		size++;
	}
	while (size != 2 || int(m[0]) - 48 > 1 || (int(m[1]) - 48 > 2 && int(m[1]) - 48 == 1))
	{
		cout << "*Please Enter again following the format (03 - hour   40 - min)";
		cout << "Min: ";
		cin >> m;
		size = 0;
		while (m[size] != '\0')
		{
			size++;
		}
	}
	


	cout << "am or pm :";
	cin >> ampm;
	str = h + ":" + m + ampm;

	cout << "\n\n\nEnd Time: " << endl;
	cout << "Hour: ";
	cin >> h;
	while (h[size] != '\0')
	{
		size++;
	}
	while (size != 2 || int(h[0]) - 48 > 1 || (int(m[1]) - 48 > 2 && int(m[1]) - 48 == 1))
	{
		cout << "*Please Enter again following the format (03 - hour   40 - min)";
		cout << "Hour: ";
		cin >> h;
		size = 0;
		while (h[size] != '\0')
		{
			size++;
		}
	}
	size = 0;
	cout << "Min: ";
	cin >> m;
	while (m[size] != '\0')
	{
		size++;
	}
	while (size != 2 || int(m[0]) - 48 > 1)
	{
		cout << "*Please Enter again following the format (03 - hour   40 - min)";
		cout << "Min: ";
		cin >> m;
		size = 0;
		while (m[size] != '\0')
		{
			size++;
		}
	}
	str = str + h + ":" + m + ampm;

	cout << str << endl;

	return str;
}
void writeCheck(string file_name, doctors obj)
{
	ofstream fout(file_name, ios::binary | ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();


}
void readCheck(string file_name)
{
	doctors obj;
	ifstream fin(file_name, ios::binary | ios::app);
	while (fin.read((char*)&obj, sizeof(obj)))
	{
		obj.displayapp();
	}
	fin.close();
}
