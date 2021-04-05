#include "AuthenticationInfo.h"
#include "Subject.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//metod for decrypting passwords
//manipulated aski values to get the original word
string AuthenticationInfo::decrypt(string value)
{
	char str[100];
	strcpy_s(str, value.c_str());
	for (uint16_t i = 0; i < 100 && str[i] != '\0'; i++)
		str[i] = str[i] - 2;
	value = str;
	return value;
}
//metod for encrypting passwords
//manipulated aski values to get the encrypted word
string AuthenticationInfo::encrypt(string value)
{
	char str[100];
	strcpy_s(str, value.c_str());
	for (uint16_t i = 0; i < 100; i++)
		str[i] = str[i] + 2;
	value = str;
	return value;
}
//Validate user method
//returns bool if user is valid (if password and username match those stored)
bool AuthenticationInfo::validateUser(string name, string pass)
{
	bool validUser = false;
	uint16_t currentLine = 0;
	string username;
	string passwordEncrypt;
	string passwordDecrypt;
	string id;

	ifstream viewUsers;
	viewUsers.open("UserDetails.txt");
	if (viewUsers.fail())
	{
		cout << "error accessing file" << endl;
	}
	else
	{
		bool end = false;
		while (!end)
		{
			viewUsers >> username;
			if (username == name)
			{

				viewUsers >> passwordEncrypt;
				viewUsers >> id;
				passwordDecrypt = decrypt(passwordEncrypt);
				if (passwordDecrypt == pass)
				{
					validUser = true;
				}
			}
			if (viewUsers.eof())
			{
				end = true;
			}
		}
	}
	viewUsers.close();

	return validUser;
}