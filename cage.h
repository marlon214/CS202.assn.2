#ifndef CAGE_H
#define CAGE_H

#include "animal.h"
#include <iostream>

using namespace std;

//Dyanmically resizing Cage to fit some number of mixed and matched Animals into
class Cage
{
	Animal** cageArr; //Dynamically allocated array containing all the animals in this cage. This is a 1D array of pointers
	int size, count; //The total amount of space in the cage and count of how many Animals are actually in it
	const int RESIZE_AMOUNT = 4;

public:
	Cage() { cageArr = nullptr; size = count = 0; }
	Cage(int size);
	~Cage();

	void addAnimal(Animal* animal);
	void printCage();
};

class Zoo
{
	Cage* cages;
	int cageCount;
public:
	Zoo(int cage_count);
	~Zoo();
	void printZoo();
	void addAnimal(Animal* animal, int cage_index) { cages[cage_index].addAnimal(animal); }
};

#endif
