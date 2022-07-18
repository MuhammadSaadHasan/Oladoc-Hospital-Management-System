#include <windows.h>
#include <fstream>
#include "admin.h"
#include "patients.h"
#include "doctors.h"
#include "user.h"

void admin::LoginUser(user MainObjectAccess)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "****************************";SetConsoleTextAttribute(hConsole, 6);cout << "ADMIN ";SetConsoleTextAttribute(hConsole, 1);cout << "PORTAL";SetConsoleTextAttribute(hConsole, 15);cout << " ****************************" << endl << endl << endl;

	bool loggedin = true;
	while (loggedin == true)
	{
		string choice;
		string c;
		cout << "What would you like to do?" << endl;
		cout << "Press 1 for Patients Data" << endl;
		cout << "Press 2 for Doctors Data" << endl;
		cout << "Press 3 to Logout" << endl;
		cin >> c;


		if (c == "1")
		{

			cout << "Press 1 to view all Patients Data" << endl;
			cout << "Press 2 to Search for a patient" << endl;
			cout << "Press 3 to Edit patients Data" << endl;
			cin >> choice;

			if (choice == "1")
			{
				user obj;
				ifstream fin("UserData.dat", ios::binary | ios::app);
				while (fin.read((char*)&obj, sizeof(obj)))
				{
					cout << "\n\n\nCNIC: " << obj.getCNIC() << endl;
					cout << "Email: " << obj.getEmail() << endl;
					cout << "ID: " << obj.getID() << endl;
					cout << "Password: " << obj.getPassword() << endl;
					cout << "Username: " << obj.getUserName() << endl;
					patients obj1;
					ifstream f("PatientsData.dat", ios::binary | ios::app);
					while (f.read((char*)&obj1, sizeof(obj1)))
					{
						if (obj1.getpatID() == obj.getID())
						{
							cout << "Age: " << obj1.getAge() << endl;
							cout << "Allergies: " << obj1.getAllergies() << endl;
							cout << "Gender: " << obj1.getGender() << endl;
							cout << "Height: " << obj1.getHeight() << endl;
							cout << "Weight: " << obj1.getWeight() << endl;
						}

					}
					f.close();
				}
				fin.close();
			}
			if (choice == "2")
			{
				bool check = false;
				string str;
				cout << "Enter the ID of the patient you are looking for: ";
				cin >> str;
				user obj;
				ifstream fin("UserData.dat", ios::binary | ios::app);
				while (fin.read((char*)&obj, sizeof(obj)))
				{
					if (obj.getID() == str)
					{
						check = true;

						cout << "\n\n\nCNIC: " << obj.getCNIC() << endl;
						cout << "Email: " << obj.getEmail() << endl;
						cout << "ID: " << obj.getID() << endl;
						cout << "Password: " << obj.getPassword() << endl;
						cout << "Username: " << obj.getUserName() << endl;
						patients obj1;
						ifstream f("PatientsData.dat", ios::binary | ios::app);
						while (f.read((char*)&obj1, sizeof(obj1)))
						{
							if (obj1.getpatID() == str)
							{
								cout << "Age: " << obj1.getAge() << endl;
								cout << "Allergies: " << obj1.getAllergies() << endl;
								cout << "Gender: " << obj1.getGender() << endl;
								cout << "Height: " << obj1.getHeight() << endl;
								cout << "Weight: " << obj1.getWeight() << endl;
							}

						}
						f.close();
					}
				}
				fin.close();
				if (check == false)
				{
					cout << "User was not found!" << endl;
				}
			}
			if (choice == "3")
			{
				system("CLS");
				bool check = false;
				string str;
				cout << "Enter the ID of the patient whose data you want to change: ";
				cin >> str;
				
				cout << "Enter what you want to edit" << endl;
				cout << "Press 0 -- Edit CNIC" << endl;
				cout << "Press 1 -- Edit Email" << endl;
				cout << "Press 2 -- Edit ID" << endl;
				cout << "Press 3 -- Edit Password" << endl;
				cout << "Press 4 -- Edit Username" << endl;
				cout << "Press 5 -- Edit Age" << endl;
				cout << "Press 6 -- Edit Allergies" << endl;
				cout << "Press 7 -- Edit Gender" << endl;
				cout << "Press 8 -- Edit Height" << endl;
				cout << "Press 9 -- Edit Weight" << endl;
				cin >> choice; 
				if (choice == "0")
				{
					string updated;
					cout << "What would you like to change it to: ";
					cin >> updated;
					check = UpdateCNIC(str, updated, "UserData.dat");
				}
				if (choice == "1")
				{
					string updated;
					cout << "What would you like to change it to: ";
					cin >> updated;
					check = UpdateEmail(str, updated, "UserData.dat");
				}
				if (choice == "2")
				{
					string updated;
					cout << "What would you like to change it to: ";
					cin >> updated;
					check = UpdateID(str, updated, "UserData.dat");
				}
				if (choice == "3")
				{
					string updated;
					cout << "What would you like to change it to: ";
					cin >> updated;
					check = UpdatePassword(str, updated, "UserData.dat");
				}
				if (choice == "4")
				{
					string updated;
					cout << "What would you like to change it to: ";
					cin >> updated;
					check = UpdateUsername(str, updated, "UserData.dat");
				}
				if (choice == "7")
				{
					string updated;
					cout << "What would you like to change it to: ";
					cin >> updated;
					UpdateGender(str, updated, "PatientsData.dat");
				}
				if (choice == "8")
				{
					string updated;
					cout << "What would you like to change it to: ";
					cin >> updated;
					UpdateHeight(str, updated, "PatientsData.dat");
				}
				if (choice == "9")
				{
					string updated;
					cout << "What would you like to change it to: ";
					cin >> updated;
					UpdateWeight(str, updated, "PatientsData.dat");
				}
				if (choice == "6")
				{
					string updated;
					cout << "What would you like to change it to: ";
					cin >> updated;
					UpdateAllergies(str, updated, "PatientsData.dat");
				}

				if (check == false)
				{
					SetConsoleTextAttribute(hConsole, 4);
					cout << "User was not found!" << endl;
					SetConsoleTextAttribute(hConsole, 15);
				}
			}
			
		}
		if (c == "2")
		{
			system("CLS");
			cout << "Press 1 to view all Doctors Data" << endl;
			cout << "Press 2 to Search for a Doctors" << endl;
			cout << "Press 3 to Edit Doctors Data" << endl;
			cin >> choice;

			if (choice == "1")
			{
				user obj;
				ifstream fin("UserData.dat", ios::binary | ios::app);
				while (fin.read((char*)&obj, sizeof(obj)))
				{
					cout << "\n\n\nCNIC: " << obj.getCNIC() << endl;
					cout << "Email: " << obj.getEmail() << endl;
					cout << "ID: " << obj.getID() << endl;
					cout << "Password: " << obj.getPassword() << endl;
					cout << "Username: " << obj.getUserName() << endl;
					doctors obj1;
					ifstream f("DoctorsData.dat", ios::binary | ios::app);
					while (f.read((char*)&obj1, sizeof(obj1)))
					{
						if (obj1.getDocID() == obj.getID())
						{
							//cout << "Age: " << obj1. << endl;
							//cout << "Allergies: " << obj1.getAllergies() << endl;
							//cout << "Gender: " << obj1.getGender() << endl;
							//cout << "Height: " << obj1.getHeight() << endl;
							//cout << "Weight: " << obj1.getWeight() << endl;
						}

					}
					f.close();
				}
				fin.close();
			}
			if (choice == "2")
			{
				bool check = false;
				string str;
				cout << "Enter the ID of the patient you are looking for: ";
				cin >> str;
				user obj;
				ifstream fin("UserData.dat", ios::binary | ios::app);
				while (fin.read((char*)&obj, sizeof(obj)))
				{
					if (obj.getID() == str)
					{
						check = true;

						cout << "\n\n\nCNIC: " << obj.getCNIC() << endl;
						cout << "Email: " << obj.getEmail() << endl;
						cout << "ID: " << obj.getID() << endl;
						cout << "Password: " << obj.getPassword() << endl;
						cout << "Username: " << obj.getUserName() << endl;
						doctors obj1;
						ifstream f("PatientsData.dat", ios::binary | ios::app);
						while (f.read((char*)&obj1, sizeof(obj1)))
						{
							if (obj1.getDocID() == str)
							{					
								cout << "Locatio: " << obj1.getlocation() << endl;
								cout << "Hospital: " << obj1.getHospital() << endl;
								cout << "Experience: " << obj1.getExperience() << endl;
								cout << "Hourly Charge: " << obj1.getHourlyCharge() << endl;
							}

						}
						f.close();
				
					}
				}
				fin.close();
				if (check == false)
				{

					cout << "User was not found!" << endl;
				}
			}
			if (choice == "3")
			{
				system("CLS");
				bool check = false;
				string str;
				cout << "Enter the ID of the docotor whose data you want to change: ";
				cin >> str;

				cout << "Enter what you want to edit" << endl;
				cout << "Press 0 -- Edit CNIC" << endl;
				cout << "Press 1 -- Edit Email" << endl;					
				cout << "Press 2 -- Edit ID" << endl;						
				cout << "Press 3 -- Edit Password" << endl;					
				cout << "Press 4 -- Edit Username" << endl;					
				cout << "Press 5 -- Edit location" << endl;					
				cout << "Press 6 -- Edit Hospital" << endl;					
				cout << "Press 7 -- Edit Experience" << endl;				
				cout << "Press 8 -- Edit Balance" << endl;
				cout << "Press 9 -- Edit Hourly" << endl;
				cin >> choice;
				if (choice == "0")
				{
					string updated;
					cout << "What would you like to change it to: ";
					cin >> updated;
					check = UpdateCNIC(str, updated, "UserData.dat");
				}
				if (choice == "1")
				{
					string updated;
					cout << "What would you like to change it to: ";
					cin >> updated;
					check = UpdateEmail(str, updated, "UserData.dat");
				}
				if (choice == "2")
				{
					string updated;
					cout << "What would you like to change it to: ";
					cin >> updated;
					check = UpdateID(str, updated, "UserData.dat");
				}
				if (choice == "3")
				{
					string updated;
					cout << "What would you like to change it to: ";
					cin >> updated;
					check = UpdatePassword(str, updated, "UserData.dat");
				}
				if (choice == "4")
				{
					string updated;
					cout << "What would you like to change it to: ";
					cin >> updated;
					check = UpdateUsername(str, updated, "UserData.dat");
				}
				if (choice == "7")
				{
					string updated;
					cout << "What would you like to change it to: ";
					cin >> updated;
					UpdateGender(str, updated, "PatientsData.dat");
				}
				if (choice == "8")
				{
					string updated;
					cout << "What would you like to change it to: ";
					cin >> updated;
					UpdateHeight(str, updated, "PatientsData.dat");
				}
				if (choice == "9")
				{
					string updated;
					cout << "What would you like to change it to: ";
					cin >> updated;
					UpdateWeight(str, updated, "PatientsData.dat");
				}
				if (choice == "6")
				{
					string updated;
					cout << "What would you like to change it to: ";
					cin >> updated;
					UpdateAllergies(str, updated, "PatientsData.dat");
				}

				if (check == false)
				{
					cout << "User was not found!" << endl;
				}
			}

		}
		

		if (c == "3")
		{
			loggedin = false;
		}

	}


}



