#include <iostream> 
#include <string>
#include <cstdlib>
#include "Date.h"
#include "Bill.h"

using namespace std;


int getFee (Bill b)
{
	return b.calcTotalFee();
}

int main()
{
	Date d(31,7,2021);
	cout << d.calculateDay();
	cout << getFee(d);
	
	return 0;
}
