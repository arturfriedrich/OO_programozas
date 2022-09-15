// 2021-tavasz-gyak01-b-Dates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

struct Date {
	int day, month, year;
	//Date() {
	//	year = 1970;
	//	month = 1;
	//	day = 1;
	//}
	Date(int d, int m, int y) {
		year = y; month = m; day = d;
		month = month > 0 && month < 13 ? month : 1;
		int upperDayLimit = (month == 4 ||
			month == 6 ||
			month == 9 ||
			month == 11) ? 30 : 31;
		if (month == 2) {
			upperDayLimit = (year % 4 == 0) ? 29 : 28;
		}
		day = day > 0 && day <= upperDayLimit ? day : 1;
	}
	std::string toString() {
		std::string output("");
		if (day < 10) {
			output += "0";
		}
		output += std::to_string(day);
		if (month == 1) { output += " Jan "; }
		if (month == 2) { output += " Feb "; }
		if (month == 3) { output += " Mar "; }
		if (month == 4) { output += " Apr "; }
		if (month == 5) { output += " May "; }
		if (month == 6) { output += " Jun "; }
		if (month == 7) { output += " Jul "; }
		if (month == 8) { output += " Aug "; }
		if (month == 9) { output += " Sep "; }
		if (month == 10) { output += " Oct "; }
		if (month == 11) { output += " Nov "; }
		if (month == 12) { output += " Dec "; }

		output += std::to_string(year);
		return output;
	}
	
	/*void print() {
		std::cout <<
			day << " / " <<
			month << " / " <<
			year << std::endl;
	}*/
};

int main()
{
	Date d1(9,-9,2021);
	Date d2(29,2,2022);
	Date d3(11,11,2023);
	//d1.print();
	//d2.print();
	//d3.print();
	std::cout << d1.toString() << std::endl;
	std::cout << d2.toString() << std::endl;
	std::cout << d3.toString() << std::endl;

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
