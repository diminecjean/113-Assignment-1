#include <iostream> 
#include <fstream>
#include <string>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include "Student.h"
#include "Form.h"

using namespace std;

int main()
{
	int linecount=0;
	string line;
	
	ifstream inputFile;
	inputFile.open("Student.txt");
	
	// While loop to count the number of lines of the input file
	while (!inputFile.eof())
	{
		getline(inputFile, line, '\n');
		linecount ++;
		if (inputFile.eof())
		{
			break;
		}
	}
	
	inputFile.clear();
	inputFile.seekg(0, ios::beg);
	
	bool Vacc_Status, CovidTest, status;
	string Vacc_Type, campus, name, NRIC, school, programme, email;
	int dayIn, monthIn, yearIn, year; 
	long int ID; 
	long long int phone;
	
	Form obj[linecount];
	
	for (int i=0; i<linecount; i++)
	{
		inputFile >> Vacc_Status >> CovidTest >> status;
		inputFile.ignore();
		
		getline(inputFile, Vacc_Type, '\t');
		getline(inputFile, campus, '\t');
		getline(inputFile, name, '\t');
		getline(inputFile, NRIC, '\t');
		getline(inputFile, school, '\t');
		getline(inputFile, programme, '\t');
		getline(inputFile, email, '\t');
		
		inputFile >> dayIn >>monthIn >> yearIn >> year >> ID >> phone;
		
	    obj[i].setForm(Vacc_Status, CovidTest, Vacc_Type, campus, dayIn, monthIn, yearIn);
	    obj[i].setIterationNSize(i, linecount); 
	    obj[i].createDynamicArray(linecount);
		obj[i].setStudentInfo(i, name, NRIC, ID, year, school, programme,status, phone, email);
		obj[i].calcDurationBill();
	}
	
	for (int j = 0; j<linecount; j++)
	{
		obj[j].print(j);
		system("CLS");
	}
	
	int list[linecount];
	for (int j = 0; j<linecount; j++)
	{
		if (obj[j].getStayApprove() == true)
		{
			list[j]=1;
		}
		else
		{
			list[j]=0;
		}
	}
	
	
	int count=1;
	
	cout << "List of students in campus:" <<endl;
	for (int i = 0; i<linecount; i++)
	{
		if(list[i]==1)
		{
			cout << count << ". ";
			obj[i].List(i);
			count++;
		}
	}
	
	
	return 0;
}