bool UpdateCNIC(string id, string updated_name, string file_name)
{
	user obj;
	fstream f(file_name, ios::out | ios::in | ios::binary);
	while (f.read((char*)&obj, sizeof(obj)))
	{
		if (obj.getID() == id)
		{
			obj.setCNIC(updated_name);
			int a = f.tellg();
			int s = sizeof(user);
			f.seekp(a - s, ios::beg);
			f.write((char*)&obj, sizeof(obj));
			f.close();
			return true;

		}
	}
	return false;
	f.close();
}
bool UpdateEmail(string id, string updated_name, string file_name)
{
	user obj;
	fstream f(file_name, ios::out | ios::in | ios::binary);
	while (f.read((char*)&obj, sizeof(obj)))
	{
		if (obj.getID() == id)
		{
			obj.setEmail(updated_name);
			int a = f.tellg();
			int s = sizeof(user);
			f.seekp(a - s, ios::beg);
			f.write((char*)&obj, sizeof(obj));
			f.close();
			return true;
		}
	}
	return false;
	f.close();
}
bool UpdateID(string id, string updated_name, string file_name)
{
	user obj;
	fstream f(file_name, ios::out | ios::in | ios::binary);
	while (f.read((char*)&obj, sizeof(obj)))
	{
		if (obj.getID() == id)
		{
			obj.setID(updated_name);
			int a = f.tellg();
			int s = sizeof(user);
			f.seekp(a - s, ios::beg);
			f.write((char*)&obj, sizeof(obj));
			f.close();
			return true;
		}
	}
	return false;
	f.close();
}
bool UpdatePassword(string id, string updated_name, string file_name)
{
	user obj;
	fstream f(file_name, ios::out | ios::in | ios::binary);
	while (f.read((char*)&obj, sizeof(obj)))
	{
		if (obj.getID() == id)
		{
			obj.setPassword(updated_name);
			int a = f.tellg();
			int s = sizeof(user);
			f.seekp(a - s, ios::beg);
			f.write((char*)&obj, sizeof(obj));
			f.close();
			return true;
		}
	}
	return false;
	f.close();
}
bool UpdateUsername(string id, string updated_name, string file_name)
{
	user obj;
	fstream f(file_name, ios::out | ios::in | ios::binary);
	while (f.read((char*)&obj, sizeof(obj)))
	{
		if (obj.getID() == id)
		{
			obj.setUserName(updated_name);
			int a = f.tellg();
			int s = sizeof(user);
			f.seekp(a - s, ios::beg);
			f.write((char*)&obj, sizeof(obj));
			f.close();
			return true;
		}
	}
	return false;
	f.close();
}
