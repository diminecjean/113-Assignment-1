// Class to calculate the total bill for the stay of student
#ifndef BILL_H
#define BILL_H

#include "Date.h"
#include <iostream>
using namespace std;

// class Bill inherited from class Date
class Bill : public Date
{
	private:
		int FeePerDay = 5;	// Fee per day fixed to RM5
		int totalFee;		// Hostel total fee

	public:
		// Default Constructor
		Bill()
		{
			totalFee=0;
		};
		
		
		// Mutators
		int setDateIn(int day, int month, int year) // Set the check in dates
		{
			setDate(day, month, year);
		}
		
		int calcDuration() // Calculate the duration of the stay from member inherited by class Date
		{
			calculateDay();
			return getDiff();
		}
		
		int calcTotalFee() // Calculate the total fee for the stay
		{
			totalFee = calculateDay()*FeePerDay;
			return totalFee;
		}		
};



#endif
