#include "subject.h"
#include <iostream>
#include <string>
#include "Autherisor.h"
using namespace std;
//creates a pointer to subject class
void Permission::subjectPointer()
{
	Subject *pSubject;
}
//checks if permission is cgranted for a particulare resource
Resource* Resource::newResource(uint16_t resourceID, uint16_t subjectID)
{		
	Permission *p = new Permission();
	if (p->checkPermission(resourceID, subjectID))
	{
		cout << "access ganted" << endl;
		return new Resource(resourceID);
	}
	else
	{
		return nullptr;
	}
}
//Secure way of accessing id
uint16_t Resource::getId()
{
	return id;
}
//sets menu = to resourceID, makes debugging easier to see is user is accessing
//the correct menu
uint16_t Resource::getMenu(uint16_t resourceID)
{
	menu = resourceID;
	return menu;
}
//checks permission for accessing the resource
Resource* Permission::accessResource(uint16_t resourceID, uint16_t subjectID)
{
	if (checkPermission(resourceID, subjectID))
	{
		cout << "access granted" << endl;
		return new Resource(resourceID);
	}
	else return nullptr;

}

bool Permission::checkPermission(uint16_t resourceID, uint16_t subjectID)
{
	if (ResourceMenusAccessTypes[resourceID] == subjectID)
	{
		return true;
	}
	else return false;
}