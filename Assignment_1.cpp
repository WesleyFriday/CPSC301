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
void Display(PERSON arr[], int count);
void FindtheRiches(PERSON arr[], int count);
void Deposit(string name, PERSON arr[], int count);

//Main
int main() {
    fstream filein;
    ofstream fileout;
    filein.open("data.txt");
    string fname, lname, n;
    float balance;
    //Getting the count
    int count = 0;
    string user;

    string u;
    while(getline(filein, u) )
    {
      count++;
    };

PERSON people[count];

filein.close();

filein.open("data.txt");
    for (int i = 0; i < count; i++)
	{
    filein >> fname;
    filein >> lname;
    filein >> balance;
    filein >> ws;
    n = fname + " " + lname;

    strcpy(people[i].Name, n.c_str());
    people[i].Balance = balance;

  };

  Display(people, count);
  FindtheRiches(people, count);

  cout << "Please insert name:  ";
  getline(cin, user);
  Deposit(user, people, count);
    filein.close();
    return 0;
}

//Display the Array
void Display(PERSON arr[], int count)
{
  cout << "Name       Balance" << endl << "--------------"<< endl;

  for(int i = 0; i < count; i++)
  {
    cout << arr[i].Name << "   $" << arr[i].Balance << endl;
  }

};

//Find the Richest
void FindtheRiches(PERSON arr[], int count)
{
float richest = 0;
string richperson;

  for(int i = 0; i < count; i++)
  {
    if(arr[i].Balance < arr[i + 1].Balance)
    { richest = arr[i + 1].Balance; richperson = arr[i + 1].Name; }
  };
cout << "The richest person is " << richperson << endl << endl;
};

//Deposit Function
void Deposit(string name, PERSON arr[], int count)
{
  float bal = 0.0;
  int num;

  for(int i = 0; i < count; i++)
  {
    strcmp(name.c_str(), arr[i].Name);
    if (name == arr[i].Name){num = i;};
  };

    if(name == arr[num].Name)
    {
      cout << "Enter how much you want to deposit?: ";
      cin >> bal;
      arr[num].Balance += bal;
      cout << arr[num].Name << " your new balance is " << arr[num].Balance << endl;
    }

};
