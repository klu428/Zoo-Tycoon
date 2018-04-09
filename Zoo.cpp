/********************
** Author: Kelvin Lu
** Date: 10/16/2017
** Description: This is the class implementation file for the Zoo class.
********************/

#include "Zoo.hpp"
#include <stdlib.h>
#include <iostream>

//Constructor
Zoo::Zoo()
{
	numSpecies = 3;
	bank = 100000;
	dailyProfit = 0;
	for (int i = 0; i < numSpecies; i++)
	{
		initAnimal_DA(&zoo[i]);
	}
}

//Initalizes the dynamic array for animals
void Zoo::initAnimal_DA(Animal_DA* species)
{
	species->collection = new Animal*[10];
	species->size = 0;
	species->capacity = 10;
}



//Takes in an animal and their corresponding dynamic array and inserts that animal into the collection
void Zoo::addAnimal(Animal_DA* species, Animal* animal)
{
	//If array filled to max capacity, increase the array size
	if (species->size >= species->capacity)
	{
		incCapacity(species);
	}

	//Add the animal to the array
	species->collection[species->size] = animal;

	//Increase the size of the array by one
	species->size++;

}

//Buy an animal, if possible
bool Zoo::buyAnimal(Animal_DA* species, Animal* animal)
{
	int cost = animal->getCost();
	if (cost > bank )
	{
		return false;
	}
		
	bank -= cost;
	addAnimal(species, animal);	
	return true;

}


//Removes the animal at the desired index
void Zoo::removeAnimal(Animal_DA* species, int index)
{
	//Free memory used for animal
	delete species->collection[index];

	//Move the elements above the index back one index
	for (int i = index; i < species->size - 1; i++)
	{
		species->collection[i] = species->collection[i + 1];
	}

	//Decrease the size
	species->size--;
}

//Get an animal from the desired index
Animal * Zoo::getAnimal(Animal_DA* species, int index)
{
	return species->collection[index];
}

//Increase a collection's capacity
void Zoo::incCapacity(Animal_DA* species)
{
	//Create a new array with 2x the capacity
	Animal ** newArray = new Animal*[species->capacity * 2];

	//Add the contents from old array into new
	for (int i = 0; i < species->size; i++)
	{
		newArray[i] = species->collection[i];
	}

	//Delete the old array
	delete[] species->collection;

	//Point collection to new array
	species->collection = newArray;

	//Increase capacity size to new capacity
	species->capacity *= 2;
}

//Increase the age of every animal in the zoo
void Zoo::incAge()
{
	for(int i = 0; i < numSpecies; i++)
	{
		for (int j = 0; j < zoo[i].size; j++)
		{
			zoo[i].collection[j]->increaseAge();
		}
	}
}

//Calculate the daily profit without bonuses
int Zoo::getProfit()
{
	int total = 0;

	//Calculate profit for each collection by multiplying their size by the species' corresponding payoff
	for (int i = 0; i < 3; i++)
	{
		if (zoo[i].size != 0)
		{
			total += zoo[i].size * zoo[i].collection[0]->getPayoff();
		}
	}
	return total;
}

//Get the total feeding costs for the zoo
int Zoo::getFeedingCost()
{
	int total = 0;

	//Calculate feeding costs for each collection by multiplying their size by the species' corresponding food costs.
	for (int i = 0; i < 3; i++)
	{
		if (zoo[i].size != 0)
		{
			total += zoo[i].size * zoo[i].collection[0]->getFoodCost();
		}
	}
	return total;
}

//Get bonus payout for each tiger and add it to the daily profit
int Zoo::getBonus()
{
	//Choose a random number between 250 and 500
	int bonus = rand() % 251 + 250;

	//Add to the daily profit the bonus * the size of the tiger collection
	dailyProfit += zoo[TIGER].size * bonus;
	return bonus;
}

