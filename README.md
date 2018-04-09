# Zoo Tycoon

This program is a simulation of a Zoo tycoon game utilizing classes and Inheritance. Zoo tycoon is a game that allows players to run a zoo business. Different types of animals cost different prices, have different maintenance costs, and of course, return a different profit at the end of each day. For this game, the player will be the proud owner of a virtual zoo that has spaces to house tigers, penguins and turtles.

Animal Class

The Animal class has the following member variables:

    Age
        Adult if age >= 3 days
        Baby if age < 3 days
    Cost
        Tiger cost $10,000
        Penguin cost $1,000
        Turtle cost $100
    Number of Babies
        Tigers have 1 baby
        Penguins have 5 babies
        Turtles have 10 babies
    Base Food Cost: $10
        Tigers have a feeding cost of 5 times the base cost
        Penguins have a feeding cost that is the same as the base cost
        Turtles have a feeding cost that is 50% the base cost
    Payoff
        A tiger’s payoff per day is 20% of their cost per animal. (not counting bonus)
        A penguin’s payoff per day is 10% of their cost per animal
        A turtle’s payoff per day is 5% of their cost per animal
        
The player begins with 100,000 dollars. At the start, the user needs to buy three types of animals (tigers, penguins, turtles) to start the business. Each type should have a quantity of either 1 or 2. For each animal bought, the cost is subtracted from the bank. All newly bought animals are 1 day old.

Each turn is a “day”. At the beginning of the day, all animals increase age by 1 day, and the user needs to pay the feeding cost of each animal. Feeding is required so the animals don’t die. After the feeding cost is subtracted from the bank, one randomized event takes place during the day.

Random Events:

    A sickness occurs to an animal in the zoo:
        Pick an animal at random that will die
        Remove one animal of that type from the exhibit.
        
    A boom in zoo attendance occurs:
        Generate a random bonus for the day, 250-500 dollars for each tiger in the zoo
        Add the bonus payoff for each tiger to the total payoff of the day as a reward
        
    A baby animal is born:
        Pick an animal at random to have a baby
        Check if there is an animal old enough to be a parent (age >= 3), add babies to
        the zoo depending on the “number of babies” specific to the type of animal. If 
        no animal is old enough of the randomly selected type, pick another type of 
        animal. Baby animals start at age 0. One adult animal is good enough to have babies.
        
    Nothing Happens

After the random event, the profit for the day is calculated based on the number of each animals and their payoff. If there is a bonus for the day, it is added to the profit as well. Before the day ends, the player is asked if they would like to buy an adult animal. If they do, the game asks the player for the type of animal they would like, then adds the animal to the zoo and subtract that cost from the bank. The adult animal that is bought will be 3 days old.

After the end of a day (the end of the game play loop), user is prompted whether to keep playing or end the game. If the user has no money, a message is printed telling the user the game is over, and the game ends.

## Installing and Running the Program

Compile the program with this command:

```
make zootycoon
```

Run the program with this command:

```
./zootycoon
```

Clean files with this command:

```
make clean
```

## Built With

* C++
