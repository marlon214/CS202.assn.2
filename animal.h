#ifndef ANIMAL_H
#define ANIMAL_H
/*^^^ Header guards are used to make sure that a file is not included multiple times*/

#include <iostream>
#include <string>

using namespace std;

enum class AnimalType { GORILLA, GIRAFFE, ZEBRA };

class Animal
{
	string name;
	AnimalType type; //Type of animal this is (needed since we haven't learned virtuals)

protected:
	Animal(string name, AnimalType type) { this->name = name; this->type = type; }
	void printAnimalInfo();
	static string getAnimalTypeAsString(AnimalType);

public:
	AnimalType getType() { return type; } //Accessor
};

//Giraffe class that inherits from the Animal class and adds one more variable member
class Giraffe : public Animal
{
	int neckLength;
public:
	Giraffe(string, int);
	void printGiraffe();
};

//Gorilla class that inherits from the Animal class
class Gorilla : public Animal
{
public:
	Gorilla(string);
	void printGorilla();
};

//Zebra class that inherits from the Animal class
class Zebra : public Animal
{
	int stripes;
public:
	Zebra(string, int);
	void printZebra();
};

#endif
