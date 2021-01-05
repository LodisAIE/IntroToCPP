#include <iostream>
#include <fstream>
#include "Character.h"


bool textFileExample()
{
	Character player = Character();
	player.health = 100;
	player.damage = 5;

	//Example of saving to a text file

	//Create an instance of a file stream
	std::fstream file;

	//Search for the file with the name given in the first
	//argument. If no file with this name exists, one with
	//the name is created. Then "std::ios::out" is used to
	//say that we want to output data to the text file.
	file.open("PlayerSaveData/save.txt", std::ios::out | std::ios::_Noreplace);

	//Check is the file isn't opened. If so, return from main.
	if (!file.is_open())
	{
		return false;
	}
	std::cout << "Lodis";
	//Write player stats to the text file.
	file << player.health << std::endl;
	file << player.damage;

	//Close the file when we're done.
	file.close();


	//Example of loading from a text file.
	Character player2 = Character();

	//Search for a file that has the name given in the first
	//argument. The "std::ios::in" argument is used to say 
	//that we want to get input from the file.
	file.open("PlayerSaveData/save.txt", std::ios::in);

	//Check is the file isn't opened. If so, return from main.
	if (!file.is_open())
	{
		return false;
	}
	int test = 0;
	std::cin >> test;
	//Reads the player stats from the text file.
	file >> player2.health;
	file >> player2.damage;

	//Closes the file once we're done
	file.close();

	std::cout << player2.health << std::endl;
	std::cout << player2.damage << std::endl;
	return true;
}

bool binaryFileExample()
{
	//Initialize characters
	Character sbeve = Character();
	sbeve.health = 120;
	sbeve.damage = 14;
	Character sbeve2 = Character();
	sbeve2.health = 145;
	sbeve2.damage = 11;
	Character sbeve3 = Character();
	sbeve3.health = 109;
	sbeve3.damage = 10;

	//Create an instance of an file stream
	std::fstream file;

	//Open the file we want to save to. The first argument is the file path.
	//The second is what we will be doing with the file(reading or writing)
	//followed by any extra parameters. In this case, std::ios::binary is used
	//to make the file created a binary file. 
	file.open("save.txt", std::ios::app | std::ios::binary);

	//Check to see if the file is open before using it
	if (!file.is_open())
		return false;

	//Write all the characters to file.
	file.write((char*)&sbeve, sizeof(Character));
	file.write((char*)&sbeve2, sizeof(Character));
	file.write((char*)&sbeve3, sizeof(Character));

	//Close the file once writing is complete.
	file.close();

	//Create a character to store the loaded data.
	Character sbeve4 = Character();

	//Open the file to load from.
	file.open("save.txt", std::ios::in | std::ios::binary);

	//Check to see if the file is open.
	if (!file.is_open())
		return false;

	//Position the marker to two Characters away from the beginning.
	//file.seekg(-((int)sizeof(Character)), std::ios::end);

	//Set the character to be the value read from the file.
	file.read((char*)&sbeve4, sizeof(Character));

	//Print the results
	std::cout << sbeve4.health << std::endl;
	std::cout << sbeve4.damage << std::endl;

	//Close the file.
	file.close();
	return true;
}

int main()
{
	binaryFileExample();
	
	return 0;
}