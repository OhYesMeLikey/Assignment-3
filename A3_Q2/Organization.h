
#ifndef ORGANIZATION_H
#define ORGANIZATION_H
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class Person;

class Organization {

protected:
    std::string name; // name of the org
    Person* members; // list of members
    int size;  // actual size of the org
    int dim;  // max size of the org
    Person* copyMembersWithExtraSlots();
public:
    Organization();
    Organization(string newName);
    Organization(const Organization& copyThisOrg);
    Organization& operator=(const Organization& copyThisOrg);
    virtual ~Organization();
    string getMemberNames();
    void addPerson(Person newPerson);
    string getName();
};

#endif
