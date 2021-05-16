/*
 * See power of two function for comments on the checking power of two algorithm.
 *
 * Test Case 1:
 * Inputs: leave, add, Bajios, add, Bam Bams, add, 5 star, add, Tsunami, add R&R, add Blue Lemon, add Taco Bell, shuffle, battle, remove, 5 Star,
 * add, SubWay, battle, 1, 1, 2, 1, 2, three, four, 6, 1, 1, quit
 * Expected Output: leave was shown to be an invalid option, first 7 restaurants added, shuffle & battle shown to be not allowed, cannot remove 5 Star
 * as it was never added, add SubWay, then we can battle, the first 5 numbers are good, cannot accept three, four, 6, accepts last two number,
 * prints winner - 5 star, and quits the program
 * My Results: the options menu, add, remove, and shuffle worked flawlessly battle took me a while to figure out.
 *
 * Test Case 2:
 * Inputs: options, Add, add, subway, subway, add, Wendy's, remove, Subway, shuffle,  quit
 * Expected Output: options menu, Add is not a valid entry, adds subway, cannot re-add subway, adds Wendy's, cannot remove Subway,  shuffles Wendy's and Subway,
 * quit program
 * My Results: again, add, remove, and shuffle works well.
 *
 * Test Case 3:
 * input: options, add, Cannon Center, add, Habit, add, Dominos, add, Papa Johns, add, Grand America, cut, 6, three, 3, shuffle, remove, Grand America, battle,
 * 1, 2, 1, 1, quit
 * Expected Output: options menu, adds 5 restaurants. cut needs to between 0 and 5 (twice), puts Cannon Center, Habit, Dominos on bottom. cannot shuffle,
 * remove Grand America, battle, papa johns is the winning restaurant. invalid input, quit.
 * My Results: add, shuffle, remove, options work well, I had some issues with cut and battle, infinite loops when the user would enter an integer instead of a string.
 *
 * Overall Comments: Battle was by far the most difficult for me to get correctly. Initially, add, options, shuffle, remove, and display all worked great,
 * I had some issues with cut when people would enter a string it would give me an infinite loop, so I had to modify the input to be a string and convert
 * the string to an integer using atoi. Although in retrospect I could've just checked for "1" or "2" in the string instead of having to convert from string
 * to intger. Battle took me several hours to figure out and I ended up finding the solution I did. The function recurssively updates the vector itself until
 * the countdown is equal to one at which point it outputs the winning restaurant. I went through several solution paths until I settled on this one. I ended
 * up doing what I should've done in the cut vector and checked the string for "1" or "2" and if that was the case I converted the string value to an integer.
 * If it wasn't one of those values I output to try again until they entered the correct input.
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
using namespace std;

void OptionsMenu() {
	cout << "Please select one of the following options:" << endl;
	cout << endl;
	cout << "quit - Quit the program" << endl;
	cout << "display - Display all restaurants" << endl;
	cout << "add - Add a restaurant" << endl;
	cout << "remove - Remove a restaurant" << endl;
	cout << "cut - \"Cut\" the list of restaurants" << endl;
	cout << "shuffle - \"Shuffle\" the list of restaurants" << endl;
	cout << "battle - Begin the tournament" << endl;
	cout << "options - Print the options menu" << endl;
	cout << endl;
	return;
}

int NameInRestaurants(const string nameToAdd, const vector<string>& restaurants) {
	unsigned int i = 0;
	int allowAdd = restaurants.size();
	for (i = 0; i < restaurants.size(); ++i) {
		if (nameToAdd == restaurants.at(i)) {
			allowAdd = i;
		}
	}
	return allowAdd;
}

void AddRestaurant(vector<string>& restaurants) {
	unsigned int i = 0;
	string add;
	cout << "What is the name of the restaurant you want to add?" << endl;
	getline(cin, add);
	i = NameInRestaurants(add, restaurants);
	if (i == restaurants.size()) {
		restaurants.push_back(add);
		cout << add << " has been added." << endl;
	}
	else {
		cout << "That restaurant is already in the list, you can not add it again." << endl;
	}
	return;
}

void RemoveRestaurant(vector<string>& restaurants) {
	unsigned int i = 0;
	string remove;
	cout << "What is the name of the restaurant you want to remove?" << endl;
	getline(cin, remove);
	i = NameInRestaurants(remove, restaurants);
	if (i != restaurants.size()) {
		restaurants.erase(restaurants.begin() + i);
		cout << remove << " has been removed." << endl;
	}
	else {
		cout << "That restaurant is not in the list, you can not remove it." << endl;
	}
	return;
}

void DisplayRestaurants(const vector<string>& restaurants) {
	unsigned int i;
	cout << "Here are the current restaurants:" << endl;
	cout << endl;
	for (i = 0; i < restaurants.size(); ++i) {
		cout << "\t" << "\"" << restaurants.at(i) << "\"" << endl;
	}
	return;
}

void CutRestaurant(vector<string>& restaurants) {
	string cutNumber;
	int convertedNumber;
	unsigned int i = 0;
	cout << "How many restaurants should be taken from the top and put on the bottom?" << endl;
	cin >> cutNumber;
	cin.ignore();
	convertedNumber = atoi(cutNumber.c_str());
	while (convertedNumber < 0 || convertedNumber > restaurants.size() || isalpha(cutNumber.at(0))) {
		cout << "The cut number must be between 0 and " << restaurants.size() << endl;
		cout << "How many restaurants should be taken from the top and put on the bottom?" << endl;
		cin >> cutNumber;
		cin.ignore();
		convertedNumber = atoi(cutNumber.c_str());
	}
	vector<string> cutVector(restaurants.size() - convertedNumber);
	for (i = 0; i < cutVector.size(); ++i) {
		cutVector.at(i) = restaurants.at(convertedNumber + i);
	}
	for (i = 0; i < convertedNumber; ++i) {
		cutVector.push_back(restaurants.at(i));
	}
	for (i = 0; i < restaurants.size(); ++i) {
		restaurants.at(i) = cutVector.at(i);
	}
	return;
}

bool PowerOfTwo(int numberToCheck) {
	double numToCheck = log2(numberToCheck);		  // log2 will return an integer if the number to check is a power of two. 
	if (numToCheck == static_cast<int>(numToCheck)) { // We check this by seeing if numToCheck is the same as static casting it to an integer.   
		return true;                                  // If it is, we return true to the boolean governing the if - statement in the shuffle 
	}                                                 // or battle sections in the menu. If the double casted to an int is not the same the    
	else {                                            // function will return false to the boolean not allowing us to shuffle or battle. 
		return false;
	}
}

void ShuffleRestaurants(vector<string>& restaurants) {
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int finalSize = restaurants.size();
	unsigned int shuffleSize = (restaurants.size() / 2);
	vector<string> shuffle(shuffleSize);
	for (i = 0; i < shuffle.size(); ++i) {
		shuffle.at(i) = restaurants.at(i + shuffleSize);
	}
	for (i = 0; i < shuffleSize; ++i) {
		restaurants.insert(restaurants.begin() + (i * 2), shuffle.at(i));
	}
	restaurants.resize(finalSize);
	return;
}

int GetChoice(string one, string two) {
	string input;
	for (;;) {
		cout << "Type \"1\" if you prefer " << one << " or" << endl;
		cout << "Type \"2\" if you prefer " << two << endl;
		cout << "Choice: " << endl;
		int choice;
		cin >> input;
		cin.ignore();
		if (input == "1" || input == "2") {
			choice = stoi(input);
			return choice;
		}
		cout << "Invalid choice" << endl;
	}
}

string BattleRestaurants(int round, const vector<string>& restaurants) {
	int countDown = restaurants.size() / 2;
	vector<string> battleResults(restaurants.size() / 2);
	int count = 0;

	cout << "Round: " << round << endl << endl;

	for (int i = 0; i < restaurants.size(); i += 2) {
		int choice = GetChoice(restaurants.at(i), restaurants.at(i + 1));
		if (choice == 1) {
			battleResults[count++] = restaurants[i];
		}
		else {
			battleResults[count++] = restaurants[i + 1];
		}
	}

	if (countDown > 1) {
		return BattleRestaurants(round + 1, battleResults);
	}
	return battleResults[0];
}

int main() {
	string userChoice = "A";
	bool run = true;
	bool shuffleOrBattle = false;
	vector<string> restaurants(0);
	string battleWinner;

	cout << "Welcome to the restaurant battle! Enter \"options\" to see options." << endl;
	cout << endl;
	cout << "Enter your selection: " << endl;
	cin >> userChoice;
	cin.ignore();

	while (run) {

		if (userChoice != "quit" && userChoice != "display" && userChoice != "add" && userChoice != "remove" && userChoice != "cut"
			&& userChoice != "shuffle" && userChoice != "battle" && userChoice != "options") {
			cout << "Invalid Selection" << endl;
			OptionsMenu();
			cout << "Enter your selection: " << endl;
			cin >> userChoice;
			cin.ignore();
		}
		else if (userChoice == "quit") {
			run = false;
		}
		else if (userChoice == "options") {
			OptionsMenu();
			cout << "Enter your selection: " << endl;
			cin >> userChoice;
			cin.ignore();
		}
		else if (userChoice == "display") {
			DisplayRestaurants(restaurants);
			cout << endl;
			cout << "Enter your selection:" << endl;
			cin >> userChoice;
			cin.ignore();
		}
		else if (userChoice == "add") {
			AddRestaurant(restaurants);
			cout << endl;
			cout << "Enter your selection: " << endl;
			cin >> userChoice;
			cin.ignore();
		}
		else if (userChoice == "remove") {
			RemoveRestaurant(restaurants);
			cout << endl;
			cout << "Enter your selection: " << endl;
			cin >> userChoice;
			cin.ignore();
		}
		else if (userChoice == "cut") {
			CutRestaurant(restaurants);
			cout << endl;
			cout << "Enter your selection: " << endl;
			cin >> userChoice;
			cin.ignore();
		}
		else if (userChoice == "shuffle") {
			shuffleOrBattle = PowerOfTwo(restaurants.size());
			if (shuffleOrBattle) {
				ShuffleRestaurants(restaurants);
			}
			else {
				cout << "The current tournament size (" << restaurants.size() << ") is not a power of two (2, 4, 8...)." << endl;
				cout << "A shuffle is not possible. Please add or remove restaurants." << endl;
			}
			cout << endl;
			cout << "Enter your selection: " << endl;
			cin >> userChoice;
			cin.ignore();
		}
		else if (userChoice == "battle") {
			shuffleOrBattle = PowerOfTwo(restaurants.size());
			if (shuffleOrBattle) {
				battleWinner = BattleRestaurants(1, restaurants);
				cout << "The winning restaurant is " << battleWinner << ".";
			}
			else {
				cout << "The current tournament size (" << restaurants.size() << ") is not a power of two (2, 4, 8...)." << endl;
				cout << "A battle is not possible. Please add or remove restaurants." << endl;
			}
			cout << endl;
			cout << "Enter your selection: " << endl;
			cin >> userChoice;
			cin.ignore();
		}
		else {
			run = false;
		}
	}
	cout << "Goodbye!" << endl;

	return 0;
}