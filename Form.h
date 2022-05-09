#ifndef FORM_H
#define FORM_H

#include "Student.h"
#include <string>
#include <cstdlib>

using namespace std;

const int size = 1;

class Form
{
	// scope of variables and function operations still to be decided
	private:
		Student stud[size]; // Student object (Composition)(array of objects)
		bool Vacc_Status, CovidTest;
		string Vacc_Type, campus;
		int dateIn, dateOut;
		
	public:
		// default constructor
		Form();
		
		// overloaded constructor
		Form (bool, bool, string, string, int, int);
		
		// Mutators
		void setVacc_Status(bool);
		void setCovidTest(bool);
		void setVacc_Type(string);
		void setCampus(string);
		void setDateIn(int);
		void setDateOut(int);
		void setStudentInfo(string, int, int, string, string, bool, long int, string);
		
		// Accessors
		bool getVacc_Status();
		bool getCovidTest();
		string getVacc_Type();
		string getCampus();
		int getDateIn();
		int getDateOut();
		void print();
		
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
	dateIn = 0;
	dateOut = 0;
}

// Overloaded Constructor -------------------------------------------------
Form::Form(bool Vacc_Status, bool CovidTest, string Vacc_Type, string campus, int dateIn, int dateOut)
{
	this -> Vacc_Status = Vacc_Status;
	this -> CovidTest = CovidTest;
	this -> Vacc_Type= Vacc_Type;
	this -> campus = campus;
	this -> dateIn = dateIn;
	this -> dateOut = dateOut;
}

// Mutators  ------------------------------------------------------------
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
		
void Form::setDateIn(int dateIn)
{	
	this -> dateIn = dateIn;
}
		
void Form::setDateOut(int dateOut)
{	
	this -> dateOut = dateOut;
}

void Form::setStudentInfo(string name, int ID, int year, string school, string programme, bool status, long int phone, string email)
{
	for (int i =0; i<size; i++)
	{
		stud[i].setName(name);
		stud[i].setID(ID);
		stud[i].setYear(year);
		stud[i].setSchool(school);
		stud[i].setProgramme(programme);
		stud[i].setStatus(status);
		stud[i].setPhone(phone);
		stud[i].setEmail(email);
	}
}

// Accessors -----------------------------------------------------------------
bool Form::getVacc_Status()
{
	return  this->Vacc_Status;
}
		
bool Form::getCovidTest()
{
	return  this->CovidTest;
}
		
string Form::getVacc_Type()
{
	return  this->Vacc_Type;
}
		
string Form::getCampus()
{
	return  this->campus;
}
		
int Form::getDateIn()
{
	return  this->dateIn;
}
		
int Form::getDateOut()
{
	return  this->dateOut;
}
		
void Form::print()
{
	for (int i =0; i<size; i++)
	{
		if (stud[i].getStatus()==false)
		{
			stud[i].print();
			
			cout << "Vaccine Status: " << getVacc_Status() <<endl;
			cout << "Covid Test Results: " << getCovidTest() <<endl;
			cout << "Vaccine Type (first booster): " << getVacc_Type() <<endl;
			cout << "USM Campus: " << getCampus() <<endl;
			cout << "Date In: " << getDateIn() <<endl;
			cout << "Date Out: " << getDateOut() <<endl;
			
			system("pause");
		}
		else
		{
			cout << stud[i].getName() <<" tested positive for Covid-19. Stay is not allowed." <<endl;
			
			system("pause");
		}
	}

}

// Destructor -----------------------------------------------------------
Form::~Form(){};


#endif
