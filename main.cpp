#include <iostream> 
#include <string>
#include "Student.h"
#include "Form.h"

using namespace std;

int main()
{
	int num = 3;
	
	Form obj[num];
	
	obj[0].setForm (true, true, "AZ", "Main Campus", 4,5);
	obj[0].setStudentInfo("Looi Wei En", "021009070068", 159163, 1, "Universiti Sains Malaysia", "Computer Science",true,60135883813,"looi.weien02@gmail.com");
	obj[0].print();
	
	obj[1].setForm (true, false, "Pfizer", "Engineering Campus", 13,30);
	obj[1].setStudentInfo("Wong Jia Yi", "021009070068", 159163, 2, "Universiti Sains Malaysia", "Computer Science",false,60135883813,"looi.weien02@gmail.com");
	obj[1].print();
	
	obj[2].setForm (false, true, "Sinovac", "Heatlh Campus", 2,15);
	obj[2].setStudentInfo("Lee Ying Hooi", "021009070068", 159163, 1, "Universiti Sains Malaysia", "Computer Science",true,60135883813,"looi.weien02@gmail.com");
	obj[2].print();
	
	return 0;
}
