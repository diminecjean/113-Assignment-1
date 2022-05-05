# UML Diagram

|Student|
|--|
|-name:string <br> <br> -NRIC:long long int <br> -ID:long int <br> -year:int <br> -school:string <br> -programme:string <br> -status:bool <br> -phone:long int <br> -email:string|
|Student():void<br>setName(string):void<br>setID(int):void<br>setYear(int):void<br>setSchool(string):void<br>setProgramme(string):void<br>setStatus(bool):void<br>setCGPA(float):void<br>getName():string<br>getID():long int<br>getYear():int<br>getSchool():string<br>getProgramme():string<br>getStatus():bool<br>getCGPA():float|

*haven't add +/-/# <br>
*referred to campus online main page

|Form|
|--|
|-Vacc_Status:bool <br> -Vacc_Type:string <br> -campus:string <br> -CovidTest:bool <br> -dateIn:int <br> -dateOut:int|
||


// Can do friend function to Form
|Bill|
|--|
|-duration:int <br> -total_fee:double|
||


// Can do class CGPA - calculate whether eligible for student loans/scholarships
