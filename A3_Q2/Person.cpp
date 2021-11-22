#include "Person.h"
#include "Organization.h"
#include "University.h"
using std::endl;
using std::string;

Person::Person() : name{"Simp"},
                   age{69},
                   maxOrgs{5},
                   numOfOrgsJoined{0},
                   orgs{new Organization *[maxOrgs]} {}

Person::Person(string newName) : name{newName},
                                 age{69},
                                 maxOrgs{5},
                                 numOfOrgsJoined{0},
                                 orgs{new Organization *[maxOrgs]} {}

Person::Person(string newName, int newAge) : name{newName},
                                             age{newAge},
                                             maxOrgs{5},
                                             numOfOrgsJoined{0},
                                             orgs{new Organization *[maxOrgs]} {}

Person::~Person()
{
    delete[] orgs;
    orgs = nullptr;
}

string Person::getName() { return name; }
int Person::getAge() { return age; }
int Person::getMaxOrgs() { return maxOrgs; }
int Person::getSize() { return numOfOrgsJoined; }

void Person::addOrganization(Organization *org)
{
    try
    {
        if (numOfOrgsJoined == maxOrgs)
        {
            throw std::out_of_range("Out of range error.");
        }
        else
        {
            orgs[numOfOrgsJoined++] = org;
            //size++;
        }
    }
    catch (const out_of_range &e)
    {
        std::cerr << "Can't join more than 5 orgs." << endl;
    }
}

string Person::getOrgNames()
{
    if (numOfOrgsJoined == 0)
    {
        return "This person hasn't joined any orgs.";
    }

    string allOrgsJoined;
    for (int i = 0; i < numOfOrgsJoined; i++)
    {
        if (i + 1 == numOfOrgsJoined)
        {
            allOrgsJoined += (*orgs[i]).getName();
        }
        else
        {
            allOrgsJoined += (*orgs[i]).getName() + ", ";
        }
    }
    return allOrgsJoined;
}

float Person::getTotalTuition()
{
    if (numOfOrgsJoined == 0)
    {
        return 0;
    }

    float total = 0;
    University *uni;

    for (int i = 0; i < numOfOrgsJoined; i++)
    {
        uni = dynamic_cast<University *>(orgs[i]);

        if (uni != nullptr)
        {
            total += (*uni).getTuition();
        }
    }
    return total;
}

string Person::printSchools()
{
    if (numOfOrgsJoined == 0)
    {
        return "This person hasn't joined any schools.";
    }

    string allSchools;
    University *uni;

    for (int i = 0; i < numOfOrgsJoined; i++)
    {
        uni = dynamic_cast<University *>(orgs[i]);
        if (uni != nullptr)
        {
            if (i + 1 == numOfOrgsJoined)
            {
                allSchools += '<' + (*uni).getName() + " : " + to_string((*uni).getTuition()) + '>';
            }
            else
            {
                allSchools += '<' + (*uni).getName() + " : " + to_string((*uni).getTuition()) + '>' + " ";
            }
        }
    }
    return allSchools;
}