#include <iostream>
using namespace std;

class Duration
{
	private:
	int day,month,year;
	
	public:
	Duration (){};  // Default Constructor
	Duration (int,int,int); // Overloaded Constructor
	void setDuration(); // Mutator
	void getDuration(); // Accesor1
	int getDay(){return day;} // Accesor2
	int getMonth(){return month;} // Accesor3
	int getYear(){return year;} // Accesor4
	friend Duration operator -(Duration,Duration);	// Accesor5
	void print() // Accesor 6
	{
		cout <<"Day: " <<day<<endl;
		cout <<"Month: "<<month<<endl;
		cout <<"Year: "<<year<<endl;
	}
	
};
	

Duration::Duration(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

void Duration :: setDuration()
{
	day = 10;
	month = 2;
	year = 22;
}


void Duration :: getDuration()
{
	cout<< day <<"\n";
	cout<< month <<"\n";
	cout<< year <<"\n";
}


//Definition of overloaded binary minus operator - friend function
Duration operator -(Duration ob2, Duration ob1)
{
	Duration result;
	result.day = ob2.day - ob1.day;
	result.month = ob2.month - ob1.month;
	result.year = ob2.year - ob1.year;
	

	return result;
}


int main()
{
	Duration obj1(12,3,22);
	Duration obj2(23,4,22);
	
	Duration obj3;
	obj3 = obj2-obj1;
	
	obj3.print();
	
	return 0;
}


