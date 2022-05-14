// Class to calculate the total number of days of stay by student
#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date{
	private:
		int day1, month1, year1; 	        // check in date 
	    int day2=21, month2=8, year2=2022; 	// check out date (assume: fixed)
	    int n;								// max day of the month
	    bool date1 = false; 
	    bool dateVal = false; 				// make sure check in date is not later than check out date
	protected:
		long long int diff; 				// to store total days stayed by student

	public: 
		Date(); 				// Default constructor
		Date(int, int, int); 	// Overloading constructor
		~Date(); 				// Default destructor 
		
		// Mutators
		void setDay1(int);
		void setMonth1(int);
		void setYear1(int);
		void setDate(int, int, int);
		int calculateDay();		// let user input date in order to calculate days stayed by student in the hostel
		bool LeapYear(int);		// identify whether if the year is a leap year
		int DaysOfMonth(int, int); // Calculate days stayed by student in the hostel
		long long int DiffOfDay(int,int, int, int, int, int); // Calculate days stayed by student in the hostel		
		
		// Accessor
		int getDiff()const;
};


//Default Constructor------------------------------------------------------------------------------------------------------------------------------------	
Date::Date()	
{
	day1 = 0;
	month1 = 0;
	year1 = 0;
	day2 = 0;
	month2 = 0;
	year2 = 0;
}

// Overloading constructor---------------------------------------------------------------------------------------------------------------------------------------
Date::Date(int dayA,int monthA, int yearA)
{
	day1 = dayA;
	month1 = monthA;
	year1 = yearA;
}

// Destructor--------------------------------------------------------------------------------------------------------------------------------------------
Date::~Date()	
{
	day1 = 0;
	month1 = 0;
	year1 = 0;
	day2 = 0;
	month2 = 0;
	year2 = 0;
}


// Accesors -------------------------------------------------------------------------------------------------------------------------------------------

// set day, month and year
void Date::setDay1(int dayA)
{
	day1 = dayA;
}

void Date::setMonth1(int monthA)
{
	month1 = monthA;
}

void Date::setYear1(int yearA)
{
	year1 = yearA;
}

// Set date
void Date::setDate(int dayA, int monthA, int yearA)
{
	day1 = dayA;
	month1 = monthA;
	year1 = yearA;
	day2 = 21;
	month2 = 8;
	year2 = 2022;
}
	
// Determine if year of date is a leap year
bool Date::LeapYear(int year)
{
    if( year % 4 == 0 && year % 100 != 0 || year % 400 == 0 )   
        return true;
   
    else
        return false;
}

// Determine days in the month of the date
int Date::DaysOfMonth(int month, int year)
{
    // january, march, may, july, august, october, december contains 31 days
    if( month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12 )
        return 31;
       
    // april, june, september, november contains 30 days
    if( month==4 || month==6 || month==9 || month==11 )
        return 30;
    
    // february contains 28 or 29 days
    if( month==2 )
    {
        bool b=LeapYear(year);
        if(b==true)    // if year is a leap year then february contains 29 days, else it contains 28 days
            return 29;
       
        else
            return 28;
    }
}

// To find out the differences between dates
long long int Date::DiffOfDay(int day1,int month1, int year1, int day2, int month2, int year2)
{
    if( year1 == year2 )			// same year
    {
        if( month1 == month2 )		// same month
        {
            if( day1 == day2 )      //same day for check in and check out
                return 0;
            else if (day1 < day2)
                return ( day2 - day1 );  // diff days (only accepts day2 > day1, if day1 > day2 means checkout is earlier than check in , invalid)
        }
        else if( month1 < month2 )		// diff months 
        {
            int result = 0;
            for( int i = month1; i < month2; i++ )
                result = result + DaysOfMonth(i, year1);
               
            if( day1 == day2 )      	// same day
                return result;
            else if( day1 < day2 )		// diff days
            {
                result = result + ( day2 - day1 );	
                return result;
            }  
            else
            {
                result = result - (day1 - day2);	// diff days ( accepts day2 < day1 days bcs diff months )
                return result;
            }  
        }
    }
    else if(year1 < year2)	// diff year
    {
        int tempday = 0;
        for(int i=year1; i<year2; i++)
        {
            if(LeapYear(i))
            	if (((day1 > day2) && (month1 > month2)) || (month1 > 2))
            	tempday = tempday + 365;	// leap year with month after february
            	else
                tempday = tempday + 366;	// leap year with month before or on february (january, february)
            else
                tempday = tempday + 365;
        }
        if(month1 == month2)     // same month, diff year 
        {
            if(day1 == day2)      //same day 
                return tempday;
            else if(day1 < day2)	// diff day
                return tempday + (day2 - day1);
            else
                return tempday - (day1 - day2);		// day1 > day 2 accepted
        }
        else if(month1 < month2)	// diff months
        {
            int result = 0;
            for(int i = month1; i<month2; i++)
                result = result + DaysOfMonth(i,year2);
               
            if(day1 == day2)      //same day, different year and different month
                return tempday+result;
            else if(day1 < day2)
            {
                result = result+(day2 - day1);
                return tempday+result;
            }
            else
            {
                result = result - (day1 - day2);
                return tempday + result;
            }
        }
        else // month1 > month2
        {
            int result = 0;
            for(int i = month2; i<month1; i++)
                result = result + DaysOfMonth(i, year2);
               
            if(day1 == day2)
                return tempday-result;
            else if(day2<day1)
            {
                result = result + (day1 - day2);
                return tempday - result;
            }
            else if (day1 < day2)
            {
                result = result - (day2 - day1);
                return tempday-result;
            }
        }
    }
}

