#include "AccessMenus.h"
#include "ParticleSensor.h"
#include "TempuratureSensor.h"
#include "DateTimeSensor.h"
#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;
//Menu for users with a ganeral user ID
//can access the program information and run the simulation
void ResourcesToAccess::generalUserMenu(TempSensor tempSensor, Particle particalSensor, FridgeTimer newFridge)
{
	uint16_t choice = 0;
	while (choice != 99)
	{
		system("CLS");
		cout << "--MENU FOR GENERAL USER--" << endl << endl;
		cout << "1) view program information" << endl;
		cout << "2) view simulation" << endl;
		cout << "99) exit" << endl;
		cin >> choice;
		system("CLS");
		switch (choice)
		{
		case 1:
		{
			programInformation();
		}
			break;
		case 2:
		{
			runSimulator(newFridge, particalSensor, tempSensor);
		}
			break;
		case 99:
		{
			cout << "Exiting..." << endl;
		}
			break;
		default:
			break;
		}
	}
}
//Menu for users with an admin user ID to access resources
//An admin user can view program information, run the simulation,
// change where data is being saved and change user permissions
void ResourcesToAccess::adminMenu(TempSensor tempSensor, Particle particalSensor, FridgeTimer newFridge)
{
	uint16_t choice = 0;
	while (choice != 99)
	{
		cout << "--MENU FOR ADMIN USER--" << endl << endl;
		cout << "1) view program information" << endl;
		cout << "2) view simulation" << endl;
		cout << "3) change file save location" << endl;
		cout << "4) change permissions of users" << endl;
		cout << "99) exit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			programInformation();
		}
		break;
		case 2:
		{
			runSimulator(newFridge, particalSensor, tempSensor);
		} 
		break;
		case 3:
		{
			changeSaveLocations(newFridge, particalSensor, tempSensor);
		}
		break;
		case 4:
		{
			changePermissions();
		}
		break;
		case 99:
		{
			cout << "Exiting..." << endl;
		}
		break;
		default:
			break;
		}

	}
}

//Menu for users with a maintanence user ID to access resources
//a maintanence user can access the program information,
//run the simulation
//add items to the fridge
//change the length of the simulation
void ResourcesToAccess::maintanenceMenu(TempSensor tempSensor, Particle particalSensor, FridgeTimer newFridge)
{
	uint16_t choice = 0;
	while (choice != 99)
	{
		system("CLS");
		cout << "--MENU FOR MAINTANENCE USER--" << endl << endl;
		cout << "1) view program information" << endl;
		cout << "2) view simulation" << endl;
		cout << "3) add items to fridge" << endl;
		cout << "4) change length of simulation" << endl;
		cout << "99) exit" << endl;
		cin >> choice;
		system("CLS");

		switch (choice)
		{
		case 1:
		{
			programInformation();
		}
		break;
		case 2:
		{
			runSimulator(newFridge, particalSensor, tempSensor);
		}
		break;
		case 99:
		{
			cout << "Exiting..." << endl;
		}
		break;
		default:
			break;
		}
	}
}
//Initialising the sensors and sending users to their menu based on their ID
//sensors are passed into the menus to be used
	void ResourcesToAccess::initialiseSensors(uint16_t id)
	{
		TempSensor tempSensor;
		Particle particleSensor;
		FridgeTimer newFridge;
		switch (id)
		{
		case 0: generalUserMenu(tempSensor, particleSensor, newFridge);
			break;
		case 1: adminMenu(tempSensor, particleSensor, newFridge);
			break;
		case 2: maintanenceMenu(tempSensor, particleSensor, newFridge);
			break;
		}
	}
	//information about program
	//should be viewed by any type of user
