// Class to store and print student details
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Student
{
 	private:
 		// Refer variable definition in report for more intormation
		string name, NRIC, school, programme, email;
		long int ID;
		long long int phone;
		int year,i;
		bool status;
		
	public:
		// default constructor
		Student();
		
		// overloaded constructor
		Student (string, string, int, int);
		
		// Mutators
		void setName(string);
		void setNRIC (string);
		void setID(int);
		void setYear(int);
		void setSchool(string);
		void setProgramme(string);
		void setStatus(bool);
		void setPhone(long long int);
		void setEmail(string);
		void setInfo(string, string, int, int, string, string, bool, long long int, string);
		void print(int);
		
		// Accessors
		string getName()const;
		string getNRIC()const;
		long int getID()const;
		int getYear()const;
		string getSchool()const;
		string getProgramme()const;
		string getStatus()const;
		long long int getPhone()const;
		string getEmail()const;
		
		// Destructor
		~Student();
};

// Default Constructor -------------------------------------------------
Student::Student()
{
	name = "";
	school = "";
	programme = "";
	ID = 0;
	NRIC="";
	year = 0;
	status = false;
	phone = 0;
	email = "";
}

// Overloded Constructor---------------------------------------------------------------------------------------------------------------------------------
Student::Student(string name, string school, int ID, int year)
{
	this->name = name;
	this->school = school;
	this->year = year;
	this->ID = ID;
	programme = "";
	NRIC="";
	status = false;
	phone = 0;
	email = "";
}
	

// Mutators ---------------------------------------------------------------------------------------------------------------------------------
void Student::setName(string name)
{
	this-> name = name;
}

void Student::setNRIC(string NRIC)
{
	this-> NRIC = NRIC;
}

void Student::setID(int ID)
{
	this-> ID = ID;
}

void Student::setYear(int year)
{
	this-> year = year;
}

void Student::setSchool(string school)
{
	this-> school = school;
}

void Student::setProgramme(string programme)
{
	this-> programme = programme;
}

void Student::setStatus(bool status)
{
	this-> status = status;
}

void Student::setPhone(long long int phone)
{
	this-> phone = phone;
}

void Student::setEmail(string email)
{
	this-> email = email;
}

void Student::setInfo(string name, string NRIC, int ID, int year, string school, string programme, bool status, long long int phone, string email)
{
		setName(name);
		setNRIC(NRIC);
		setID(ID);
		setYear(year);
		setSchool(school);
		setProgramme(programme);
		setStatus(status);
		setPhone(phone);
		setEmail(email);
} 

void Student::print(int i)
{
	cout << "---------------------------------------------------------------------------------------------" <<endl;
	cout << "Student Details " <<i+1 <<endl;
	cout << "---------------------------------------------------------------------------------------------" <<endl;
	cout << "Name\t: " <<left <<setw(12)<< getName() << "\t\t\tProgramme\t: " <<left <<setw(12)<< getProgramme()  <<endl;
	cout << "NRIC\t: " <<left <<setw(12)<< getNRIC() << "\t\t\tStud. Status\t: " <<left <<setw(12)<< getStatus() <<endl;
	cout << "ID\t: " <<left <<setw(12)<< getID() << "\t\t\tPhone No.\t: " <<left <<setw(12)<< getPhone() <<endl;
	cout << "Year\t: " <<left <<setw(12)<< getYear() << "\t\t\tEmail Add.\t: " <<left <<setw(12)<< getEmail() <<endl;
	cout << "School\t: " <<left <<setw(12)<< getSchool() <<endl;
	cout << "\n\n\n";
}

// Accessors -----------------------------------------------------------------
string Student::getName()const
{
	return name;
}

string Student::getNRIC()const
{
	return NRIC;
}

long int Student::getID()const
{
	return ID;
}

int Student::getYear()const
{
	return year;
}

string Student::getSchool()const
{
	return school;
}

string Student::getProgramme()const
{
	return programme;
}

string Student::getStatus()const
{
	if (status == 0)
	{
		return "Inactive";
	}
	else if (status == 1)
	{
		return "Active";
	}
}

long long int Student::getPhone()const
{
	return phone;
}

string Student::getEmail()const
{
	return email;
}



// Destructor -----------------------------------------------------------
Student::~Student(){};


#endif
