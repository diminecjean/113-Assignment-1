#include "Date.h"
#include <iostream>
using namespace std;

void DateInput();

int main()
{
	DateInput();
	
	return 0;
}

// menu for date
void DateInput()
{
	
	int day1, month1, year1; 	// check in date 
    int day2, month2, year2; 	// check out date (fixed)
    
	cout<<endl;
	cout << "\t\t\t\t ________________________Reminder_______________________\n";
	cout << "\t\t\t\t|\tWays to enter check-in and check-out date:\t|\n";
	cout << "\t\t\t\t|\tExample:( date(15.4.2022) )\t\t\t|\n";
	cout << "\t\t\t\t|\tPlease enter check in date: 1\t\t\t|\n";
	cout << "\t\t\t\t|\tDay	: 15\t\t\t\t\t|\n";
	cout << "\t\t\t\t|\tMonth	: 4\t\t\t\t\t|\n";
	cout << "\t\t\t\t|\tYear	: 2022\t\t\t\t\t|\n";
	cout << "\t\t\t\t|_______________________________________________________|\n\n";
	cout << "\t\t\t     **************************************************************";
	cout << "\n\t\t\t     Enter '0' or characters other than integers to exit the system\n"; 
	cout << "\t\t\t     **************************************************************\n";
    
    cout << "\n==========================================================================================";
    cout << "\n\nCheck out date:\n"; // fixed at one week after last day of final exam
    
	day2 = 21;
    month2 = 8;  
    year2 = 2022;
    
    cout << "Day	: ";
    cout << day2;
    cout << "\nMonth	: ";
    cout << month2;
    cout << "\nYear	: ";
    cout << year2;
 
	// Inputting check in date
    cout << "\n\nPlease enter the check in date:\n";
    cout << "Day	: ";
    cin >> day1;
    cout << "Month	: ";
    cin >> month1;
    cout << "Year	: ";
    cin >> year1;

	Date d(day1, month1, year1, day2, month2, year2);
    d.calculateDay();
    
}
