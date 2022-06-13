#include "cage.h"
#include <iostream>
#include <string>

using namespace std;

//---------------- Zoo function implementations -----------------

/*
*/
Zoo::Zoo(int cage_count)
{
	//Allocate the cages array to hold as many cages that were asked for
	//Also set the cageCount for later
}

/**/
Zoo::~Zoo()
{
	//The Zoo destructor needs to deallocate the array storing all of the Cages
	//Since this is a 1D array of Cage objects, we can deallocate pretty easily
	//This should be one line deleting the array (recall the syntax for deleting an array)
}

/* Function to print all of the cages in the Zoo*/
void Zoo::printZoo()
{
	for (int i = 0; i < cageCount; i++)
	{
		cout << "Cage# " << i << endl;
		cages[i].printCage();
	}
}

//---------------- Cage function implementations -----------------

/*
*/
Cage::Cage(int size)
{
	//This constructor needs to allocate an Animal* array of the given size.
	//Allocate an Animal* array and store it in our cageArr
	//Set this Animal's size to the passed size and the count to 0
}

Cage::~Cage()
{
	//The Cage destructor needs to deallocate the array holding Animals as well as the Animals
	//themselves. While it is a 1D array, it contains pointers, so we need to deallocate the objects
	//being pointed to to avoid memory leaks.

	//Start by going through the array and deallocating any existing Animals
	//Once they're all deallocated, you can deallocate the array itself
	//This should be about 3 lines. Consider that the contents of the array are objects and then we have the array
	//itself, so you'll need two different kinds of deletes
}

/*
*/
void Cage::addAnimal(Animal* animal)
{
	//If the array is unallocated (nullptr), allocate it and set the size
	//Else if the array is out of space, allocate a bigger one using RESIZE_AMOUNT and set the size
	//Make sure to deep copy everything from the old array to the bigger array and deallocate the old one

	//Finally, regardless of whether or not we allocated, throw the Animal at the end of the cage array
	//Then increment the count
}

/* Prints all of the animals in the cage. Implemented for you already */
void Cage::printCage()
{
	cout << "There are " << count << " animals in this cage" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << i << ". " << endl;
		//Figure out what the type of the animal is to cast and then print.
		//This is only really necessary since we're not using virtuals
		switch (cageArr[i]->getType())
		{
			case AnimalType::GIRAFFE:
				static_cast<Giraffe*>(cageArr[i])->printGiraffe();
				break;
			case AnimalType::GORILLA:
				static_cast<Gorilla*>(cageArr[i])->printGorilla();
				break;
			case AnimalType::ZEBRA:
				static_cast<Zebra*>(cageArr[i])->printZebra();
				break;
		}
		cout << endl;
	}
	cout << endl;
}