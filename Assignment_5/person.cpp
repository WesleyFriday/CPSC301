#include "person.h"

Person::Person(int cardNo, bool act, string fName, string lName) {

firstName = fName;
lastName = lName;
cardID = cardNo;
active = act;
                  // complete constructor
}

string Person::getFirstName() {
    return firstName; // complete
}

string Person::getLastName() {
    return lastName; // complete
}

int Person::getId() {
    return cardID; // complete
}

void Person::setActive(bool act)
{
if(act == 1){ act = true;}
else act = false;
} // complete

bool Person::isActive() {
    return active; // complete
}

string Person::fullName() {
    return firstName + " " + lastName; // complete
}
