#include "Person.h"
#include "Organization.h"
#include "University.h"

University::University() : tuition{0} {}

University::University(std::string newName) : Organization(newName), tuition{0} {}

float University::getTuition() { return tuition; }

void University::setTuition(float newTuition) { tuition = newTuition; }