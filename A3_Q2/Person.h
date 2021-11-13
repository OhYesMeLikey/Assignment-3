
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Organization;
 
/**
Class Person:  Create  Person, used to add organizations to a person
Private variable: name, age and others to define


Add all missing methods
*/
class Person {
private:
    string name;
    int age;
    int maxOrgs;
    int numOfOrgsJoined;
    Organization** orgs;
public:
    Person();
    Person(string newName);
    Person(string newName, int newAge);

    ~Person();

    string getName();
    int getAge();
    int getMaxOrgs();
    int getSize();

    void addOrganization(Organization* org);

    string getOrgNames();

    float getTotalTuition();
    
    string printSchools();
};

#endif