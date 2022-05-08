#ifndef FORM_H
#define FORM_H

class Form
{
	// scope of variables and function operations still to be decided
	private
		Student stud;
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
}

void Form::print()
{
	if (stud.getStatus()=true)
	{
		//print information
	}
	else
	{
		//display error message
	}
}

#endif
