#ifndef BILL_H
#define BILL_H

#include "Date.h"
#include <iostream>
using namespace std;

// class Bill inherited from class Date
class Bill : public Date
{
	private:
		int FeePerDay = 5;
		int totalFee;	//Hostel total fee

	public:
		// Default Constructor
		Bill(){};
		
		int setDateIn(int day, int month, int year)
		{
			setDate(day, month, year);
		}
		
		int getDuration()
		{
			calculateDay();
			return getDiff();
		}
		int calcTotalFee()
		{
			totalFee = calculateDay()*FeePerDay;
			return totalFee;
		}			
};



#endif
