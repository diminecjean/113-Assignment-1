#ifndef STUDENT_H
#define STUDENT_H


#include<iomanip>
#include<string>

class Student
{
	// scope of variables and function operations can be changed
	private:
		string name, school, programme, email;
		long int ID, phone;
		int year;
		bool status;
		
	public:
		// default constructor
		Student();
		
		// overloaded constructor
		
		// Mutators
		void setName(string);
		void setID(int);
		void setYear(int);
		void setSchool(string);
		void setProgramme(string);
		void setStatus(bool);
		void setPhone(long int);
		void setEmail(string);
		
		// Accessors
		string getName();
		long int getID();
		int getYear();
		string getSchool();
		string getProgramme();
		bool getStatus();
		long int getPhone();
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

void Student::setPhone(long int phone)
{
	this-> phone = phone;
}

void Student::setEmail(string email)
{
	this-> email = email;
}

// Accessors -----------------------------------------------------------------
string Student::getName()
{
	return name;
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

bool Student::getStatus()
{
	return status;
}

long int Student::getPhone()
{
	return phone;
}

string Student::getEmail()
{
	return email;
}

void Student::print()
{
	// idk bout this yet
}

// Destructor -----------------------------------------------------------
~Student::Student(){};


#endif
