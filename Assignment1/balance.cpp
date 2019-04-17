//Wesley Friday
//CPSC301 - 3

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Struct
struct  PERSON {
    char  Name[20];
    float Balance;
  };

//Function Protypes
void Display(PERSON *p, int count);
void FindtheRiches(PERSON *p, int count);
void Deposit(string name, PERSON *p, int count);
PERSON *readData(int &N);
void NewCopy(PERSON* p, int count);

//Main
int main() {

    fstream filein;
    filein.open("data.txt");
    int count = 6;
    string user;

//Getting the Count
    // while(!filein.eof() )
    // {
    //   string u;
    //   getline(filein, u);
    //   count++;
    // };
filein.close();


PERSON* per = new PERSON[count];
per = readData(count);




  Display(per,count);
  FindtheRiches(per, count);
  //User Input
  cout << "Please insert name:  ";
  getline(cin, user);
  Deposit(user,per, count);
  //NewCopy(per, count);

    return 0;
}

//Display the Array
void Display(PERSON* p, int count)
{
  cout << "Name       Balance" << endl << "--------------"<< endl;

  for(int i = 0; i < count; i++)
  {
    cout << p[i].Name << "       $" << p[i].Balance << endl;
  }

};

//Find the Richest
void FindtheRiches(PERSON * p, int count)
{
float richest = 0;
string richperson;

  for(int i = 0; i < count; i++)
  {
    if(p[i].Balance < p[i + 1].Balance)
    { richest = p[i + 1].Balance; richperson = p[i + 1].Name;}
  };
cout << "The richest person is " << richperson << endl << endl;
};

//Deposit Function
void Deposit(string name,PERSON * p, int count)
{
  float bal = 0.0;
  int num;

  for(int i = 0; i < count; i++)
  {
    strcmp(name.c_str(), p[i].Name);
    if (name == p[i].Name){num = i;};
  };

    if(name == p[num].Name)
    {
      cout << "Enter how much you want to deposit?: ";
      cin >> bal;
      p[num].Balance += bal;
      cout << p[num].Name << " your new balance is " << p[num].Balance << endl;
    }

};

// void NewCopy(PERSON * p, int count)
// {
//   fstream out;
//   out.open("data.txt");
//   out << p->Name << p[count].Balance << endl;
//   out.close();
// };



PERSON *readData(int &N)
{
PERSON* person = new PERSON[N];
ifstream filein;
filein.open("data.txt");
string fname, lname;
string fulName;
int t = 0;


while (filein && t < N)
{
filein >> fname >> lname >> person[t].Balance;
fulName = fname + " " + lname;
strcpy(person->Name, fulName.c_str());
cout << fname << person->Balance << endl;
t++;

}

  filein.close();
  return person;
};
