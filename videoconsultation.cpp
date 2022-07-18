#include "videoconsultation.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#include <windows.h>

#include "appointments.h"
#include "DateAndTime.h"


void videoconsultation::book(appointments temp)
{
	//cout << "VIDEO CONSULTATION!" << endl;
	//cout << "These are the slots available for " << temp.GetAppDocName() << endl;
	//cout << "D ID " << temp.GetAppDocID() << endl;
	//cout << "P ID " << temp.GetAppPatID() << endl;
	//cout << "Patient NAme" << temp.GetAppPatName() << endl;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool oof = true;
	while (oof == true)
	{
		string str;
		doctors obj;
		ifstream out("DoctorsData.dat", ios::binary | ios::app);
		string check = temp.GetAppDocID();
		while (out.read((char*)&obj, sizeof(obj)))
		{
			if (obj.getDocID() == check)
			{
				system("CLS");
				SetConsoleTextAttribute(hConsole, 9);
				cout << "Mondays Slots\n\n";
				SetConsoleTextAttribute(hConsole, 15);
				int starthour = (int(obj.GetMonTimings()[0]) - 48) * 10 + int(obj.GetMonTimings()[1] - 48);
				int startmin = (int(obj.GetMonTimings()[3]) - 48) * 10 + int(obj.GetMonTimings()[4] - 48);
				int endhour = (int(obj.GetMonTimings()[7]) - 48) * 10 + int(obj.GetMonTimings()[8] - 48);
				int endmin = (int(obj.GetMonTimings()[9]) - 48) * 10 + int(obj.GetMonTimings()[10] - 48);
				while (starthour <= endhour && startmin <= endmin)
				{
					cout << "  " << starthour << ":" << startmin;
					if (startmin == 0)
					{
						cout << "0";
					}
					cout << endl;

					startmin += 15;
					if (startmin >= 60)
					{
						starthour++;
						startmin -= 60;
					}
					if (starthour > 12)
					{
						starthour = 1;
					}

				}

				SetConsoleTextAttribute(hConsole, 9);
				cout << "Tuesdays Slots\n\n";
				SetConsoleTextAttribute(hConsole, 15);
				starthour = (int(obj.GetTueTimings()[0]) - 48) * 10 + int(obj.GetTueTimings()[1] - 48);
				startmin = (int(obj.GetTueTimings()[3]) - 48) * 10 + int(obj.GetTueTimings()[4] - 48);
				endhour = (int(obj.GetTueTimings()[7]) - 48) * 10 + int(obj.GetTueTimings()[8] - 48);
				endmin = (int(obj.GetTueTimings()[9]) - 48) * 10 + int(obj.GetTueTimings()[10] - 48);
				while (starthour <= endhour && startmin <= endmin)
				{
					cout << "  " << starthour << ":" << startmin;
					if (startmin == 0)
					{
						cout << "0";
					}
					cout << endl;

					startmin += 15;
					if (startmin >= 60)
					{
						starthour++;
						startmin -= 60;
					}
					if (starthour > 12)
					{
						starthour = 1;
					}

				}

				SetConsoleTextAttribute(hConsole, 9);
				cout << "Wednesdays Slots\n\n";
				SetConsoleTextAttribute(hConsole, 15);
				starthour = (int(obj.GetWedTimings()[0]) - 48) * 10 + int(obj.GetWedTimings()[1] - 48);
				startmin = (int(obj.GetWedTimings()[3]) - 48) * 10 + int(obj.GetWedTimings()[4] - 48);
				endhour = (int(obj.GetWedTimings()[7]) - 48) * 10 + int(obj.GetWedTimings()[8] - 48);
				endmin = (int(obj.GetWedTimings()[9]) - 48) * 10 + int(obj.GetWedTimings()[10] - 48);
				while (starthour <= endhour && startmin <= endmin)
				{
					cout << "  " << starthour << ":" << startmin;
					if (startmin == 0)
					{
						cout << "0";
					}
					cout << endl;

					startmin += 15;
					if (startmin >= 60)
					{
						starthour++;
						startmin -= 60;
					}
					if (starthour > 12)
					{
						starthour = 1;
					}

				}

				SetConsoleTextAttribute(hConsole, 9);
				cout << "Thursday Slots\n\n";
				SetConsoleTextAttribute(hConsole, 15);
				starthour = (int(obj.GetThurTimings()[0]) - 48) * 10 + int(obj.GetThurTimings()[1] - 48);
				startmin = (int(obj.GetThurTimings()[3]) - 48) * 10 + int(obj.GetThurTimings()[4] - 48);
				endhour = (int(obj.GetThurTimings()[7]) - 48) * 10 + int(obj.GetThurTimings()[8] - 48);
				endmin = (int(obj.GetThurTimings()[9]) - 48) * 10 + int(obj.GetThurTimings()[10] - 48);
				while (starthour <= endhour && startmin <= endmin)
				{
					cout << "  " << starthour << ":" << startmin;
					if (startmin == 0)
					{
						cout << "0";
					}
					cout << endl;

					startmin += 15;
					if (startmin >= 60)
					{
						starthour++;
						startmin -= 60;
					}
					if (starthour > 12)
					{
						starthour = 1;
					}

				}

				SetConsoleTextAttribute(hConsole, 9);
				cout << "Friday Slots\n\n";
				SetConsoleTextAttribute(hConsole, 15);
				starthour = (int(obj.GetFriTimings()[0]) - 48) * 10 + int(obj.GetFriTimings()[1] - 48);
				startmin = (int(obj.GetFriTimings()[3]) - 48) * 10 + int(obj.GetFriTimings()[4] - 48);
				endhour = (int(obj.GetFriTimings()[7]) - 48) * 10 + int(obj.GetFriTimings()[8] - 48);
				endmin = (int(obj.GetFriTimings()[9]) - 48) * 10 + int(obj.GetFriTimings()[10] - 48);
				while (starthour <= endhour && startmin <= endmin)
				{
					cout << "  " << starthour << ":" << startmin;
					if (startmin == 0)
					{
						cout << "0";
					}
					cout << endl;

					startmin += 15;
					if (startmin >= 60)
					{
						starthour++;
						startmin -= 60;
					}
					if (starthour > 12)
					{
						starthour = 1;
					}

				}

				SetConsoleTextAttribute(hConsole, 9);
				cout << "Saturday Slots\n\n";
				SetConsoleTextAttribute(hConsole, 15);
				starthour = (int(obj.GetSatTimings()[0]) - 48) * 10 + int(obj.GetSatTimings()[1] - 48);
				startmin = (int(obj.GetSatTimings()[3]) - 48) * 10 + int(obj.GetSatTimings()[4] - 48);
				endhour = (int(obj.GetSatTimings()[7]) - 48) * 10 + int(obj.GetSatTimings()[8] - 48);
				endmin = (int(obj.GetSatTimings()[9]) - 48) * 10 + int(obj.GetSatTimings()[10] - 48);
				while (starthour <= endhour && startmin <= endmin)
				{
					cout << "  " << starthour << ":" << startmin;
					if (startmin == 0)
					{
						cout << "0";
					}
					cout << endl;

					startmin += 15;
					if (startmin >= 60)
					{
						starthour++;
						startmin -= 60;
					}
					if (starthour > 12)
					{
						starthour = 1;
					}

				}

				SetConsoleTextAttribute(hConsole, 9);
				cout << "Sunday Slots\n\n";
				SetConsoleTextAttribute(hConsole, 15);
				starthour = (int(obj.GetSunTimings()[0]) - 48) * 10 + int(obj.GetSunTimings()[1] - 48);
				startmin = (int(obj.GetSunTimings()[3]) - 48) * 10 + int(obj.GetSunTimings()[4] - 48);
				endhour = (int(obj.GetSunTimings()[7]) - 48) * 10 + int(obj.GetSunTimings()[8] - 48);
				endmin = (int(obj.GetSunTimings()[9]) - 48) * 10 + int(obj.GetSunTimings()[10] - 48);
				while (starthour <= endhour && startmin <= endmin)
				{
					cout << "  " << starthour << ":" << startmin;
					if (startmin == 0)
					{
						cout << "0";
					}
					cout << endl;

					startmin += 15;
					if (startmin >= 60)
					{
						starthour++;
						startmin -= 60;
					}
					if (starthour > 12)
					{
						starthour = 1;
					}

				}
			}
		}
		out.close();

		cout << "Please Enter the Date you would like to book you video consulation(dd/mm/yy): ";
		cin >> str;

		string time;
		cout << "Please select the time: ";
		cin >> time;






		





	}



	


	


	




}