void ResourcesToAccess::programInformation()
{
	system("CLS");
	cout << "-Information about program-" << endl << endl;
	cout << "This is a securly designed program that simulates a smart fridge" << endl;
	cout << "The main parts of this program are:" << endl;
	cout << ".A secure log in system that authenticates and autherises usesers" << endl;
	cout << ".Three different user types (general user, admin and maintanence)" << endl;
	cout << "that are defined when an account is created" << endl;
	cout << ".Three sensors: Tempurature sensor, Time sensor and odor particulates sensor" << endl;
	cout << endl << "Press any button to exit:" << endl;
	cin.ignore();
	system("CLS");
}
//Method to change the location of saved data
//only admin users can access this resource
//can chose between grouped and ungrouped or default (both)
void ResourcesToAccess::changeSaveLocations(FridgeTimer newFridge, Particle particalSensor, TempSensor tempSensor)
{
	uint16_t choice = 0;
	while (choice != 4)
	{
		system("CLS");
		cout << "Where do you want the data to be saved?" << endl << endl;
		cout << "1) Default (indevidual and grouped)" << endl;
		cout << "2) Individualy saved data only" << endl;
		cout << "3) Grouped saved data only" << endl;
		cout << "4) Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			newFridge.wherePrintData = 0;
			particalSensor.wherePrintData = 0;
			tempSensor.whereToPrintData = 0;
		}
		break;
		case 2:
		{
			newFridge.wherePrintData = 2;
			particalSensor.wherePrintData = 2;
			tempSensor.whereToPrintData = 2;
		}
		break;
		case 3:
		{
			newFridge.wherePrintData = 1;
			particalSensor.wherePrintData = 1;
			tempSensor.whereToPrintData = 1;
		}
		break;
		case 4:
		{

		}
		break;
		default: cout << "BAD CHOICE" << endl;
			break;
		}
	}
	system("CLS");
}

