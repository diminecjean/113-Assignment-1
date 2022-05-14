// Class to store, calculate and display information for hostel stay
#ifndef FORM_H
#define FORM_H

#include "Student.h"
#include "Bill.h"
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

class Form 
{
	private:
		// Refer variable definition in report for more intormation
		int i, dayIn, monthIn, yearIn, size, duration, fee;
		Student *stud; // object from class Student
		Bill d; // Object from class Bill
		bool Vacc_Status, CovidTest, stay_approve;
		string Vacc_Type, campus;
		
	public:
		// Default constructor
		Form();
		
		// Overloaded constructor
		Form (bool, bool, string, string, int, int,int);
		
		// Mutators
		void createDynamicArray(int);
		
		void setIterationNSize(int, int);
		void setVacc_Status(bool);
		void setCovidTest(bool);
		void setVacc_Type(string);
		void setCampus(string);
		void setDuration(int);
		void setFee(int);
		void setStayApprove(bool stay);
		void setDateInCampus (int, int, int);
		void setStudentInfo(int, string, string, int, int, string, string, bool, long long int, string);
		void setForm (bool, bool, string, string, int, int, int);
		
		void deleteArray();
		
		void calcDurationBill ();
		void print(int);
		void List(int i);
		
		friend float operator / (Form, int); // operator oveloading friend function
		
		// Accesors
		string getVacc_Status()const;
		string getCovidTest()const;
		string getVacc_Type()const;
		string getCampus()const;
		string getName(int)const;
		bool getStayApprove()const;
		int getDayIn()const;
		int getMonthIn()const;
		int getYearIn()const;
		int getFee()const;
		int getDuration()const;
		

		
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
Form::Form(bool Vacc_Status, bool CovidTest, string Vacc_Type, string campus, int dayIn, int monthIn, int yearIn)
{
	this -> Vacc_Status = Vacc_Status;
	this -> CovidTest = CovidTest;
	this -> Vacc_Type= Vacc_Type;
	this -> campus = campus;
	this -> dayIn = dayIn;
	this -> monthIn = monthIn;
	this -> yearIn = yearIn;
}

// Mutators  ------------------------------------------------------------
void Form::createDynamicArray(int size) // create array for obj stud of class Student
{
   stud = new Student [size];
}

void Form::setIterationNSize(int i, int size) // set the iteration and size used by the object array in function main
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

void Form::setDuration(int duration)
{	
	this -> duration = duration;
}

void Form::setFee(int fee)
{	
	this -> fee = fee;
}

void Form::setStayApprove(bool stay)
{
	stay_approve = stay;
}
		
void Form::setDateInCampus (int day, int month, int year)
{
	dayIn = day;
	monthIn = month;
	yearIn = year;
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

void Form::calcDurationBill ()
{
	d.setDateIn(dayIn,monthIn,yearIn);
	duration = d.calcDuration();
	fee = d.calcTotalFee();
}
		
void Form::print(int i) // display student info 
{
	if (stud[i].getStatus()=="Active"&& getCovidTest() == "Negative" )
	{
		setStayApprove(true);
		stud[i].print(i);
		
	
		cout << "---------------------------------------------------------------------------------------------" <<endl;
		cout << "Hostel Application Form Details " << i+1 <<endl;
		cout << "---------------------------------------------------------------------------------------------" <<endl;
		cout << "Vaccination Status\t: " << getVacc_Status() <<endl;
		cout << "Covid Test Results\t: " << getCovidTest() <<endl;
		if (getVacc_Status()=="Unvaccinated")
		{
			cout << "1st Booster Type\t: -" <<endl;
		}
		else
		{
			cout << "1st Booster Type\t: " << getVacc_Type() <<endl;
		}
		cout << "University Campus\t: " << getCampus() <<endl;
		cout << "Duration of Stay\t: " <<duration <<" days" <<endl;
		cout << "Total Hostel Fees\t: RM" <<fee <<endl;
		
		system("pause");
		system("CLS");
	}
	else if (stud[i].getStatus()=="Inactive" && getCovidTest() == "Positive")
	{
		setStayApprove(false);
		stud[i].print(i);
		cout << "\n\n";
		cout << "---------------------------------------------------------------------------------------------" <<endl;
		cout << stud[i].getName() <<" is not an active student in USM and has tested positive for Covid-19. \nStay not permitted." <<endl;
		cout << "---------------------------------------------------------------------------------------------" <<endl;
		system("pause");
		system("CLS");
	}
	else if (getCovidTest() == "Positive")
	{
		setStayApprove(false);
		stud[i].print(i);
		cout << "\n\n";
		cout << "---------------------------------------------------------------------------------------------" <<endl;
		cout << stud[i].getName() <<" has tested positive for Covid-19. \nStay not permitted." <<endl;
		cout << "---------------------------------------------------------------------------------------------" <<endl;
		system("pause");
		system("CLS");
	}
	else if (stud[i].getStatus()=="Inactive")
	{
		setStayApprove(false);
		stud[i].print(i);
		cout << "\n\n";
		cout << "---------------------------------------------------------------------------------------------" <<endl;
		cout << stud[i].getName() <<" is not an active student in USM. \nStay not permitted." <<endl;
		cout << "---------------------------------------------------------------------------------------------" <<endl;
		system("pause");
		system("CLS");
	}

}

void Form::List(int i)
{
	cout << stud[i].getName() <<",\tRM" <<getFee() <<",\t" <<getDuration() <<" days, \t" <<getCampus() <<endl;
}


float operator /(Form ob, int div)
{
	return ((ob.fee)/div);

}	



// Accesors -------------------------------------------------------------------------------------------------------------------------------------------
string Form::getVacc_Status()const
{
	if (Vacc_Status == 1)
	{
		return "Vaccinated";
	}
	else if (Vacc_Status == 0)
	{
		return "Unvaccinated";
	}
}
		
string Form::getCovidTest()const
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
		
string Form::getVacc_Type()const
{
	return  this->Vacc_Type;
}
		
string Form::getCampus()const
{
	return  this->campus;
}

string Form::getName(int i)const
{
	return stud[i].getName();
}

bool Form::getStayApprove()const
{
	return  this->stay_approve;
}
		
int Form::getDayIn()const
{
	return  this->dayIn;
}
		
int Form::getMonthIn()const
{
	return  this->monthIn;
}

int Form::getYearIn()const
{
	return  this->yearIn;
}

int Form::getDuration()const
{
	return  this->duration;
}

int Form::getFee()const
{
	return  this->fee;
}



// Destructor ------------------------------------------------------------------------------------------------------------------------------------------
Form::~Form(){};


#endif
