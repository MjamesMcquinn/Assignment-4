
/*

Matthew McQuinn
mmcquinn2021@fit.edu

Write an application(including algorithm) that uses an input file to process the payroll of a company.
The file format includes a record for each employee that contains the following information
(each field separated by colon)

•	First Name
•	Last Name
•	Street Address
•	City
•	Employee ID
•	Pay Rate
•	Hour Worked
•	Wages

The application must read the file of recordsand store the information in an array of structures
(maximum size of each array will be 100 entries).
Therefore the application must be designed to support a file that contains a maximum of 100 employees.
In addition, the “wages” field must be used to store the salary of each employee.
The wages are calculated based on the following logic.



If Hours Worked <= 40
Wage = Pay Rate * Hours Worked
Else
Wage = Pay Rate * 40 + ((Hours Worked – 40) * Pay Rate * 1.5)



The application must display all the array information(tabular format) 
for each record, in sorted order, based on the employee wagesand display
the total of all of the employee wages at the bottom of the table.


Upload to the Canvas “Assignment 4 Submission” area.


Note: The application must read all records of the file by using the technique of testing for the end - of - file
(i.e., cannot prompt user for the number of records in the file).
In addition, the application must be designed to handle strings that contain spaces.

Algorithm:










Sample
Alan:Colllins:113 Amber Way:Orlando:17:12.75:73
Cindy:Davis:11 Oak Street:Melbourne:210:13.67:45
Eilein:Ferguson:75 Allen Drive:Jacksonville:62:53.36:17



*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE = 100;

struct CompanyPayroll
{
    string firstName;
    string lastName;
    string streetAddress;
    string cityName;
    string employeeID;

    string payRate;
    string hoursWorked;
    double wages=0;
    double dhoursWorked;
    double dpayRate;
    double dID;

};


void bubbleSort(CompanyPayroll arr[], int length);

int main()
{
    CompanyPayroll payroll[SIZE];

    ifstream inFile;
    inFile.open("Sample.txt");
    string next;
    

    int index = 0;
   do  {

       


        getline(inFile, payroll[index].firstName, ':');

        getline(inFile, payroll[index].lastName, ':');

        getline(inFile, payroll[index].streetAddress, ':');

        getline(inFile, payroll[index].cityName, ':');

        getline(inFile, payroll[index].employeeID, ':');

        getline(inFile, payroll[index].payRate, ':');

        getline(inFile, payroll[index].hoursWorked, '\n');

        double tempPayrate =  stod(payroll[index].payRate);
         double tempHoursworked = stod(payroll[index].hoursWorked);
         double dID = stod(payroll[index].employeeID);

         payroll[index].dpayRate=tempPayrate;
         payroll[index].dhoursWorked=tempHoursworked;
         payroll[index].dID = dID;


         if (inFile.peek() == EOF) 
             inFile.get();
        

      
      
         index++;
      
            


   } while (inFile.eof() == false);
   
   


   for (int i = 0; i < SIZE; i++){

       if (payroll[i].dhoursWorked <= 40)
           payroll[i].wages = payroll[i].dpayRate * payroll[i].dhoursWorked;
       else
           payroll[i].wages = payroll[i].dpayRate * 40 + ((payroll[i].dhoursWorked - 40) * payroll[i].dpayRate * 1.5);
       
   }

   bubbleSort(payroll, SIZE);
  
   for (int i = 0; i < SIZE; i++) {
       if (payroll[i].dID < 8.56729e+123)
           cout << payroll[i].firstName << " " << payroll[i].lastName << " " << payroll[i].streetAddress << " " << payroll[i].cityName << " " << payroll[i].employeeID << " " << payroll[i].payRate << " " << payroll[i].hoursWorked << " " << payroll[i].wages << endl;
   }

  // If Hours Worked <= 40
    //   Wage = Pay Rate * Hours Worked
      // Else
       //Wage = Pay Rate * 40 + ((Hours Worked – 40) * Pay Rate * 1.5)

    
}
   
void bubbleSort(CompanyPayroll arr[], int length)
{
    CompanyPayroll temp;
    // 5 for example below
    for (int i = length - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j].wages > arr[j + 1].wages)
            {
                //Swap the numbers
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
    
    


   

