#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;
#include "user.h"
#include "oladoc.h"

user::user()
{

}
string user::RegisterUser(char type)
{
	system("CLS");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "****************************";SetConsoleTextAttribute(hConsole, 6);cout << "REGISTRATION";SetConsoleTextAttribute(hConsole, 1);cout << " PORTAL";SetConsoleTextAttribute(hConsole, 15);cout << " ****************************" << endl << endl << endl;

	if (type == 'D')
	{
		SetConsoleTextAttribute(hConsole, 3);
		cout << "        Doctor Registration.\n" << endl;
		SetConsoleTextAttribute(hConsole, 15);
	}

	this->setIDtype(type);


	bool EnteredWrongOnce = false;
	bool check = false;
	string str;
	cout << "Enter your username: ";
	cin >> str;

	check = SearchForUserName(str);
	while (check == true)
	{
		SetConsoleTextAttribute(hConsole, 4);
		cout << "*This UserName is already taken. Please create a unique one." << endl;
		cout << "(Try " << str << "01 or " << str << "OlaDoc)" << endl;
		SetConsoleTextAttribute(hConsole, 15);
		cout << "Input: ";
		cin >> str;
		check = SearchForUserName(str);
		EnteredWrongOnce = true;
	}

	if (EnteredWrongOnce == false)
	{
		cout << "\033[F";
		cout << "Enter your username: " << str;
		SetConsoleTextAttribute(hConsole, 2);
		cout << "    accepted" << endl << endl;
		SetConsoleTextAttribute(hConsole, 15);

	}
	else
	{
		cout << "\033[F";
		cout << "Input: " << str;
		SetConsoleTextAttribute(hConsole, 2);
		cout << "    accepted" << endl << endl;
		SetConsoleTextAttribute(hConsole, 15);
	}

	EnteredWrongOnce = false;


	int i = 0;

	strcpy_s(this->username, str.c_str());

	cout << "(xxxxx-xxxxxxx-x)" << endl;
	cout << "Enter your CNIC: ";
	cin >> str;
	while (str[i] != '\0')
	{
		i++;
	}
	while (i != 15 || str[5] != '-' || str[13] != '-')
	{
		SetConsoleTextAttribute(hConsole, 4);
		cout << "\n*Please enter your CNIC according to the given format" << endl;
		SetConsoleTextAttribute(hConsole, 15);
		cout << "Input: ";
		cin >> str;
		i = 0;
		while (str[i] != '\0')
		{
			i++;
		}
		EnteredWrongOnce = true;
	}

	check = SearchForCNIC(str,type);
	while (check == true)
	{
		SetConsoleTextAttribute(hConsole, 4);
		cout << "*An account has already been registered by this CNIC" << endl;
		SetConsoleTextAttribute(hConsole, 15);
		cout << "Input: ";
		cin >> str;

		while (str[i] != '\0')
		{
			i++;
		}
		while (i != 15 || str[5] != '-' || str[13] != '-')
		{
			SetConsoleTextAttribute(hConsole, 4);
			cout << "\n*Please enter your CNIC according to the given format" << endl;
			SetConsoleTextAttribute(hConsole, 15);
			cout << "Input: ";
			cin >> str;
			i = 0;
			while (str[i] != '\0')
			{
				i++;
			}
		}

		check = SearchForCNIC(str,type);
		EnteredWrongOnce = true;
	}

	if (EnteredWrongOnce == false)
	{
		cout << "\033[F";
		cout << "Enter your CNIC: " << str;
		SetConsoleTextAttribute(hConsole, 2);
		cout << "    accepted" << endl << endl;
		SetConsoleTextAttribute(hConsole, 15);

	}
	else
	{
		cout << "\033[F";
		cout << "Input: " << str;
		SetConsoleTextAttribute(hConsole, 2);
		cout << "    accepted" << endl << endl;
		SetConsoleTextAttribute(hConsole, 15);
	}

	EnteredWrongOnce = false;





	strcpy_s(this->CNIC, str.c_str());

	cout << "Your password must be 8 characters long and one special character, uppercase, lowercase, and the numeric digit is a must" << endl;
	cout << "Enter your Password: ";
	cin >> str;
	bool upper = false;
	bool lower = false;
	bool numeric = false;
	bool special = false;
	i = 0;
	int sizeOfPassword = 0;
	while (str[i] != '\0')
	{
		if ((int(str[i]) >= 33 && int(str[i]) <= 47) || (int(str[i]) >= 58 && int(str[i]) <= 64) || (int(str[i]) >= 91 && int(str[i]) <= 96) || (int(str[i]) >= 123 && int(str[i]) <= 128))
		{
			special = true;
		}
		if ((int(str[i]) >= 49 && int(str[i]) <= 57))
		{
			numeric = true;
		}
		if ((int(str[i]) >= 65 && int(str[i]) <= 90))
		{
			upper = true;
		}
		if ((int(str[i]) >= 97 && int(str[i]) <= 122))
		{
			lower = true;
		}
		i++;
		sizeOfPassword++;
	}
	i = 0;
	while (upper == false || lower == false || special == false || numeric == false || sizeOfPassword != 8)
	{
		upper = false;
		lower = false;
		numeric = false;
		special = false;
		SetConsoleTextAttribute(hConsole, 4);
		cout << "*Your password doesnt match the conditions" << endl;
		SetConsoleTextAttribute(hConsole, 15);
		cout << "Input: ";
		cin >> str;
		i = 0;
		sizeOfPassword = 0;
		while (str[i] != '\0')
		{
			if ((int(str[i]) >= 33 && int(str[i]) <= 47) || (int(str[i]) >= 58 && int(str[i]) <= 64) || (int(str[i]) >= 91 && int(str[i]) <= 96) || (int(str[i]) >= 123 && int(str[i]) <= 128))
			{
				special = true;
			}
			if ((int(str[i]) >= 49 && int(str[i]) <= 57))
			{
				numeric = true;
			}
			if ((int(str[i]) >= 65 && int(str[i]) <= 90))
			{
				upper = true;
			}
			if ((int(str[i]) >= 97 && int(str[i]) <= 122))
			{
				lower = true;
			}
			i++;
			sizeOfPassword++;
		}
		EnteredWrongOnce = true;
	}


	check = SearchForPassword(str);
	while (check == true)
	{
		SetConsoleTextAttribute(hConsole, 4);
		cout << "*Your password is already taken. Please create a unique one." << endl;
		SetConsoleTextAttribute(hConsole, 15);
		cout << "Input: ";
		cin >> str;
		upper = false;
		lower = false;
		numeric = false;
		special = false;
		i = 0;
		int sizeOfPassword = 0;
		while (str[i] != '\0')
		{
			if ((int(str[i]) >= 33 && int(str[i]) <= 47) || (int(str[i]) >= 58 && int(str[i]) <= 64) || (int(str[i]) >= 91 && int(str[i]) <= 96) || (int(str[i]) >= 123 && int(str[i]) <= 128))
			{
				special = true;
			}
			if ((int(str[i]) >= 49 && int(str[i]) <= 57))
			{
				numeric = true;
			}
			if ((int(str[i]) >= 65 && int(str[i]) <= 90))
			{
				upper = true;
			}
			if ((int(str[i]) >= 97 && int(str[i]) <= 122))
			{
				lower = true;
			}
			i++;
			sizeOfPassword++;
		}
		i = 0;
		while (upper == false || lower == false || special == false || numeric == false || sizeOfPassword != 8)
		{
			upper = false;
			lower = false;
			numeric = false;
			special = false;
			SetConsoleTextAttribute(hConsole, 4);
			cout << "*Your password doesnt match the conditions" << endl;
			SetConsoleTextAttribute(hConsole, 15);
			cout << "Input: ";
			cin >> str;
			i = 0;
			sizeOfPassword = 0;
			while (str[i] != '\0')
			{
				if ((int(str[i]) >= 33 && int(str[i]) <= 47) || (int(str[i]) >= 58 && int(str[i]) <= 64) || (int(str[i]) >= 91 && int(str[i]) <= 96) || (int(str[i]) >= 123 && int(str[i]) <= 128))
				{
					special = true;
				}
				if ((int(str[i]) >= 49 && int(str[i]) <= 57))
				{
					numeric = true;
				}
				if ((int(str[i]) >= 65 && int(str[i]) <= 90))
				{
					upper = true;
				}
				if ((int(str[i]) >= 97 && int(str[i]) <= 122))
				{
					lower = true;
				}
				i++;
				sizeOfPassword++;
			}
		}
		check = SearchForPassword(str);
		EnteredWrongOnce = true;
	}


	if (EnteredWrongOnce == false)
	{
		cout << "\033[F";
		cout << "Enter your Password: " << str;
		SetConsoleTextAttribute(hConsole, 2);
		cout << "    accepted" << endl << endl;
		SetConsoleTextAttribute(hConsole, 15);

	}
	else
	{
		cout << "\033[F";
		cout << "Input: " << str;
		SetConsoleTextAttribute(hConsole, 2);
		cout << "    accepted" << endl << endl;
		SetConsoleTextAttribute(hConsole, 15);
	}

	EnteredWrongOnce = false;

	strcpy_s(this->password, str.c_str());

	cout << "Oladoc works with Hotmail, Gmail, Yahoo and Fast" << endl;
	cout << "Enter your email: ";
	cin >> str;
	i = 0;
	int ats = 0;
	bool correctEmailPlatfrom = false;
	while (str[i] != '\0')
	{

		if (str[i] == '@')
		{
			ats++;
			if ((str[i + 1] == 'g' && str[i + 2] == 'm' && str[i + 3] == 'a' && str[i + 4] == 'i' && str[i + 5] == 'l' && str[i + 6] == '.' && str[i + 7] == 'c' && str[i + 8] == 'o' && str[i + 9] == 'm')
				|| (str[i + 1] == 'h' && str[i + 2] == 'o' && str[i + 3] == 't' && str[i + 4] == 'm' && str[i + 5] == 'a' && str[i + 6] == 'i' && str[i + 7] == 'l' && str[i + 8] == '.' && str[i + 9] == 'c' && str[i + 10] == 'o' && str[i + 11] == 'm')
				|| (str[i + 1] == 'y' && str[i + 2] == 'a' && str[i + 3] == 'h' && str[i + 4] == 'o' && str[i + 5] == 'o' && str[i + 6] == '.' && str[i + 7] == 'c' && str[i + 8] == 'o' && str[i + 9] == 'm')
				|| (str[i + 1] == 'n' && str[i + 2] == 'u' && str[i + 3] == '.' && str[i + 4] == 'e' && str[i + 5] == 'd' && str[i + 6] == 'u' && str[i + 7] == '.' && str[i + 8] == 'p' && str[i + 9] == 'k'))
			{
				correctEmailPlatfrom = true;
			}
		}
		i++;
	}
	while (ats != 1 || correctEmailPlatfrom == false)
	{
		SetConsoleTextAttribute(hConsole, 4);
		cout << "\n*Please enter a valid email address" << endl;
		SetConsoleTextAttribute(hConsole, 15);
		cout << "Input: ";
		cin >> str;
		ats = 0;
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] == '@')
			{
				ats++;
				if ((str[i + 1] == 'g' && str[i + 2] == 'm' && str[i + 3] == 'a' && str[i + 4] == 'i' && str[i + 5] == 'l' && str[i + 6] == '.' && str[i + 7] == 'c' && str[i + 8] == 'o' && str[i + 9] == 'm')
					|| (str[i + 1] == 'h' && str[i + 2] == 'o' && str[i + 3] == 't' && str[i + 4] == 'm' && str[i + 5] == 'a' && str[i + 6] == 'i' && str[i + 7] == 'l' && str[i + 8] == '.' && str[i + 9] == 'c' && str[i + 10] == 'o' && str[i + 11] == 'm')
					|| (str[i + 1] == 'y' && str[i + 2] == 'a' && str[i + 3] == 'h' && str[i + 4] == 'o' && str[i + 5] == 'o' && str[i + 6] == '.' && str[i + 7] == 'c' && str[i + 8] == 'o' && str[i + 9] == 'm')
					|| (str[i + 1] == 'n' && str[i + 2] == 'u' && str[i + 3] == '.' && str[i + 4] == 'e' && str[i + 5] == 'd' && str[i + 6] == 'u' && str[i + 7] == '.' && str[i + 8] == 'p' && str[i + 9] == 'k'))
				{
					correctEmailPlatfrom = true;
				}
			}
			i++;
		}
		EnteredWrongOnce = true;

	}

	check = SearchForEmail(str);
	while (check == true)
	{
		SetConsoleTextAttribute(hConsole, 4);
		cout << "*An Account has already been made using this email" << endl;
		SetConsoleTextAttribute(hConsole, 15);
		cout << "Input: ";
		cin >> str;
		i = 0;
		int ats = 0;
		while (str[i] != '\0')
		{
			if (str[i] == '@')
			{
				ats++;
			}
			i++;
		}
		while (ats != 1)
		{
			SetConsoleTextAttribute(hConsole, 4);
			cout << "\n*Please enter a valid email address" << endl;
			SetConsoleTextAttribute(hConsole, 15);
			cout << "Input: ";
			cin >> str;
			ats = 0;
			i = 0;
			while (str[i] != '\0')
			{
				if (str[i] == '@')
				{
					ats++;
				}
				i++;
			}

		}
		check = SearchForEmail(str);
		EnteredWrongOnce = true;
	}

	//************************************************************
	if (EnteredWrongOnce == false)
	{
		cout << "\033[F";
		cout << "Enter your email : " << str;
		SetConsoleTextAttribute(hConsole, 2);
		cout << "    accepted" << endl << endl;
		SetConsoleTextAttribute(hConsole, 15);

	}
	else
	{
		cout << "\033[F";
		cout << "Input: " << str;
		SetConsoleTextAttribute(hConsole, 2);
		cout << "    accepted" << endl << endl;
		SetConsoleTextAttribute(hConsole, 15);
	}

	EnteredWrongOnce = false;

	strcpy_s(this->email, str.c_str());
	
	int temp;
	if (type == 'D')
	{
		str = "D-    ";
		temp = DoctorsPatientsCounter('D');


	}
	else if (type == 'P')
	{
		str = "P-    ";
		temp = DoctorsPatientsCounter('P');

	}
	else
	{
		str = "A-    ";
		temp = DoctorsPatientsCounter('A');
	}

	for (int i = 5; i > 1;i--)
	{
		str[i] = char((temp % 10) + 48);
		temp -= (temp % 10);
		temp = temp / 10;
	}

	strcpy_s(this->ID, str.c_str());

	cout << "Your ID NUMBER IS ";
	SetConsoleTextAttribute(hConsole, 3);
	cout << this->ID << endl;
	SetConsoleTextAttribute(hConsole, 15);
	writeUserData("UserData.dat", *this);


	return ID;


}




