#include "person.h"
#include "person.cpp"
#include <vector>
#include <string>
#include <fstream>
#include "iostream"
#include <iomanip>

using namespace std;

void readData(vector<Person> &Empvect);
void getCompanies(vector<Person> &Empvect,vector<string> &compVect);
void PrintHighestPaid(vector<Person> &Empvect);
void seperateAndSave(vector<Person> &Empvect,vector<string> &compVect);


int main()
{

vector<Person> employees;
vector<string> companyNames;

readData(employees);
getCompanies(employees,companyNames);
PrintHighestPaid(employees);

seperateAndSave(employees, companyNames);


}

void readData(vector<Person> &Empvect)
{

Person s;
fstream myfile;
myfile.open("input.txt");
string Fname;
string Lname;
int id;
string compName;
float hours;
float payrate;

if (!myfile.is_open())
{
cout << "File is not found" << endl;

}

else 
{

while (!myfile.eof())
{

myfile >> Fname >> Lname >> id >> compName >> hours >> payrate;
s.setFirstName(Fname); s.setLastName(Lname); s.setEmployeeId(id);
s.setCompanyName(compName);s.setHoursWorked(hours); s.setPayRate(payrate);

Empvect.push_back(s);

}
myfile.close();

}


}

void getCompanies(vector<Person> &Empvect,vector<string> &compVect)
{

for (unsigned int i = 0; i < Empvect.size(); i++)

{

compVect.push_back(Empvect.at(i).getCompanyName());

}
}



void PrintHighestPaid(vector<Person> &Empvect)
{

int counter = 0;
int id;
string coName;
string empName;
float total;
cout << showpoint;
for (unsigned int i = 0; i < Empvect.size(); i++)
{

if (counter < Empvect.at(i).totalPay())
{

counter = Empvect.at(i).totalPay();
id =  Empvect.at(i).getEmployeeId();
coName = Empvect.at(i).getCompanyName();
empName = Empvect.at(i).fullName();
total = Empvect.at(i).totalPay();

}




}

cout << "Highest paid: " << empName << endl;
cout << "Employee ID: " << id << endl;
cout << "Employer: " << coName << endl;
cout << "Total Pay: $" << total <<endl;

}


void seperateAndSave(vector<Person> &Empvect,vector<string> &compVect){
string name;

for (unsigned int i = 0; i < compVect.size();i++)
{
float totalpay = 0;
name = compVect.at(i);



ofstream outputfile (name+".txt");
ifstream inputfile;

inputfile.open(name+".txt");

outputfile <<"Company: "<< name << ".txt"<< endl;
outputfile << "___________________________________________________________________" << endl;

for (unsigned int i = 0; i < Empvect.size()-1; i++)
{

if (name == Empvect.at(i).getCompanyName())
{
outputfile << showpoint;
outputfile << setw(20)<< left << Empvect.at(i).fullName() << setw(20) << right << Empvect.at(i).getEmployeeId() << right << setw(20) << Empvect.at(i).getCompanyName() << right << setw(20) << "$" << Empvect.at(i).totalPay() << endl;
 
totalpay += Empvect.at(i).totalPay();

}


}
outputfile << "\nTotal Pay: $"<< totalpay;
outputfile.close();

}



 
 


}
