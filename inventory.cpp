#include<iostream>
using namespace std;

//global variable: seen and used by ALL functions
string inventory[10];

int main() {
	//local variables

	string input = "dummy";
	int room = 1;
	while (input != "quit") {// game loop
		//stuff here runs EVERY turn
		cout << endl << "-------------------------------------" << endl;
		cout << "your inventory:";
		for (int i = 0; i < 10; i++)
			cout << inventory[i] << " | ";
		cout << endl;

		switch (room) {
		case 1:
			cout << "you're in room 1 you can go east" << endl;
			if (inventory[0] != "fish")
				cout << "you found a fish" << endl;
			inventory[0] = "fish";
			cout << "there is a dusty rug on the floor" << endl;
			cin >> input;
			if (input == "east" || input == "go east")
				room = 2;
			if (input == "rug" || input == "look under rug") {
				if (inventory[2] != "key")
				cout << "you found a shiny key" << endl;
				inventory[2] = "key";
			}
			break;
		case 2:
			cout << "you're in room 2 you can go west or go north." << endl;
			if(inventory)
			cout << "you see a sword on the floor" << endl;
			cin >> input;
			if (input == "west" || input == "go west")
				room = 1;
			if (input == "north" || input == "go north")
				if (inventory[2] == "key") {
					cout << endl<< "you unlock the door with the key" << endl;
					inventory[2] = "";//erases the key from the inventory
					room = 3;
				}
				else {
					cout << "the door is locked womp womp" << endl;
				}
			if (input == "sword" || input == "pick up the sword" || input == "get sword") {
				inventory[1] = "sword";
				cout << "you picked up a sword" << endl;
			}
			break;
		case 3:
			cout << "you're in room 3, OMG THERES A DRAGON!!!" << endl;
			if (inventory[1] == "sword") {
				cout << "you slay the dragon with your sword and escape the castle" << endl;
				input = "quit";
				//return 0;// kills the program
			}
			else {
				cout << "you ded." << endl;
				input = "quit";
			}
			break;
		}

	}/// end of game loop
	cout << endl << "-------------------------------------------------" << endl;
	cout << "Thanks for playing" << endl;
}//end of main
