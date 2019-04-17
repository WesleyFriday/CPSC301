//Wesley Friday
//CPSC301 - 3
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "person.cpp"
#include <iomanip>

using namespace std;

//Function Protype
void readData(vector<Person> *v);
void getCompanies(vector<Person> *v, vector<string> *n);
void printHighestPaid(vector<Person> *v);
void separateAndSave(vector<Person> *v, vector<string> *n);


 int main(int argc, char const *argv[]) {
   vector<Person> employee;
   vector<string> companyNames;
   readData(&employee);
   getCompanies(&employee, &companyNames);
   printHighestPaid(&employee);
   separateAndSave(&employee ,&companyNames);

  return 0;
};


void readData(vector<Person> *v)
{
fstream filein;
string fname;
string lname;
int emploID;
string compname;
float time;
float prate;
filein.open("Input.txt");
Person p;

 for (int i = 0; i < 16; i++){
filein >> fname >> lname >> emploID >> compname >> time >> prate >> ws;

p.setFirstName(fname);
p.setLastName(lname);
p.setEmployeeId(emploID);
p.setCompanyName(compname);
p.setHoursWorked(time);
p.setPayRate(prate);

v->push_back(p);
};
filein.close();
};


void getCompanies(vector<Person> *v, vector<string> *n)
{
string c;

for (int i = 0; i < v->size(); i++)
{
c = v->at(i).getCompanyName();
n->push_back(c);


};
};


void printHighestPaid(vector<Person> *v){

float highest = 0;
float next;
int index = 0;


for (int i = 0; i < v->size(); i++)
{
 next = v->at(i).getPayRate();
 if(next > highest){ highest = next;};
};

for (int i = 0; i < v->size(); i++)
{
  if(highest == v->at(i).getPayRate()){ index = i; i = v->size();}
}

cout << "Highest Paid: " << v->at(index).fullName() << endl;
cout << "Employee ID: " << v->at(index).getEmployeeId() << endl;
cout << "Employer: " << v->at(index).getCompanyName() << endl;
cout << "Total Pay: $" << v->at(index).totalPay() << endl << endl<< endl<< endl<< endl<< endl;
};



void separateAndSave(vector<Person> *v, vector<string> *n)
{
  ofstream out1, out2, out3, out4, out5;
  float Btotal =0;
  float Dtotal =0;
  float Htotal =0;
  float Itotal =0;
  float Rtotal =0;

  //For Boeing
  out1.open("Boeing.txt");
  for (int i = 0; i < v->size(); i++)
  {
  if (v->at(i).getCompanyName() == "Boeing"){
  Btotal = Btotal + v->at(i).totalPay();
  out1 << v->at(i).fullName() << " " << v->at(i).getEmployeeId() << " " << v->at(i).getCompanyName() << " " << v->at(i).totalPay() << endl;
  }
  };
  out1 << "Total: $" << Btotal << endl << endl;
  out1.close();


  out2.open("Douglas.txt");
  for (int i = 0; i < v->size(); i++)
  {
  if (v->at(i).getCompanyName() == "Douglas"){
  Dtotal = Dtotal + v->at(i).totalPay();
  out2 << v->at(i).fullName() << " " << v->at(i).getEmployeeId() << " " << v->at(i).getCompanyName() << " " << v->at(i).totalPay() << endl;
  }
  };
  out2 << "Total: $" << Dtotal << endl << endl;
  out2.close();


  out3.open("HealthTech.txt");
  for (int i = 0; i < v->size(); i++)
  {
  if (v->at(i).getCompanyName() == "HealthTech"){
  Htotal = Htotal + v->at(i).totalPay();
  out3 << v->at(i).fullName() << " " << v->at(i).getEmployeeId() << " " << v->at(i).getCompanyName() << " " << v->at(i).totalPay() << endl;
  }
  };
  out3 << "Total: $" << Htotal << endl << endl;
  out3.close();



  out4.open("Intel.txt");
  for (int i = 0; i < v->size(); i++)
  {
  if (v->at(i).getCompanyName() == "Intel"){
  Itotal = Itotal + v->at(i).totalPay();
  out4 << v->at(i).fullName() << " " << v->at(i).getEmployeeId() << " " << v->at(i).getCompanyName() << " " << v->at(i).totalPay() << endl;
  }
  };
  out4 << "Total: $" << Itotal << endl << endl;
  out4.close();


  out5.open("Raytheon.txt");
  for (int i = 0; i < v->size(); i++)
  {
  if (v->at(i).getCompanyName() == "Raytheon"){
  Rtotal = Rtotal + v->at(i).totalPay();
  out5 << v->at(i).fullName() << " " << v->at(i).getEmployeeId() << " " << v->at(i).getCompanyName() << " " << v->at(i).totalPay() << endl;
  }
  };
  out5 << "Total: $" << Rtotal << endl << endl;
  out5.close();
};
