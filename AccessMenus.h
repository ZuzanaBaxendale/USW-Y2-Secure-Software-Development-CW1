#ifndef ACCESS_MENU_H
#define ACCESS_MENU_H

#include <iostream>
#include <vector>
#include <string>
#include "DateTimeSensor.h"
#include "ParticleSensor.h"
#include "TempuratureSensor.h"
using namespace std;

class ResourcesToAccess
{
private:
	uint16_t id;
public:
	vector<string> allUsers;
	void generalUserMenu(TempSensor, Particle, FridgeTimer);
	void adminMenu(TempSensor, Particle, FridgeTimer);
	void maintanenceMenu(TempSensor, Particle, FridgeTimer);
	void initialiseSensors(uint16_t);
	uint16_t lengthRunTime = 30;
	void programInformation();
	void changeSaveLocations(FridgeTimer, Particle, TempSensor);
	void AddItemsToFridge(FridgeTimer);
	void ChangeLengthOfSimulation();
	void runSimulator(FridgeTimer newFridge, Particle particalSensor, TempSensor tempSensor);
	void changePermissions(void);

	int getID()
	{
		return id;
	}

};

#endif ACCESS_MENU_H
