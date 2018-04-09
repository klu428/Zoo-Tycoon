/********************
** Author: Kelvin Lu
** Date: 10/16/2017
** Description: This is the class specification file for the Zoo class.
********************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp"
#include <string>

//enumaertor for type of animal
enum Species {TIGER, PENGUIN, TURTLE};

//Dynamic array structure
struct Animal_DA
{

	Animal** collection;
	int size;
	int capacity;

};

class Zoo
{
protected:
	Animal_DA zoo[3];
	int numSpecies;
	int bank;
	int dailyProfit;

public:

	//Constructor
	Zoo();

	//Initialize new animal dynamic array
	void initAnimal_DA(Animal_DA *species);

	//Adds an animal into their corresponding dynamic array
	void addAnimal(Animal_DA* species, Animal* animal);

	//Buy an animal, if possible. Returns false if not possible.
	bool buyAnimal(Animal_DA *species, Animal* animal);

	//Remove an animal at the desired index
	void removeAnimal(Animal_DA* species, int index);

	//Get an animal from the desired index
	Animal * getAnimal(Animal_DA* species, int index);

	//Increase capacity by 2x
	void incCapacity(Animal_DA* species);

	//Increase the age of every animal in the zoo
	void incAge();

	//Calculate the daily profit without bonuses
	int getProfit();

	//Get the feeding cost of a collection
	int getFeedingCost();

	//Get bonus payout for each tiger and add it to the daily profit
	int getBonus();

	//Select a random adult animal and add their species-specified number of babies to the collection
	bool addRandomBabies();

	//Select a random animal to get sick and die
	bool sickAnimal();

	//Check if out of money and game over
	bool isgameOver();

	//Destructor
	~Zoo();

};
#endif


/********************
** Description: This is the class specification file for the Zoo's UI
********************/

#ifndef ZOOUI_HPP
#define ZOOUI_HPP

class ZooUI : public Zoo
{
private:
	//Three option menu with input validation
	int threeOptionMenu(std::string a, std::string b, std::string c);

	//Three option menu with input validation
	int twoOptionMenu(std::string a, std::string b);

	//One option menu with positive integer input validation
	int oneOptionMenu(std::string a);

	//Function to get a user's input and check if it is a positive integer. It will return the integer if valid.
	int validatePositive();

	/*Function to get a user's input and check that it is >=lower and <=upper. 
	 *It will return the integer if valid.
	 *Precondition: Lower < Upper
	 */
	int validatePositiveRange(int lower, int upper);

public:
	//Constructor
	ZooUI() : Zoo() {};

	//Initial animal buying
	void initialBuy();

	//Holds each day's events
	void dailyEvents();

	//Execute random event
	void randomEvent();

	//Display game over message
	void gameOver();

};
#endif