//Adding items to fridge is only available to the maintanence user
//maximum of 15 items in the fridge
//they must input the name and time before item will spoil
void ResourcesToAccess::AddItemsToFridge(FridgeTimer newFridge)
{
	uint16_t choice = 0;
	Produce item7;
	Produce item8;
	Produce item9;
	Produce item10;
	Produce item11;
	Produce item12;
	Produce item13;
	Produce item14;
	Produce item15;
	while (choice != 2)
	{
		system("CLS");
		cout << "1) Add item" << endl << "2) Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			if (item7.name == "")
			{
				cout << "Name: ";
				cin >> item7.name;
				cout << endl << "Shelf life: ";
				cin >> item7.shelfLife;
				newFridge.addItem(item7);
			}
			else if (item8.name == "")
			{
				cout << "Name: ";
				cin >> item7.name;
				cout << endl << "Shelf life: ";
				cin >> item7.shelfLife;
				newFridge.addItem(item7);
			}
			else if (item9.name == "")
			{
				cout << "Name: ";
				cin >> item7.name;
				cout << endl << "Shelf life: ";
				cin >> item7.shelfLife;
				newFridge.addItem(item7);
			}
			else if (item10.name == "")
			{
				cout << "Name: ";
				cin >> item7.name;
				cout << endl << "Shelf life: ";
				cin >> item7.shelfLife;
				newFridge.addItem(item7);
			}
			else if (item11.name == "")
			{
				cout << "Name: ";
				cin >> item7.name;
				cout << endl << "Shelf life: ";
				cin >> item7.shelfLife;
				newFridge.addItem(item7);
			}
			else if (item12.name == "")
			{
				cout << "Name: ";
				cin >> item7.name;
				cout << endl << "Shelf life: ";
				cin >> item7.shelfLife;
				newFridge.addItem(item7);
			}
			else if (item13.name == "")
			{
				cout << "Name: ";
				cin >> item7.name;
				cout << endl << "Shelf life: ";
				cin >> item7.shelfLife;
				newFridge.addItem(item7);
			}
			else if (item14.name == "")
			{
				cout << "Name: ";
				cin >> item7.name;
				cout << endl << "Shelf life: ";
				cin >> item7.shelfLife;
				newFridge.addItem(item7);
			}
			else if (item15.name == "")
			{
				cout << "Name: ";
				cin >> item7.name;
				cout << endl << "Shelf life: ";
				cin >> item7.shelfLife;
				newFridge.addItem(item7);
			}
			else
			{
				cout << "Max number of items reached" << endl;
			}
			break;

		default:
			break;
		}
	}
	system("CLS");
}
//Method to change the length of the simulation by changing the number of iterations
//each iteration reperesents 3 seconds
//only the maintanence users can access this resource
void ResourcesToAccess::ChangeLengthOfSimulation()
{
	uint16_t pauses = 3;
	system("CLS");
	cout << "How long do you want the simulation to last in seconds: ";
	cin >> lengthRunTime;
	lengthRunTime = lengthRunTime / 3;
	system("CLS");
}
//method to run the simulator
//cycles through the sensors for a given number of iterations
void ResourcesToAccess::runSimulator(FridgeTimer newFridge, Particle particalSensor, TempSensor tempSensor)
{
	system("CLS");
	cout << "Simulation start" << endl;
	cout << "_______________________________________________________________________________________________" << endl;
	newFridge.itemsInFridgeAtStart();
	uint16_t count = 0;
	for (uint16_t i = 0; i < lengthRunTime; i++)
	{
		Sleep(2000);
		newFridge.endOfFridge = false;
		while (!newFridge.endOfFridge)
		{
			count = newFridge.simulation(count);
			Sleep(1000);
		}
		particalSensor.particalSensor();
		tempSensor.tempSimulator();
		cout << endl;
		cout << "_______________________________________________________________________________________________" << endl;
		cout << endl;

	}
	cout << "Simulation end" << endl;
	cout << "Press any key to go back to menu" << endl;
	cin.ignore();
	system("CLS");
}
//change persmissions, can be accessed by admin user
//the user searches for a name to change the permissions of
//if the name is found they can then select a permission to give them
//the details are coppied intoa  vector with the persons new details for permission being coppied
//the file is then cleared and the vector gets printed out to the file.
void ResourcesToAccess::changePermissions()
{
	system("CLS");
	uint16_t choice = 0;
	while (choice != 2)
	{
		cout << "Change permission of a user" << endl << endl;
		cout << "1) Change a users permission" << endl;
		cout << "2) Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			uint16_t permisson;

			system("CLS");
			string usernameToChange;
			string usernameFound;
			cout << "Enter username of user to change: " << endl;
			cin >> usernameToChange;
			ifstream userAccess;
			userAccess.open("userDetails.txt", ios::in);
			if (userAccess.fail())
			{
				cout << "Failed to open file" << endl;
			}
			else
			{
				bool endFile = false;
				while (!endFile)
				{
					userAccess >> usernameFound;
					if (usernameFound == usernameToChange)
					{
					
						uint16_t choice = 0;
						while (choice == 0)
						{
							cout << "Found user: " << usernameToChange << endl;
							cout << "What permission should the user have?" << endl;
							cout << "1) General user" << endl;
							cout << "2) Maintenance user" << endl;
							cout << "3) Admin user" << endl;
							cout << "4) Exit" << endl;
							cin >> choice;

							switch (choice)
							{
							case 1:
							{
								permisson = 0;
							}
							break;
							case 2:
							{
								permisson = 2;
							}
							break;
							case 3:
							{
								permisson = 1;
							}
							break;
							case 4:
							{
								system("CLS");
								cout << "Exiting..." << endl;
								Sleep(1000);
								return;
							}
							break;
							default:
							{
								system("CLS");
								cout << "BAD CHOICE" << endl;
								Sleep(1000);
								choice = 0;
							}
							break;
							}
						}

						ifstream coppy;
						coppy.open("userDetails.txt", ios::in);
						if (coppy.fail())
						{
							cout << "Failed to open file" << endl;
						}
						else
						{
							allUsers.clear();
							bool endFile = false;
							uint16_t count = 0;
							string a;
							while (!endFile)
							{
								coppy >> a;
								allUsers.push_back(a);
								if (allUsers[count] == usernameFound)
								{
									coppy >> a;
									allUsers.push_back(a);
									coppy >> a;
									allUsers.push_back(to_string(permisson));
									if ((UINT16_MAX - 1) < count)
									{
										cout << "unsigned interger wrap" << endl;
									}
									else count++;
									if ((UINT16_MAX - 1) < count)
									{
										cout << "unsigned interger wrap" << endl;
									}
									else count++;
								}

								if (coppy.eof())
								{
									endFile = true;
								}
								count++;

							}
							coppy.close();
						}

						ofstream clear;
						clear.open("userDetails.txt", ios::trunc);
						clear.close();
						ofstream userOveride;
						userOveride.open("userDetails.txt", ios::app);
						if (userOveride.fail())
						{
							cout << "Could not access file" << endl;
						}
						else
						{
							uint16_t count = 0;
							while (count < allUsers.size())
							{
								string line = allUsers[count];
								if (!(userOveride << line << endl))
								{
									cout << "Could not write to file" << endl;
								}
								count++;
							}
						}
						userOveride.close();
					}

					if (userAccess.eof())
					{
						endFile = true;
					}


				}

			}
			userAccess.close();
			system("CLS");
			cout << "Users permisison has been changed!!" << endl;
			Sleep(1000);
			system("CLS");
		}
		}

	}



}
