//--------------------------------------------------------------
//File:     Homework3.cpp         
//By:      Caelan Osman         
//Date:  27 January 2020        
//This program recreates the game plinko where you attempt to win money by 
//dropping Chips into slots in an attempt to win money. We us the rand function is cstdlib to emulate
//the upredicatiblity of being able to win money. 
//--------------------------------------------------------------
#include <iostream> ///Access input-output abilities
#include <cstdlib> ///Using this to access Rand
#include <ios>///Ios and iomanip are bouth output manipulators where I can access fixed and set precision. 
#include <iomanip>

using namespace std; ///We want to be using the standard namespace to access these capablilities. 

double Winnings(const int finalSlot) { ///add this user defined function so we can make the code more concise (a recommend change)
	double roundWinnings = 0;
	const int WINNINGS[9] = { 100, 500, 1000, 0 , 10000, 0, 1000, 500, 100 }; ///This array holds the values of the winning 
	switch (finalSlot) { ///this switch statement will determine the winnings of the chip for the given slot choice
	case 0:
		roundWinnings = WINNINGS[0];
		break;
	case 1:
		roundWinnings = WINNINGS[1];
		break;
	case 2:
		roundWinnings = WINNINGS[2];
		break;
	case 3:
		roundWinnings = WINNINGS[3];
		break;
	case 4:
		roundWinnings = WINNINGS[4];
		break;
	case 5:
		roundWinnings = WINNINGS[5];
		break;
	case 6:
		roundWinnings = WINNINGS[6];
		break;
	case 7:
		roundWinnings = WINNINGS[7];
		break;
	case 8:
		roundWinnings = WINNINGS[8];
		break;
	}
	return roundWinnings; ///this is the return value that we set winnings equal to down below. 
}

