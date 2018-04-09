/********************
** Author: Kelvin Lu
** Date: 10/16/2017
** Description: This is the class implementation file for the Animal class and all the species that inherit from the class.
********************/

#include "Animal.hpp"

/********************
** Description: This is the class implementation for the Animal class.
********************/


//One-parameter constructor for setting age
Animal::Animal(int a)
{
	age = a;
}

//Increase age by one
void Animal::increaseAge()
{
	age++;
}

//Getter function for age
int Animal::getAge()
{
	return age;
}

//Getter function for cost
int Animal::getCost()
{
	return cost;
}

//Getter function for number of babies
int Animal::getBabies()
{
	return babies;
}

//Getter function for food cost
int Animal::getFoodCost()
{
	return foodCost;
}

//Getter function for payoff
int Animal::getPayoff()
{
	return payoff;
}


/********************
** Description: This is the class implementation for the Tiger class.
********************/

//One-Paramter Constructor for setting values
Tiger::Tiger(int a) : Animal(a)
{
	cost = 10000;
	babies = 1;
	foodCost *= 5;
	payoff = 0.2 * cost;
	
}


/********************
** Description: This is the class implementation for the Penguin class.
********************/

//One-Paramter Constructor for setting values
Penguin::Penguin(int a) : Animal(a)
{
	cost = 1000;
	babies = 5;
	payoff = 0.1 * cost;
}


/********************
** Description: This is the class implementation for the Turtle class.
********************/

//One-Paramter Constructor for setting values
Turtle::Turtle(int a) : Animal(a)
{
	cost = 100;
	babies = 10;
	foodCost *= 0.5;
	payoff = 0.05 * cost;
}