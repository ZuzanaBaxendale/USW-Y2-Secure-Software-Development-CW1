#ifndef AUTHERISOR_H
#define AUTHERISOR_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Resource;
class Permission;

class Resource
{
private:
	uint16_t id;
public:
	uint16_t menu = 0;
	Resource(uint16_t a) : id(a)
	{
		menu = a;
	}

	static Resource* newResource(uint16_t resourceID, uint16_t subjectID);

	uint16_t getId();

	uint16_t getMenu(uint16_t);
};

class Permission
{
private:
	map<uint16_t, uint16_t> ResourceMenusAccessTypes;
	void subjectPointer();
	Resource *pResources;
public:
	Permission()
	{
	ResourceMenusAccessTypes[1] = 0;
	ResourceMenusAccessTypes[2] = 1;
	ResourceMenusAccessTypes[3] = 2;
	}
	Resource* accessResource(uint16_t resourceID, uint16_t subjectID);
	bool checkPermission(uint16_t resourceID, uint16_t subjectID);
};

class ResourceFactory
{
public:
	Resource* accessResource(uint16_t resourceID, uint16_t subjectID)
	{
		return Resource::newResource(resourceID, subjectID);
	}
};

#endif // !AUTHERISOR_H