char user::getIDtype()
{
	return idType;

}
void user::setIDtype(char t)
{
	idType = t;
}
void user::LoginUser(user MainAccessObject)
{
	cout << "User Login" << endl;

}
void user::displayalldata()
{
	cout << username << endl;
	cout << CNIC << endl;
	cout << ID << endl;
	cout << email << endl;
	cout << password << endl << endl << endl << endl;
}
char* user::getID()
{
	return ID;
}
char* user::getPassword()
{
	return password;
}
char* user::getCNIC()
{
	return CNIC;
}
char* user::getUserName()
{
	return username;
}
char* user::getEmail()
{
	return email;
}
void user::setID(string str)
{

	strcpy_s(this->ID, str.c_str());
}
void user::setPassword(string str)
{
	strcpy_s(this->password, str.c_str());

}
void user::setCNIC(string str)
{
	strcpy_s(this->CNIC, str.c_str());
}
void user::setUserName(string str)
{
	strcpy_s(this->username, str.c_str());
}
void user::setEmail(string str)
{
	strcpy_s(this->email, str.c_str());
}
int DoctorsPatientsCounter(char t)
{
	user obj;
	int count = 1;
	ifstream fin("UserData.dat", ios::binary | ios::app);
	while (fin.read((char*)&obj, sizeof(obj)))
	{
		if (obj.getIDtype() == t)
		{
			count++;
		}

	}

	fin.close();

	return count;


}






