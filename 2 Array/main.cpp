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
//	cout << "Please enter your file name: " <<endl;
//  getline (cin,filename);
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
	int dateIn, dateOut, year; 
	long int ID; 
	long long int phone;
	
	Form obj[linecount];
	
//	cout << linecount <<endl;
	
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
		
		inputFile >> dateIn >> dateOut >> year >> ID >> phone;
		
	    obj[i].setForm(Vacc_Status, CovidTest, Vacc_Type, campus, dateIn, dateOut);
	    obj[i].setIterationNSize(i, linecount); 
	    obj[i].createDynamicArray(linecount);
		obj[i].setStudentInfo(i, name, NRIC, ID, year, school, programme,status, phone, email);
		
	}
	
	for (int j = 0; j<linecount; j++)
	{
		obj[j].print(j);
		system("CLS");
	}
//	obj[0].setForm (true, true, "AZ", "Main Campus", 4,5);
//	obj[0].setStudentInfo("Looi Wei En", "021009070068", 159163, 1, "Universiti Sains Malaysia", "Computer Science",true,60135883813,"looi.weien02@gmail.com");
//	obj[0].print();
//	
//	obj[1].setForm (true, false, "Pfizer", "Engineering Campus", 13,30);
//	obj[1].setStudentInfo("Wong Jia Yi", "021009070068", 159163, 2, "Universiti Sains Malaysia", "Computer Science",false,60135883813,"looi.weien02@gmail.com");
//	obj[1].print();
//	
//	obj[2].setForm (false, true, "Sinovac", "Heatlh Campus", 2,15);
//	obj[2].setStudentInfo("Lee Ying Hooi", "021009070068", 159163, 1, "Universiti Sains Malaysia", "Computer Science",true,60135883813,"looi.weien02@gmail.com");
//	obj[2].print();
	
	return 0;
}
