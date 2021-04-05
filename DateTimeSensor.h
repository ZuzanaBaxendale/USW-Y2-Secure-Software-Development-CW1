#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Produce
{
public:
	uint16_t shelfLife;
	string name;

};

class FridgeTimer
{
private:
	const uint16_t OutOfDateWarning1 = 240;
	const uint16_t OutOfDateWarning2 = 120;
	const uint16_t OutOfDateWarning3 = 60;
	const uint16_t OutOfDateWarning4 = 30;
	const uint16_t OutOfDateWarning5 = 0;
public:
	uint16_t wherePrintData = 0;
	uint16_t count;
	bool endOfFridge;
	vector<Produce> itemsInFridge;
	void itemsInFridgeAtStart();
	uint16_t simulation(uint16_t count);
	void calculateTimeLeft(uint16_t count);
	void display(uint16_t count);
	void addItem(Produce& ItemInput);
	void printDataIndevidual(string);
	void printDataGroup(string);
};



#endif
