#ifndef BILL_H
#define BILL_H

#include "Date.h"
#include <iostream>
using namespace std;

class Bill : public Date
{
	private:
		int FeePerDay = 5;
		int totalFee;	//Hostel total fee

	public:
		//
		//
		
		friend int getFee(Bill b);
		int calcTotalFee()
		{
			totalFee = diff*FeePerDay;
			return totalFee;
		}	

			
};



#endif
