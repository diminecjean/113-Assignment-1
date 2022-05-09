#include <iostream> 
#include <string>
#include "Student.h"
#include "Form.h"

using namespace std;

int main()
{
	Form obj (true, true, "AZ", "main", 4,5);
	obj.setStudentInfo("Looi Wei En", 159163, 1, "Universiti Sains Malaysia", "Computer Science",true,60135883813,"looi.weien02@gmail.com");
	
	obj.print();
	
	return 0;
}