int main() {
	bool runProgram = true; //Allows us to run the program and enter the while-loop
	int  userChoice = 0; ///UserChoice is a variable which stores the choice of the user for that particular round
	int slotChoice = 0;///The choice of slot the user chooses to put the chip into
	double plinkoPosition = 0.0;///Stores the plinko position as it falls and the final position
	const int ROW_NUM = 12;///The number of rows total the chip falls down.
	const int RANDOM_SEED = 42;///this is the seed for our rand function we could include ctime to make it more random but for error checking we make it constant
	srand(RANDOM_SEED);///setting our random function using the seed
	const int CHOICES[4] = { 1,2,3,4 }; ///the arrays I have here are suggestions some other people made, instead of having 22 additional variables
	///I can store them all here. This stores the choice values and each value is assigned a certain meaning
	const int SLOTS[9] = { 0,1,2,3,4,5,6,7,8 }; ///stores the slot numbers that you can start a chip out in. 
	double winnings = 0; ///stores the winnings of the player for that slot choice
	int numChips = 0;///stores the number of chips if the user selects dropping multiple chips
	double totalWinnings = 0.0;///the total winnings if the user choose to drop multiple chips
	double totalOverallWinnings = 0.0; ///the total overall winnings for the entire game
	double avgWinnings = 0.0; ///the average winnings for each play

	cout << "Welcome to the Plinko simulator! Enter 3 to see options." << endl;
	cout << endl;

	while (runProgram) { ///we will continue to play the game unless they want to stop
		cout << "Enter your selection now: ";
		cin >> userChoice;
		cout << endl;

		while (userChoice < CHOICES[0] || userChoice > CHOICES[3]) { ///This is error checking, to make sure they choose a valid option
			cout << "Invalid selection. Enter 3 to see options. " << endl;
			cout << endl;
			cout << "Enter your selection now: ";
			cin >> userChoice;
			cout << endl;
		}

		if (userChoice == CHOICES[0]) {
			cout << "*** Drop a single chip ***" << endl;
			cout << endl;
			cout << "Which slot do you want to drop the chip in (0-8)? ";
			cin >> slotChoice;
			cout << endl;

			if (slotChoice >= SLOTS[0] && slotChoice <= SLOTS[8]) { //error checking to make sure they have a slot choice within range
				//This outputs the path of the chip
				plinkoPosition = slotChoice;
				cout << "*** Dropping chip into slot " << slotChoice << " ***" << endl;
				cout << "Path: [" << fixed << setprecision(1) << plinkoPosition << ", ";

				for (int i = 0; i <= (ROW_NUM - 1); ++i) { ///will run through all the rows. 
					if (plinkoPosition > -0.1 && plinkoPosition < 0.1) {
						plinkoPosition += 0.5;
					}
					else if (plinkoPosition > 7.9 && plinkoPosition < 8.1) {
						plinkoPosition -= 0.5;
					}
					///for the if-else if statements we are just making sure the plinko actually stays in the allotted number of columns, 9.
					else {
						plinkoPosition += (rand() % 2) - 0.5;
					}
					///if the plinko is not on the edge this will dynamically determine and randomly determine the next position of the plinko

					cout << fixed << setprecision(1) << plinkoPosition; ///outputs position

					if (i < (ROW_NUM - 1)) { ///formatting for the output. 
						cout << ", ";
					}
				}
				cout << "]" << endl;

				plinkoPosition = static_cast<int>(plinkoPosition); ///casts the position to an int so we can safely compare in our Winnings function
				winnings = Winnings(plinkoPosition); ///calls our function to compute the winnings for this round
				totalOverallWinnings += winnings; ///adds winnings to the total overall winnings
				cout << "Winnings: $" << fixed << setprecision(2) << winnings << endl;
				///outputs the winnings of the chip to two decimal place precision.
				cout << endl;
			}
			else {
				cout << "Invalid slot." << endl; ///if they don't chose a position to start in the correct range it won't start. 
				cout << endl;
			}
		}

		if (userChoice == CHOICES[1]) { ///executes if the user chooses to drop mulitple chips
			cout << "*** Drop multiple chips ***" << endl;
			cout << endl;
			cout << "How many Chips do you want to drop (>0)? ";
			cin >> numChips;
			cout << endl;

			if (numChips > 0) { ///error checking, you can't drop negative chips
				cout << "Which slot do you want to drop the chip in (0-8)? ";
				cin >> slotChoice;
				cout << endl;

				if (slotChoice >= SLOTS[0] && slotChoice <= SLOTS[8]) { ///determines the plinkos final position which changes each iteration
					///of the for-loop
					plinkoPosition = slotChoice;

					for (int j = 0; j < numChips; ++j) {

						for (int i = 0; i <= (ROW_NUM - 1); ++i) {

							if (plinkoPosition > -0.1 && plinkoPosition < 0.1) {
								plinkoPosition += 0.5;
							}
							else if (plinkoPosition > 7.9 && plinkoPosition < 8.1) {
								plinkoPosition -= 0.5;
							}
							else {
								plinkoPosition += (rand() % 2) - 0.5;
							}
						}

						static_cast<int>(plinkoPosition);
						winnings = Winnings(plinkoPosition);
						static_cast<double>(plinkoPosition);
						plinkoPosition = slotChoice; ///resets the plinko position at the end of each loop. 
						totalWinnings += winnings;
					}
					totalOverallWinnings += totalWinnings;
					avgWinnings = totalWinnings / numChips; /// computes the avg winning for a single chip

					cout << "Total winnings on " << numChips << " chips: $" << fixed << setprecision(2) << totalWinnings << endl;
					cout << "Average winnings per chip: $" << avgWinnings << endl;
					cout << endl;
					totalWinnings = 0.0; ///resents total winnnings so the average doesn't get messed up if they choose 2 again. 
				}
				else { ///executes if the slot choice isn't in the correct range
					cout << "Invalid slot." << endl;
					cout << endl;
				}
			}
			else { ///executes if the chip number is invalid
				cout << "Invalid number of chips." << endl;
				cout << endl;
			}
		}

		if (userChoice == CHOICES[2]) { ///executes if the user choose to see the options
			cout << "Menu: Please select one of the following options: " << endl;
			cout << endl;
			cout << "1 - Drop a single chip into one slot" << endl;
			cout << "2 - Drop multiple chips into one slot" << endl;
			cout << "3 - Show the options menu" << endl;
			cout << "4 - Quit the program" << endl;
			cout << endl;
		}

		if (userChoice == CHOICES[3]) { ///will execute if the user chooses to quit the program changing the bool runProgram to false and 
			///exiting the while-loop
			runProgram = false;
		}
	}
	cout << "Your total winnings are: $" << totalOverallWinnings << "!" << endl; ///outputs total overall winnings this was another
	///recommend change by a user, before it was just outputting what you won each round not the total over all rounds. 
	cout << "Goodbye!" << endl;

	return 0;
}