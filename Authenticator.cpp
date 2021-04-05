#include <iostream>
#include <string>
#include "Authenticator.h"
#include "Autherisor.h"
using namespace std;

Authenticator::Authenticator() {};
//function to check if user is authenticated
//used to access authentication info so as to
//add a layor of security
bool Authenticator::authenticateUser(Subject &s)
{
	AuthenticationInfo ainfo;
	string Id = s.getUserName();
	string pass = s.getPassword();
	bool authenticated = false;
	if (ainfo.validateUser(Id, pass))
	{
		cout << "Welcome!" << endl;
		cout << "Authenticated!" << endl;
		authenticated = true;
	}
	else cout << "Invalid Id or password. Please try again.";
	return authenticated;
};