#include <iostream>
#include <string>
#include "animal.h" //To include a local file, put the relative path in quotes

using namespace std;

//------------------ Animal base class function implementations ------------------
/* Prints information that all animals have to standard out, cout. You can call this function to 
* print the private Animal class members within other classes.
*/
void Animal::printAnimalInfo()
{
	cout << name << " the " << getAnimalTypeAsString(type) << endl;
}

/* This function converts from the Animal's AnimalType to a string
* Written for you for use in printAnimalInfo() 
*/
string Animal::getAnimalTypeAsString(AnimalType animal_type)
{
	switch (animal_type)
	{
		case AnimalType::GIRAFFE:
			return "Giraffe";
		case AnimalType::GORILLA:
			return "Gorilla";
		case AnimalType::ZEBRA:
			return "Zebra";
		default:
			return "Unknown Animal";
	}
}

//------------------ Giraffe class function implementations ------------------
//These functions are implemented for you already for use as reference for the other 2 classes
Giraffe::Giraffe(string giraffe_name, int neck) : Animal(giraffe_name, AnimalType::GIRAFFE)
{
	/*We call the Animal class constructor using relevant arguments above. Recall
	* that a base class constructor is ALWAYS called by a derived class one before the body, even if we
	* don't put any. Here, we explicitly ask to use the (string, AnimalType) Animal constructor
	* by putting it after the :. If none is put, the default constructor is called. */

	//Set the neck length, being the only new member added to the Giraffe class
	//from the Animal class.
	neckLength = neck;

}
void Giraffe::printGiraffe()
{
	Animal::printAnimalInfo(); //Re-use the Animal's print to make life easier (so, just call it)
	cout << "Neck Length: " << neckLength << endl; //Add onto the existing Animal code and print the neck length
}

/* YOUR CODE HERE Finish implementing the functions for 
the classes that inherit from Animal. All your code should go below this line */

//------------------ Gorilla class function implementations ------------------

/*
*/
Gorilla::Gorilla(string gorilla_name) /*YOUR CODE HERE*/
{
	//Call the Animal class constructor to finish setting things. Use Giraffe's constructor as reference

	//No other members here, so the function body will be empty
}

/*
*/
void Gorilla::printGorilla()
{
	//The Gorilla prints nothing new, just call the Animal's print function similar to Giraffe's print
	/*YOUR CODE HERE*/
}

//------------------ Zebra class function implementations ------------------

/*
*/
Zebra::Zebra(string zebra_name, int stripe_count) /*YOUR CODE HERE*/
{
	//Similar to the other classes, call the base class Animal constructor

	//Then, set the new stripes member for this class
}

/*
*/
void Zebra::printZebra()
{
	//Again, similar to the other two classes, let's reuse the base Animal print function
	/*YOUR CODE HERE*/
	
	//Then add onto it by printing the stripes
}