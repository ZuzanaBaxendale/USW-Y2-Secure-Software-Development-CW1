#include <iostream>
#include <string>
using namespace std;

class DeviceResource
{
private:
	string userType;
public:
	// returns usertype saved
	string getUserType() { return userType; }
};