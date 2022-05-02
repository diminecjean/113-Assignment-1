#ifndef STUDENT_H
#define STUDENT_H


#include<iomanip>
#include<string>

class Student
{
	// scope of variables and function operations can be changed
	private:
		string name, school, programme;
		long int ID;
		int year;
		bool status;
		float CGPA;

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
		void setCGPA(float);
		
		// Accessors
		string getName();
		long int getID();
		int getYear();
		string getSchool();
		string getProgramme();
		bool getStatus();
		float getCGPA();
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
	CGPA = 0.0;
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

void Student::setCGPA(float CGPA)
{
	this-> CGPA = CGPA;
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

float Student::getCGPA()
{
	return CGPA;
}

void Student::print()
{
	// idk bout this yet
}

// Destructor -----------------------------------------------------------
~Student::Student(){};


#endif
