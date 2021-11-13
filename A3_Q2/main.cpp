
#include "Person.h"
#include "Organization.h"
#include "university.h"

//Start of the implementation of Person
Person::Person()
{
    name = "Simp";
    age = 69;
    maxOrgs = 5;
    numOfOrgsJoined = 0;
    orgs = new Organization *[maxOrgs];
}

Person::Person(std::string newName)
{
    name = newName;
    age = 69;
    maxOrgs = 5;
    numOfOrgsJoined = 0;
    orgs = new Organization *[maxOrgs];
}

Person::Person(std::string newName, int newAge)
{
    name = newName;
    age = newAge;
    maxOrgs = 5;
    numOfOrgsJoined = 0;
    orgs = new Organization *[maxOrgs];
};

Person::~Person()
{
    if (orgs == nullptr)
    {
        return;
    }
    for (int i = 0; i < maxOrgs; i++)
    {
        delete[] orgs[i];
    }
    delete[] orgs;
    orgs = nullptr;
}

std::string Person::getName()
{
    return name;
}
int Person::getAge()
{
    return age;
}
int Person::getMaxOrgs()
{
    return maxOrgs;
}
int Person::getSize()
{
    return numOfOrgsJoined;
}

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
        cerr << "Can't join more than 5 orgs." << endl;
    }
}

std::string Person::getOrgNames()
{
    if (numOfOrgsJoined == 0)
    {
        return "This person hasn't joined any orgs.";
    }

    std::string allOrgsJoined;
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

std::string Person::printSchools()
{
    if (numOfOrgsJoined == 0)
    {
        return "This person hasn't joined any schools.";
    }

    std::string allSchools;
    University *uni;

    for (int i = 0; i < numOfOrgsJoined; i++)
    {
        uni = dynamic_cast<University *>(orgs[i]);
        if (uni != nullptr)
        {
            if (i + 1 == numOfOrgsJoined)
            {
                allSchools += (uni->getName());
            }
            else
            {
                allSchools += (uni->getName()) + ", ";
            }
        }
    }
}
// End of Person implementation
//
//
//
//
//
//
//
//
//
// Start of Organization implementation
Organization::Organization()
{
    name = "Poki Simps";
    size = 0;
    dim = 100;
    members = new Person[dim];
}

Organization::Organization(std::string newName)
{
    name = newName;
    size = 0;
    dim = 100;
    members = new Person[dim];
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
    if (size == 0)
    {
        return;
    }

    delete[] members;
    members = nullptr;
}

string Organization::getMemberNames()
{
    if (size == 0)
    {
        return "There are no members in the organization.";
    }

    string listOfMembers = "";
    for (int i = 0; i < size; i++)
    {
        if (i + 1 == size)
        {
            listOfMembers = listOfMembers + members[i].getName();
        }
        else
        {
            listOfMembers = listOfMembers + members[i].getName() + ", ";
        }
    }
    return listOfMembers;
}

Person *Organization::copyMembersWithExtraSlots()
{
    Person *temp = new Person[dim];

    for (int i = 0; i < size; i++)
    {
        temp[i] = members[i];
    }

    return temp;
}

void Organization::addPerson(Person person)
{
    /*
    if (size == 0)
    {
        members = new Person[size + 1];
        members[size++] = person;
    }
    else
    {
        if (size == dim)
        {
            dim *= 2;
        }

        Person *copiedMembers = copyMembersWithExtraSlot();
        copiedMembers[size++] = person;
        delete[] members;
        members = copiedMembers;
    }
    */
    if (size == 0)
    {
        members[size++] = person;
    }
    else if (size == dim)
    {
        dim *= 2;
    }
    else
    {
        Person *copiedMembers = copyMembersWithExtraSlots();
        copiedMembers[size++] = person;
        delete[] members;
        members = copiedMembers;
    }
}

string Organization::getName()
{
    return name;
}
// End of Organization implementation
//
//
//
//
//
//
//
//
//
// Start of University implementation
University::University()
{
    tuition = 0;
    name = "UniPokiSimp";
    members = nullptr;
    size = 0;
    dim = 100;
}

University::University(std::string newName) : Organization(newName)
{
    tuition = 0;
}

float University::getTuition()
{
    return tuition;
}

void University::setTuition(float newTuition)
{
    tuition = newTuition;
}
// End of University implementation

//add a person to an organization and an organization to a person
void registering(Organization *o, Person *p)
{
    (*o).addPerson(*p);
    (*p).addOrganization(o);
}

//prints the name of the person, the number of organizations of the person and the name list of the organizations of the person
void printMembers(Person &person)
{

    cout << person.getName() << " is part of " << person.getSize() << " organisations: " << endl;
    cout << person.getOrgNames() << endl;
}

//main: to test program
int main()
{
    Organization *o0 = new Organization("SAMSUNG");
    Organization *o1 = new Organization("Test");
    Organization *o2 = new Organization("Subway");
    Organization *o3 = new Organization("IBM");
    Organization *o4 = new Organization("Microsoft");
    Organization *o5 = new Organization("Google");

    University *o6 = new University("UofO");
    University *o7 = new University("UofT");

    cout << "Test" << endl;

    o6->setTuition(10);
    o7->setTuition(30);

    Person *p1 = new Person("Amir");
    Person *p2 = new Person("John");

    cout << "Before registering" << endl;
    registering(o0, p1);
    registering(o1, p1);
    registering(o6, p1);
    registering(o3, p1);
    registering(o7, p1);
    //registering(o5, p1); //throws error

    registering(o1, p2);
    registering(o6, p2);
    registering(o5, p2);

    cout << "After registering" << endl;

    printMembers(*p1);
    cout << "Univeristy Organization: \n"
         << p1->printSchools() << endl;
    cout << "With Total tution fees of " << p1->getTotalTuition() << " $" << endl
         << endl;

    return 0;
}