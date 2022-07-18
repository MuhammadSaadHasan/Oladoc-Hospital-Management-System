#include "oladoc.h"
#include "doctors.h"
#include "admin.h"
#include <windows.h>
#include <fstream>

oladoc::oladoc()
{
	u = new user();
}
string oladoc::Register()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	string choice;
	cout << "\nAre you Registering as a Doctor or Patient or Admin" << endl;
	cout << "Input: ";
	cin >> choice;
	while (choice != "d" && choice != "D" && choice != "doctor" && choice != "Doctor" && choice != "p" && choice != "P" && choice != "patient" && choice != "Patient" && choice == "a" && choice == "A" && choice == "admin" && choice == "Admin")
	{
		SetConsoleTextAttribute(hConsole, 4);
		cout << "\n*Please enter only from the options provided" << endl;
		SetConsoleTextAttribute(hConsole, 15);
		cout << "Input: ";
		cin >> choice;
	}
	
	if (choice == "d" || choice == "D" || choice == "doctor" || choice == "Doctor")
	{
		u = new doctors();
		choice = u->RegisterUser('D');
		MainAccessObject.setCNIC(u->getCNIC());
		MainAccessObject.setUserName(u->getUserName());
		MainAccessObject.setPassword(u->getPassword());
		MainAccessObject.setEmail(u->getEmail());
		MainAccessObject.setID(u->getID());
		MainAccessObject.setIDtype(u->getIDtype());
		
		SetConsoleTextAttribute(hConsole, 6);
		cout << "\n\n You have Automatically logged onto Oladoc" << endl;
		SetConsoleTextAttribute(hConsole, 15);

		u->LoginUser(MainAccessObject);
	}
	if (choice == "p" || choice == "P" || choice == "patient" || choice == "Patient")
	{
		u = new patients();
		choice = u->RegisterUser('P');
		MainAccessObject.setCNIC(u->getCNIC());
		MainAccessObject.setUserName(u->getUserName());
		MainAccessObject.setPassword(u->getPassword());
		MainAccessObject.setEmail(u->getEmail());
		MainAccessObject.setID(u->getID());
		MainAccessObject.setIDtype(u->getIDtype());
		SetConsoleTextAttribute(hConsole, 6);
		cout << "\n\n Automatically logged on to Oladoc" << endl;
		SetConsoleTextAttribute(hConsole, 15);
		u->LoginUser(MainAccessObject);
	}
	if (choice == "a" || choice == "A" || choice == "admin" || choice == "Admin")
	{
		u = new admin();
		choice = u->RegisterUser('A');
		MainAccessObject.setCNIC(u->getCNIC());
		MainAccessObject.setUserName(u->getUserName());
		MainAccessObject.setPassword(u->getPassword());
		MainAccessObject.setEmail(u->getEmail());
		MainAccessObject.setID(u->getID());
		MainAccessObject.setIDtype(u->getIDtype());
		SetConsoleTextAttribute(hConsole, 6);
		cout << "\n\nAutomatically logged in" << endl;
		SetConsoleTextAttribute(hConsole, 15);
		u->LoginUser(MainAccessObject);
	}

	return choice;


}

void oladoc::login(string id)
{

	if (id[0] == 'D')
	{
		user obj;
		ifstream fin("UserData.dat", ios::binary | ios::app);
		while (fin.read((char*)&obj, sizeof(obj)))
		{
			if (obj.getID() == id)
			{
				MainAccessObject.setCNIC(obj.getCNIC());
				MainAccessObject.setUserName(obj.getUserName());
				MainAccessObject.setPassword(obj.getPassword());
				MainAccessObject.setEmail(obj.getEmail());
				MainAccessObject.setID(obj.getID());
			}

		}
		fin.close();
		u = new doctors();
		u->LoginUser(MainAccessObject);
	}
	if (id[0] == 'P')
	{
		user obj;
		ifstream fin("UserData.dat", ios::binary | ios::app);
		while (fin.read((char*)&obj, sizeof(obj)))
		{
			if (obj.getID() == id)
			{
				MainAccessObject.setCNIC(obj.getCNIC());
				MainAccessObject.setUserName(obj.getUserName());
				MainAccessObject.setID(obj.getID());
				MainAccessObject.setPassword(obj.getPassword());
				MainAccessObject.setEmail(obj.getEmail());
				MainAccessObject.setID(id);
			}

		}
		fin.close();
		u = new patients();
		u->LoginUser(MainAccessObject);

	}
	if (id[0] == 'A')
	{
		u = new admin();
		u->LoginUser(MainAccessObject);
	}


}


bool SearchForPassword(string str)
{
	user obj;
	ifstream fin("UserData.dat", ios::binary | ios::app);
	while (fin.read((char*)&obj, sizeof(obj)))
	{
		if (obj.getPassword() == str)
		{
			fin.close();
			return true;
		}
	}
	return false;
}
bool SearchForEmail(string str)
{
	user obj;
	ifstream fin("UserData.dat", ios::binary | ios::app);
	while (fin.read((char*)&obj, sizeof(obj)))
	{
		if (obj.getEmail() == str)
		{
			fin.close();
			return true;
		}
	}
	return false;
}
bool SearchForUserName(string str)
{
	user obj;
	ifstream fin("UserData.dat", ios::binary | ios::app);
	while (fin.read((char*)&obj, sizeof(obj)))
	{
		if (obj.getUserName() == str)
		{
			fin.close();
			return true;
		}
	}
	fin.close();
	return false;
}
bool SearchForCNIC(string str, char type)
{
	user obj;
	ifstream fin("UserData.dat", ios::binary | ios::app);
	while (fin.read((char*)&obj, sizeof(obj)))
	{
		if (obj.getCNIC() == str && obj.getIDtype() == type)
		{
			fin.close();
			return true;
		}
	}
	return false;
}
void writeUserData(string file_name, user obj)
{
	ofstream fout(file_name, ios::binary | ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();

}
void readUserData(string file_name)
{
	user obj;
	ifstream fin(file_name, ios::binary | ios::app);
	while (fin.read((char*)&obj, sizeof(obj)))
	{
		obj.user::displayalldata();
	}
	fin.close();
}