//Select a random adult animal and add their species-specified number of babies to the collection
bool Zoo::addRandomBabies()
{
	int hasAdult[4];
	int hasAdultSize = 0;

	//Find species that have adults and add them to a temporary array
	for (int i = 0; i < numSpecies; i++)
	{
		for (int j = 0; j < zoo[i].size; j++)
		{
			if (zoo[i].collection[j]->getAge() >= 3)
			{
				hasAdult[hasAdultSize] = i;
				hasAdultSize++;
				break;
			}
		}
	}

	if(hasAdultSize == 0)
	{
		return false;
	}

	//Randomly select a species from the species that has adults to have babies
	int choice = hasAdult[rand() % hasAdultSize];
	switch (choice)
	{
	case TIGER:
		for (int i = 0; i < zoo[TIGER].collection[0]->getBabies(); i++)
		{
			addAnimal(&zoo[TIGER], new Tiger(0));
		}
		break;
	case PENGUIN:
		for (int i = 0; i < zoo[PENGUIN].collection[0]->getBabies(); i++)
		{
			addAnimal(&zoo[PENGUIN], new Penguin(0));
		}
		break;
	case TURTLE:
		for (int i = 0; i < zoo[TURTLE].collection[0]->getBabies(); i++)
		{
			addAnimal(&zoo[TURTLE], new Turtle(0));
		}
	}

	return true;

}

//Select a random animal to get sick and die
bool Zoo::sickAnimal()
{
	int hasAnimal[4];
	int hasAnimalSize = 0;

	//Find species that have animals
	for (int i = 0; i < numSpecies; i++)
	{
			if (zoo[i].size > 0)
			{
				hasAnimal[hasAnimalSize] = i;
				hasAnimalSize++;
			}
	}

	//Randomly select an animal from a species that has animals to get sick
	if (hasAnimalSize > 0) {
		int choice = hasAnimal[rand() % hasAnimalSize];
		if (choice == TIGER)
		{

			removeAnimal(&zoo[TIGER], rand() % zoo[TIGER].size);
		}
		else if (choice == PENGUIN)
		{
			removeAnimal(&zoo[PENGUIN], rand() % zoo[PENGUIN].size);
		}
		else if (choice == TURTLE)
		{
			removeAnimal(&zoo[TURTLE], rand() % zoo[TURTLE].size);
		}

		return true;
	}

	return false;

}

//Check if the user has no money and the game ends
bool Zoo::isgameOver()
{
	if (bank <= 0)
	{
		return true;
	}
	return false;
}

//Destructor
Zoo::~Zoo()
{
	for (int i = 0; i < numSpecies; i++)
	{
		for (int j = 0; j < zoo[i].size; j++)
		{
			delete zoo[i].collection[j];
		}
		delete [] zoo[i].collection;
	}
}


/********************
** Description: This is the class implementation file for the ZooUI class.
********************/

//Three option menu with input validation
int ZooUI::threeOptionMenu(std::string a, std::string b, std::string c)
{
	std::cout << "1. " << a << std::endl;
	std::cout << "2. " << b << std::endl;
	std::cout << "3. " << c << std::endl;
	std::cout << "Please enter your choice: ";
	return validatePositiveRange(1, 3);
}

//Two option menu with input validation
int ZooUI::twoOptionMenu(std::string a, std::string b)
{
	std::cout << "1. " << a << std::endl;
	std::cout << "2. " << b << std::endl;
	std::cout << "Please enter your choice: ";
	return validatePositiveRange(1, 2);
}

//One option menu with positive integer input validation
int ZooUI::oneOptionMenu(std::string a)
{
	std::cout << a << ": ";
	return validatePositive();
}

//Function to get a user's input and check if it is a positive integer. It will return the integer if valid.
int ZooUI::validatePositive()
{
	std::string input;
	bool again;

	//Loop endlessly until user provides a valid input
	do
	{
		getline(std::cin, input);
		again = false;
		//If first character is 0 or the string is null, print error and have user re-enter input
		if (input.length() == 0 || input[0] == '0')
		{
			again = true;
		}

		//If any character is non-numerical, print error and have user re-enter input
		if (!again)
		{
			for (int i = 0; i < static_cast<int>(input.length()); i++)
			{
				if (!isdigit(input[i]))
				{
					again = true;
				}
			}
		}

		//If input passes all of the tests, return the input as an integer
		if (!again)
		{
			return stoi(input);
		}

		//If input did not pass all the tests, have user try again
		std::cout << "Invalid format- Please enter a positive integer: ";
	} while (again);

	//function should never reach here, but if it does restart
	return validatePositive();
}


