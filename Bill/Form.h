#ifndef FORM_H
#define FORM_H

#include "Student.h"
#include "Bill.h"
#include <string>
#include <cstdlib>

using namespace std;

//const int size = 1;

class Form 
{
	// scope of variables and function operations still to be decided
	private:
		int i, dayIn, monthIn, yearIn, size, duration, fee;
		Student *stud; // Student object (Composition)(array of objects)
		Bill d;
		bool Vacc_Status, CovidTest;
		string Vacc_Type, campus;
		
	public:
		// default constructor
		Form();
		
		// overloaded constructor
		//Form (bool, bool, string, string, int, int);
		
		// Mutators
		void createDynamicArray(int);
		void setIterationNSize(int, int);
		void setVacc_Status(bool);
		void setCovidTest(bool);
		void setVacc_Type(string);
		void setCampus(string);
		void setDateInCampus (int, int, int);
		void calcDurationBill ();
		void setStudentInfo(int, string, string, int, int, string, string, bool, long long int, string);
		void setForm (bool, bool, string, string, int, int, int);
		void deleteArray();
		
		// Accessors
		string getVacc_Status();
		string getCovidTest();
		string getVacc_Type();
		string getCampus();
		int getDayIn();
		int getMonthIn();
		int getYearIn();
		void print(int);
		
		// Destructor
		~Form();
};

// Default Constructor -------------------------------------------------
Form::Form()
{
	Vacc_Status = false;
	CovidTest = false;
	Vacc_Type= "";
	campus = "";
	dayIn = 0;
	monthIn = 0;
	yearIn = 0;
}

// Overloaded Constructor -------------------------------------------------
//Form::Form(bool Vacc_Status, bool CovidTest, string Vacc_Type, string campus, int dateIn, int dateOut)
//{
//	this -> Vacc_Status = Vacc_Status;
//	this -> CovidTest = CovidTest;
//	this -> Vacc_Type= Vacc_Type;
//	this -> campus = campus;
//	this -> dateIn = dateIn;
//	this -> dateOut = dateOut;
//}

// Mutators  ------------------------------------------------------------
void Form::createDynamicArray(int size) 
{
   stud = new Student [size];
}

void Form::setIterationNSize(int i, int size) 
{
   this -> i = i;
   this -> size = size;
}

       
void Form::setVacc_Status(bool Vacc_Status)
{	
	this -> Vacc_Status = Vacc_Status;
}
		
void Form::setCovidTest(bool CovidTest)
{	
	this -> CovidTest = CovidTest;
}
		
void Form::setVacc_Type(string Vacc_Type)
{	
	this -> Vacc_Type= Vacc_Type;
}
		
void Form::setCampus(string campus)
{	
	this -> campus = campus;
}

void Form::calcDurationBill ()
{
	d.setDateIn(dayIn,monthIn,yearIn);
	duration = d.getDuration();
	fee = d.calcTotalFee();
}
		
void Form::setDateInCampus (int day, int month, int year)
{
	dayIn = day;
	monthIn = month;
	yearIn = year;
	calcDurationBill();
}




void Form::setForm(bool Vacc_Status, bool CovidTest, string Vacc_Type, string campus, int dayIn, int monthIn, int yearIn)
{
	this -> Vacc_Status = Vacc_Status;
	this -> CovidTest = CovidTest;
	this -> Vacc_Type= Vacc_Type;
	this -> campus = campus;
	this -> dayIn = dayIn;
	this -> monthIn = monthIn;
	this -> yearIn = yearIn;
}

void Form::setStudentInfo(int i, string name, string NRIC, int ID, int year, string school, string programme, bool status, long long int phone, string email)
{
		int num=i;
		stud[num].setInfo(name, NRIC, ID, year, school, programme, status, phone, email);
}

void Form::deleteArray() // delete dynamic array
{
	delete [] stud;
} 

// Accessors -----------------------------------------------------------------
string Form::getVacc_Status()
{
	if (Vacc_Status == 1)
	{
		return "Vaccinated";
	}
	else if (Vacc_Status == 0)
	{
		return "Unvacinated";
	}
}
		
string Form::getCovidTest()
{
	if (CovidTest == 1)
	{
		return "Positive";
	}
	else if (CovidTest == 0)
	{
		return "Negative";
	}
}
		
string Form::getVacc_Type()
{
	return  this->Vacc_Type;
}
		
string Form::getCampus()
{
	return  this->campus;
}
		
int Form::getDayIn()
{
	return  this->dayIn;
}
		
int Form::getMonthIn()
{
	return  this->monthIn;
}

int Form::getYearIn()
{
	return  this->yearIn;
}
		
void Form::print(int i)
{
		if (stud[i].getStatus()=="Active"&& getCovidTest() == "Negative" )
		{
			stud[i].print();
			
			cout << "Vaccine Status: " << getVacc_Status() <<endl;
			cout << "Covid Test Results: " << getCovidTest() <<endl;
			cout << "Vaccine Type (first booster): " << getVacc_Type() <<endl;
			cout << "USM Campus: " << getCampus() <<endl;
			
			cout << "Duration of stay: " <<duration<<endl;
			cout << "Total Fees: RM" <<fee<<endl;
			
			system("pause");
			system("CLS");
		}
		else if (stud[i].getStatus()=="Inactive" && getCovidTest() == "Positive")
		{
			cout << stud[i].getName() <<" is not an active student in USM and has tested positive for Covid-19. Stay not permitted." <<endl;
			
			system("pause");
			system("CLS");
		}
		else if (getCovidTest() == "Positive")
		{
			cout << stud[i].getName() <<" has tested positive for Covid-19. Stay not permitted." <<endl;
			
			system("pause");
			system("CLS");
		}
		else if (stud[i].getStatus()=="Inactive")
		{
			cout << stud[i].getName() <<" is not an active student in USM. Stay not permitted." <<endl;
			
			system("pause");
			system("CLS");
		}

}

// Destructor -----------------------------------------------------------
Form::~Form(){};


#endif
