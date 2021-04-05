#ifndef AUTHENTICATOR_H
#define AUTHENTICATOR_H

#include "AuthenticationInfo.h" 
#include "Subject.h" 

using namespace std;

//Authenticator class 
class Authenticator
{
public:
	Authenticator(); // constructor initializes data members
	bool authenticateUser(Subject &s); // attempts to authenticate user
};

#endif // AUTHENTICATOR_H