/********************
** Author: Kelvin Lu
** Date: 10/16/2017
** Description: This is the class specification file for the abstract Animal class and each species class that inherits from the animal class.
********************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
protected:
	int age;
	int cost;
	int babies;
	int foodCost = 10;
	int payoff;
public:
	//One-Parameter Constructor for setting age
	Animal(int a);

	//Increase age by one
	void increaseAge();

	//Getter function for age
	int getAge();

	//Getter function for cost
	int getCost();

	//Getter function for number of babies
	int getBabies();

	//Getter function for food cost
	int getFoodCost();

	//Getter function for payoff
	int getPayoff();

};


/********************
** Description: This is the class specification file for the Tiger class.
********************/


class Tiger : public Animal
{
public:
	//One-Paramter Constructor for setting values
	Tiger(int a);
};



/********************
** Description: This is the class specification file for the Penguin class.
********************/


class Penguin : public Animal
{
public:
	//One-Paramter Constructor for setting values
	Penguin(int a);
};



/********************
** Description: This is the class specification file for the Turtle class.
********************/


class Turtle : public Animal
{
public:
	//One-Paramter Constructor for setting values
	Turtle(int a);
};
#endif

