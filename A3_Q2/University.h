
#ifndef UNIVERSITY_H 
#define UNIVERSITY_H 

#include "Organization.h"



class University : public Organization {

private:
    float tuition;

public:
    University();   
    University(string newName);   
    University(const Organization& copyThisOrg);  
    float getTuition();
    void setTuition(float newTuition);
};

#endif

