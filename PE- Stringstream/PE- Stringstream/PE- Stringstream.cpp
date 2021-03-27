// PE- Stringstream.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>


int main()
{
	int month = 3;
	int day = 27;
	int daysOfMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char birthday[] = { "Chase Call 4/25" };


	std::stringstream ss(birthday);
	std::string str;

	int birthMonth;
	int birthDay;
	char slash;


	ss >> str  >> str >> birthMonth >> slash >> birthDay;

	int daysTillBirth = 0;
	while (month != birthMonth || day != birthDay) {

		daysTillBirth++;
		day++;

		if (day > daysOfMonth[month]) {

			day = 1;
			month++;

		}
		if (month == 13) {
			month = 1;
		}

	}

	std::cout << str << ", your birthday is in " << daysTillBirth << " day(s).\n";

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
