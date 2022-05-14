// Name of Pragrammers: Lee Ying Hooi, Looi Wei En, Wong Jia Yi
// Date Created: May 2022
// Purpose of the program: *insert here*
// This is the main function.
#include <iostream> 
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Student.h"
#include "Form.h"

using namespace std;

int main()
{
	// Refer variable definition in report for more intormation
	int linecount=0;
	string line;
	
	bool Vacc_Status, CovidTest, status;
	string Vacc_Type, campus, name, NRIC, school, programme, email;
	int dayIn, monthIn, yearIn, year; 
	long int ID; 
	long long int phone;
	
	int count=1;
	
	int total_fee=0;

	
	ifstream inputFile;
	inputFile.open("Student.txt");
	
	
	if(!inputFile) // file input validation
	{
		cout << "Error loading file!!";
		exit(1);
	}
	else
	{
		while (!inputFile.eof()) // While loop to count the number of lines of the input file
		{
			getline(inputFile, line, '\n');
			linecount ++;
			if (inputFile.eof())
			{
				break;
			}
		}
	}
	
	
	inputFile.clear();
	inputFile.seekg(0, ios::beg); // Go back to the beginning of the text file
	
	Form obj[linecount+1];
	
	// Store data from text file to program variables
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
	    obj[i].createDynamicArray(linecount); // create stud array from class Student
		obj[i].setStudentInfo(i, name, NRIC, ID, year, school, programme,status, phone, email);
		obj[i].calcDurationBill();
	}
	
	inputFile.close();
	
	
	
	
	
	
	// Display the details of each student
	for (int j = 0; j<linecount; j++)
	{
		obj[j].print(j);
		system("CLS");
	}
	
	// Obtain the iteration of the students with approved stay
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
	
	
	// Display the list of students with approved stay
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
	
	// Find the average hostel fees from all students 
	for (int i = 0; i<linecount; i++)
	{
		if(list[i]==1)
		{
			total_fee+=obj[i].getFee();
		}
	}
	obj[linecount+1].setFee(total_fee);
	cout << "Average hostel fee received by students: RM"<< obj[linecount+1]/(count-1);


	// Export the list of students with approved stay
	ofstream outputFile;
	outputFile.open("List of Students Staying in Hostel.txt");
	
	count=1;
	for (int i = 0; i<linecount; i++)
	{
		if(list[i]==1)
		{
			outputFile << "Student "<<count <<": " <<obj[i].getName(i) <<"\tRM" <<obj[i].getFee() <<"\t" 
					   << obj[i].getDuration() <<" days\t" <<obj[i].getCampus() <<endl;
			count++;
		}
	}
	
	outputFile.close();
	
	return 0;
}
