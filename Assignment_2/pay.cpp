//Wesley Friday
//CPSC301 - 3
#include <iostream>
#include <string>
#include "person.cpp"
#include <fstream>
#include <vector>
using namespace std;

void readData(vector <Person> &p);
void writeData(vector <Person> &p);

int main() {
  vector <Person> person;
  readData(person);
  writeData(person);

  return 0;
};

//READ DATA
void readData(vector <Person> &p)
{
  fstream filein;
  filein.open("input.txt");
  string lastname;
  string firstname;
  float  payrate;
  float  hoursworked;

while (filein >> firstname >> lastname >> hoursworked >> payrate) {

  p.emplace_back(firstname, lastname, hoursworked, payrate);
}
filein.close();
}

//WRITE DATA
void writeData(vector <Person> &p)
{
ofstream fileout;
fileout.open("input.txt");

for (int i = 0; i < p.size(); i++)
	{
		fileout << p.at(i).fullName() << "  $" << p.at(i).totalPay() << endl;
	};
  fileout.close();
};
