#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "DateTimeSensor.h"

using namespace std;
//pushes item selected onto vector
void FridgeTimer::addItem(Produce& ItemInput)
{
	itemsInFridge.push_back(ItemInput);
}
//when initialising the fridge some items already exist
//they ahev a pre-determind name and shelf life (shelf
//life is more condensed than a real life simulation as 
//produce can last for days/weeks and I don't want the
//simulator to have to run for that long
void FridgeTimer::itemsInFridgeAtStart()
{
	Produce item1;
	Produce item2;
	Produce item3;
	Produce item4;
	Produce item5;
	Produce item6;
	itemsInFridge.clear();

	item1.name = "Orange";
	item1.shelfLife = 300;
	addItem(item1);
	item2.name = "Milk";
	item2.shelfLife = 50;
	addItem(item2);
	item3.name = "Eggs";
	item3.shelfLife = 200;
	addItem(item3);
	item4.name = "Salmon";
	item4.shelfLife = 100;
	addItem(item4);
	item5.name = "Scrambled eggs";
	item5.shelfLife = 150;
	addItem(item5);
	item6.name = "Butter";
	item6.shelfLife = 400;
	addItem(item6);
}

uint16_t FridgeTimer::simulation(uint16_t count)
{
	if (itemsInFridge[count].shelfLife >= 0)
	{
	calculateTimeLeft(count);
	}
	if (itemsInFridge[count].shelfLife >= 0)
	{
	display(count);
	}
	count++;
	if (count > (itemsInFridge.size() - 1))
	{
		endOfFridge = true;
		count = 0;
		return count;
	}

	return count;
}
//displays the item, it's shelf life and any warnings that need to be shown
void FridgeTimer::display(uint16_t count)
{
	string dataToPrint;
	cout << "|" << itemsInFridge[count].name << "| Time before item expires: " << itemsInFridge[count].shelfLife;
	string integerData= to_string(itemsInFridge[count].shelfLife);

	if (itemsInFridge[count].shelfLife <= OutOfDateWarning1)
	{
		string warning;
		if (itemsInFridge[count].shelfLife == OutOfDateWarning5)
		{
			warning = "ITEM IS OUT OF DATE! THROW AWAY NOW!";
		}
		else if (itemsInFridge[count].shelfLife <= OutOfDateWarning4)
		{
			warning = "ITEM WILL SOON BE OUT OF DATE! CONSUME IMEDIATLY!";
		}
		else if (itemsInFridge[count].shelfLife <= OutOfDateWarning3)
		{
			warning = "ITEM IS NEARING EXPARATION DATE! CONSUME SOON!";
		}
		else if (itemsInFridge[count].shelfLife <= OutOfDateWarning2)
		{
			warning = "ITEM IS GETTING OLDER! SHOULD CONSIDER CONSUMING!";
		}
		else
		{
			warning = "ITEM WILL START GETTING OLD SOON! NO NEED TO WORRY THOUGH";
		}
		cout << "Warning!! " << warning << endl;
		dataToPrint = "|" + itemsInFridge[count].name + "| Time before item expires: " + integerData + warning;
	}
	else
	{
		cout << endl;
		dataToPrint = "|" + itemsInFridge[count].name + "| Time before item expires: " + integerData;
	}

	switch (wherePrintData)
	{
	case 0: 	
	{
		printDataIndevidual(dataToPrint);
		printDataGroup(dataToPrint);
	}
			break;
	case 1: 		printDataGroup(dataToPrint);
			break;
	case 2: 		printDataIndevidual(dataToPrint);
		break;
	default:
	{
		printDataIndevidual(dataToPrint);
		printDataGroup(dataToPrint);
	}
			break;
	}
}
//function calculates time left before item expires
//checks for unsigned integer wrap occur
void FridgeTimer::calculateTimeLeft(uint16_t count)
{
	if ((UINT_MAX - itemsInFridge[count].shelfLife) < -10)
	{
		cout << "UNSIGNED INTEGER WRAP ERROR!!!" << endl;
	}
	else
	itemsInFridge[count].shelfLife = (itemsInFridge[count].shelfLife - 10);
}
//method to print data to indevidual log files
void FridgeTimer::printDataIndevidual(string dataToPrint)
{
	ofstream output_file;
	output_file.open("ProduceStatusLog.txt", ios::out | ios_base::app);

	if (output_file.fail())
	{
		cout << "Could not access file for writing" << endl;
	}
	else if (!(output_file << dataToPrint << endl))
	{
		cout << "problem writing file" << endl;
	}

	output_file.close();
}
//method to print data to a group log file
void FridgeTimer::printDataGroup(string dataToPrint)
{
	ofstream output_file;
	output_file.open("OverallLog.txt", ios::out | ios_base::app);

	if (output_file.fail())
	{
		cout << "Could not access file for writing" << endl;
	}
	else if (!(output_file << dataToPrint << endl))
	{
		cout << "problem writing file" << endl;
	}

	output_file.close();

}