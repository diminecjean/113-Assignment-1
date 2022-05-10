#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Student
{
 	private:
		string name, NRIC, school, programme, email;
		long int ID;
		long long int phone;
		int year;
		bool status;
		
	public:
		// default constructor
		Student();
		
		// overloaded constructor
		
		
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
		
		
		// Accessors
		string getName();
		string getNRIC();
		long int getID();
		int getYear();
		string getSchool();
		string getProgramme();
		string getStatus();
		long long int getPhone();
		string getEmail();
		void print();
		
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




// Mutators  ------------------------------------------------------------
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

// Accessors -----------------------------------------------------------------
string Student::getName()
{
	return name;
}

string Student::getNRIC()
{
	return NRIC;
}

long int Student::getID()
{
	return ID;
}

int Student::getYear()
{
	return year;
}

string Student::getSchool()
{
	return school;
}

string Student::getProgramme()
{
	return programme;
}

string Student::getStatus()
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

long long int Student::getPhone()
{
	return phone;
}

string Student::getEmail()
{
	return email;
}

void Student::print()
{
	cout << "Name: " << getName() <<endl;
	cout << "NRIC: " << getNRIC() <<endl;
	cout << "Student ID: " << getID() <<endl;
	cout << "Year: " << getYear() <<endl;
	cout << "School: " << getSchool() <<endl;
	cout << "Programme: " << getProgramme() <<endl;
	cout << "Status: " << getStatus() <<endl;
	cout << "Phone: " << getPhone() <<endl;
	cout << "Email: " << getEmail() <<endl;
}

// Destructor -----------------------------------------------------------
Student::~Student(){};


#endif
