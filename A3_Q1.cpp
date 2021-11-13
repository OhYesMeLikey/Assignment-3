#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

// define your classes here
class Person
{
private:
    string name;
    int age;

public:
    Person() : name{"Simp"}, age{69} {}

    Person(string newName, int newAge) : name{newName}, age{newAge} {}

    int getAge() { return age; }

    string getName() { return name; }
};

class Organization
{
private:
    string name;
    Person *members;
    int size;
    int dim;

public:
    Organization() : name{"Poki Simps"}, members{new Person[100]}, size{0}, dim{100} {}

    Organization(const Organization &copyThisOrg)
    {
        name = copyThisOrg.name;
        size = copyThisOrg.size;
        dim = copyThisOrg.dim;
        members = new Person[dim];
        for (int i = 0; i < size; i++)
        {
            members[i] = copyThisOrg.members[i];
        }
    }

    ~Organization()
    {
        delete[] members;
        members = nullptr;
    }

    string getMemberNames()
    {
        if (size == 0)
        {
            return "";
        }

        string everyMember{""};
        for (int i = 0; i < size; i++)
        {
            if (i + 1 == size)
            {
                everyMember += members[i].getName();
            }
            else
            {
                everyMember += members[i].getName() + ";";
            }
        }
        return everyMember;
    }

    
    void addPerson(Person person)
    {
        if (size == dim)
        {
            dim *= 2;
            
            Person *temp {new Person[dim]};
            for (int i = 0; i < size; i++)
            {
                temp[i] = members[i];
            }
            temp[size++] = person;
            
            delete[] members;
            members = temp;
            temp = nullptr;
        }
        else
        {
            members[size++] = person;
        }
    }
    
};

// prints all members of an organization to std::cout
void printMembers(Organization organization)
{
    cout << organization.getMemberNames() << endl;
}

int main()
{
    Person p;         //create a Person instance
    Organization org; //create an Organization instance

    org.addPerson(p); // add p to org
    cout << "org includes: " << endl;
    printMembers(org);

    //here we will add 250 persons to org
    for (int i = 0; i < 250; i++)
    {
        Person person("Person" + std::to_string(i), rand() % 30 + 16); // create  a Person instance with the name "Person+i" and a random age
        org.addPerson(person);
    }
    cout << endl
         << "organization includes: " << endl;
    printMembers(org);

    Organization org1 = org;
    cout << endl
         << "org1 includes: " << endl;
    printMembers(org1);

    return 0;
}