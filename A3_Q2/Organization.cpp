#include "Person.h"
#include "Organization.h"
#include "University.h"
using std::string;

Organization::Organization() : name{"Poki Simps"}, members{new Person[100]}, size{0}, dim{100} {}

Organization::Organization(std::string newName) : name{newName}, members{new Person[100]}, size{0}, dim{100} {}

Organization::Organization(const Organization &copyThisOrg)
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

Organization &Organization::operator=(const Organization &copyThisOrg)
{
    if (this == &copyThisOrg)
    {
        return *this;
    }

    name = copyThisOrg.name;
    size = copyThisOrg.size;
    dim = copyThisOrg.dim;
    members = new Person[dim];
    for (int i = 0; i < size; i++)
    {
        members[i] = copyThisOrg.members[i];
    }
    return *this;
}

Organization::~Organization()
{
    delete[] members;
}

string Organization::getMemberNames()
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

void Organization::addPerson(Person person)
{
    if (size == dim)
    {
        dim *= 2;

        Person *temp{new Person[dim]};
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

string Organization::getName() { return name; }