//Prompt user to input check-in date, and evaluate the day(s) stayyed by the patient
int Date::calculateDay()
{
 	n = DaysOfMonth(month1,year1);
   
    // checking validation of check in date	
   	while (!date1)
    {
    	if (day1 == 0 || month1 == 0|| year1 == 0)   // to avoid infinite loop when entering non-integer
		{
			// assign random numbers to avoid infinite loop
			day1 = 158;
			month1 = 477;
			year1 = 787; 
			
			cout << "\n\nInteger '0' / Characters other than integers detected...\n\nExiting the system...\n\n";
			exit(1);
		}
		
    	// prompt user to input date again if the entered date is invalid
	   	else if( day1<1 || day1>n || month1<1 || month1 >12 || year1 <1 )
	   	{		
    		cout << "\nXXX Check in date is not valid. Please enter the check in date again. XXX\n\n";
        	cout << "Please enter the check in date:\n";
		    cout << "Day	: ";
		    cin >> day1;
		    cout << "Month	: ";
		    cin >> month1;
		    cout << "Year	: ";
		    cin >> year1;		  

		    n = DaysOfMonth(month1,year1);    
		}
        else 
        	date1 = true;
    }
    
   
   // make sure check in date is not later than check out date
   date1 = false;
   while (!dateVal)
   {
   		if ( ((year1 == year2) && (month1 == month2) && (day1 > day2)) || ( (year1 == year2) && (month1 > month2)) || (year1 > year2))
   		{
   			// Inputting check in date again because check in date is later than check out date
   			cout << "\n\nXXX Check in date should not be later than check out date. XXX\nPlease reenter the dates.\n\n";
		    cout << "Please enter the check in date:\n";
		    cout << "Day	: ";
		    cin >> day1;
		    cout << "Month	: ";
		    cin >> month1;
		    cout << "Year	: ";
		    cin >> year1;
		    
		    n = DaysOfMonth(month1,year1);
		    
   			if (day1 == 0 || month1 == 0|| year1 == 0)   // to avoid infinite loop when entering non-integer
			{
			// assign random numbers to avoid infinite loop
			day1 = 158;
			month1 = 477;
			year1 = 787; 
			
			cout << "\n\nInteger '0' / Characters other than integers detected...\n\nExiting the system...\n\n";
			exit(1);
			}
		
		    // checking validation of check in date	
		   	while (!date1)
		    {
		    	// prompt user to input date again if the entered date is invalid
			   	if( day1<1 || day1>n || month1<1 || month1 >12 || year1 <1 )
			   	{	
		    		cout << "\nXXX Check in date is not valid. Please enter the check in date again. XXX\n\n";
		        	cout << "Please enter the check in date:\n";
				    cout << "Day	: ";
				    cin >> day1;
				    cout << "Month	: ";
				    cin >> month1;
				    cout << "Year	: ";
				    cin >> year1;
				    
				    n = DaysOfMonth(month1,year1);    
				}
		        else 
		        	date1 = true;
	    	}
		}
			
		else
			dateVal = true;
	}
   
    // Counting the difference between check out and check in dates in terms of number of days
    diff = DiffOfDay(day1, month1, year1, day2, month2, year2);
    return diff;
}


// Accessor ---------------------------------------------------------------------------------------------------
int Date::getDiff() const
{
	return diff;
}



#endif
