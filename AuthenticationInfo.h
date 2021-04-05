#ifndef AUTH_INFO_H
#define AUTH_INFO_H

#include <string>

using namespace std;

//AuthenticationInfo class 
class AuthenticationInfo
{
private:
	string userID;
	string password;
	uint16_t accessID;

public:
	string encrypt(string value);
	string decrypt(string value);
	bool validateUser(string name, string password);
};


#endif // AUTH_INFO_H