/*Function to get a user's input and check that it is >=lower and <=upper.
*It will return the integer if valid.
*Precondition: Lower < Upper
*/
int ZooUI::validatePositiveRange(int lower, int upper)
{
	int input;
	bool rangeAgain = true;

	//Loop endlessly until user provides a valid input
	do
	{
		//validate input is a positive integer
		input = validatePositive();

		//Return input if input is within range
		if (input >= lower && input <= upper)
		{
			return input;
		}

		//If not, display this error message and prompt the user to try again
		std::cout << "Not in range- Please enter an integer between " << lower << " and " << upper << ": ";
	} while (rangeAgain);

	//function should never reach here, but if it does restart
	return validatePositiveRange(lower, upper);
}

//Initial animal buying
void ZooUI::initialBuy()
{
	std::cout << "How many tigers would you like to buy?" << std::endl;
	
	if(twoOptionMenu("One tiger", "Two tigers") == 2)
	{
		buyAnimal(&zoo[TIGER], new Tiger(1));
	}

	buyAnimal(&zoo[TIGER], new Tiger(1));

	std::cout << "How many penguins would you like to buy?" << std::endl;

	if (twoOptionMenu("One penguin", "Two penguins") == 2)
	{
		buyAnimal(&zoo[PENGUIN], new Penguin(1));
	}

	buyAnimal(&zoo[PENGUIN], new Penguin(1));

	std::cout << "How many turtles would you like to buy?" << std::endl;

	if (twoOptionMenu("One turtle", "Two turtles") == 2)
	{
		buyAnimal(&zoo[TURTLE], new Turtle(1));
	}

	buyAnimal(&zoo[TURTLE], new Turtle(1));
}


//Causes one of the four random events to occur
void ZooUI::randomEvent()
{

	switch (rand() % 4)
	{
	case 0:	//Sick animal
		if (sickAnimal())
		{
			std::cout << "One of your animals fell sick and died" << std::endl;
		}
		else
		{
			std::cout << "A bug was going around, but because you don't own any animals your zoo wasn't affected" << std::endl;
		}
		break;

	case 1:	//Boom in Zoo attendance
		std::cout << "Your zoo is booming today! You made " << getBonus() << " extra dollars for each tiger you own :)" << std::endl;		
		break;

	case 2:	//Animal had babies
		if (addRandomBabies())
		{
			std::cout << "Congratulations! One of your animals had babies" << std::endl;
		}
		else
		{
			std::cout << "Your animals can't wait to get older" << std::endl;
		}
		break;
	default:
		std::cout << "Nothing out of the ordinary happened today." << std::endl;
	}
}

//Daily Events
void ZooUI::dailyEvents()
{
	bool again = true;
	int feedingCost;
	bool enoughMoney;
	Animal* newAnimal;
	
	while (again && !isgameOver())
	{
		dailyProfit = 0;
		
		//Increase the age of each animal
		incAge();

		//Feed the animals, take the total feeding costs out of the bank
		feedingCost = getFeedingCost();
		std::cout << "The cost to feed your animals for the day is: " << feedingCost << std::endl;
		bank -= feedingCost;

		//Execute a random event
		randomEvent();

		//Add the daily profit to the bank
		dailyProfit += getProfit();
		std::cout << "Your daily profit for the day is $" << dailyProfit << std::endl;
		bank += dailyProfit;

		//Buy an animal if player has enough money
		do
		{
			enoughMoney = true;
			std::cout << "You currently have $" << bank << " in the bank, would you like to buy an adult animal?" << std::endl;
			if (twoOptionMenu("Yes", "No") == 1)
			{

				std::cout << "Which animal would you like to buy?" << std::endl;
				int choice = threeOptionMenu("Tiger", "Penguin", "Turtle");
				switch(choice)
				{
				case 1: //Buy a tiger
					newAnimal = new Tiger(3);
					enoughMoney = buyAnimal(&zoo[TIGER], newAnimal);
					break;
				case 2: //Buy a penguin
					newAnimal = new Penguin(3);
					enoughMoney = buyAnimal(&zoo[PENGUIN], newAnimal);
					break;
				case 3: //Buy a turtle
					newAnimal = new Turtle(3);
					enoughMoney = buyAnimal(&zoo[TURTLE], newAnimal);
				}

				if (!enoughMoney)
				{
					std::cout << "Not enough money. Please try again." << std::endl;
					delete newAnimal;
				}
			}
		} while (!enoughMoney);

		//Ask if user wants to play another round
		std::cout << "Play another round?" << std::endl;
		if(twoOptionMenu("Yes", "No") == 2)
		{
			again = false;
		}
	}
}

void ZooUI::gameOver()
{
	std::cout << "GAME OVER" << std::endl;
}
