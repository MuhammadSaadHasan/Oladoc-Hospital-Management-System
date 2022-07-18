#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <MMSystem.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "patients.h"
#include "oladoc.h"
#include "doctors.h"
#include "user.h"

string SearchForUserNameAndPassword(string file, string UN, string Pass);




using namespace std;
int main()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    oladoc od;
    cout << "****************************WELCOME TO ";SetConsoleTextAttribute(hConsole, 6);cout << "OLA";SetConsoleTextAttribute(hConsole, 1);cout << "DOC";SetConsoleTextAttribute(hConsole, 15);cout << " ****************************" << endl << endl << endl;

    while (true)
    {
        //PlaySound(TEXT("soundcheck.wav"), NULL, SND_FILENAME | SND_SYNC);

        string choice;
        cout << "Choose one of the following" << endl;
        cout << "1 - Register" << endl;
        cout << "2 - Login" << endl;
        cout << "3 - Hospitals List" << endl;
        cout << "4 - Doctors List" << endl;
        cout << "5 - Departments List" << endl;
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
            string choice = od.Register();
            SetConsoleTextAttribute(hConsole, 2);
            cout << "\nCongratulations you have successfully registered an Account on Oladoc!\n\n\n";
            SetConsoleTextAttribute(hConsole, 15);
            
            
            
        }
        if (choice == "2")
        {
            string dummy;
            cout << "Are you Logging in as Doctor or Patient or Admin";
            cin >> dummy;

            string UN;
            string Pass;
            cout << "\n\nEnter you UserName: ";
            cin >> UN;
            cout << "Enter you Password: ";
            cin >> Pass;
            string idRecieved = SearchForUserNameAndPassword("UserData.dat", UN, Pass);

            while (idRecieved == "x")
            {
                SetConsoleTextAttribute(hConsole, 4);
                cout << "*UserName or Password Incorrect" << endl;
                cout << "*Please Enter Again" << endl << endl;
                SetConsoleTextAttribute(hConsole, 15);
                cout << "\n\nEnter you UserName: ";
                cin >> UN;
                cout << "Enter you Password: ";
                cin >> Pass;
                idRecieved = SearchForUserNameAndPassword("UserData.dat", UN, Pass);

            }

            od.login(idRecieved);
            

        }
    }



    system("pause");
}


string SearchForUserNameAndPassword(string file, string UN, string Pass)
{
    user obj;
    ifstream fin(file, ios::binary | ios::app);
    while (fin.read((char*)&obj, sizeof(obj)))
    {
        if (obj.getUserName() == UN && obj.getPassword() == Pass)
        {

            return obj.getID();
        }
    }
    fin.close();
    return "x";
}




