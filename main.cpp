#include <iostream>
#include <string>
#include "animal.h" 
#include "cage.h"

using namespace std;

//Helper function prototypes
int readInt();
char readChar();

int main()
{
	int cageCount, animalCount;
	int characteristicNum;
	string tempName;
	char animalChar;

	cout << "How many cages would you like to create?" << endl;
	cageCount = readInt();
	Zoo zoo = Zoo(cageCount); //Create the zoo based on the number

	//Ask the user for each cage to populate the Zoo with
	int i, j;
	for (i = 0; i < cageCount; i++)
	{
		cout << "How many animals should cage " << i << " hold?" << endl;
		animalCount = readInt();
		for (j = 0; j < animalCount; j++)
		{
			cout << "Animal " << j << endl;
			cout << "What kind of animal should this be ('g', 'G', 'z')?" << endl;
			animalChar = readChar(); //Get the user's char entered
			cout << "What should the animal be named?" << endl;
			cin >> tempName;
			//Make an animal corresponding to the char
			switch (animalChar)
			{
				case 'g': //Giraffe
					cout << "How long is its neck?" << endl;
					characteristicNum = readInt();
					zoo.addAnimal(new Giraffe(tempName, characteristicNum), i);
					break;
				case 'G': //Gorilla
					zoo.addAnimal(new Gorilla(tempName), i); //Add the Gorilla to the zoo in cage i
					break;
				case 'z': //Zebra
					cout << "How many stripes does it have?" << endl;
					characteristicNum = readInt();
					zoo.addAnimal(new Zebra(tempName, characteristicNum), i);
					break;
			}
		}
	}

	//Now that the Zoo is setup, let's print the contents
	cout << endl;
	zoo.printZoo();

	//Now we're done! When the function ends, zoo goes out of scope and will be automatically deleted 
	//This only happens since it is not a pointer to a Zoo object, but a Zoo object itself
	return 0;
}

/*Reads an int from cin and returns it, while doing error checking*/
int readInt()
{
	int returnVal;
	cin >> returnVal;
	while (cin.fail() || returnVal < 0)
	{
		cout << "Error, invalid value. Please enter a positive integer" << endl;
		cin.clear();
		cin.ignore(512, '\n');
		cin >> returnVal;
	}

	return returnVal;
}

/*Reads a char from cin and returns it, while doing error checking*/
char readChar()
{
	char returnVal;
	cin >> returnVal;
	while (cin.fail() || (returnVal != 'g' && returnVal != 'G' && returnVal != 'z'))
	{
		cout << "Error, invalid selection. Please enter a char that is either ('g', 'G', or 'z')" << endl;
		cin.clear();
		cin.ignore(512, '\n');
		cin >> returnVal;
	}

	return returnVal;
}