//--------------------------------------------------------------
//File:     Plinko.cpp         
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

int main() {
	bool runProgram = true; //Allows us to run the program
	int  userChoice = 0; ///UserChoice is a variable which stores the choice of the user for that particular round
	int slotChoice = 0;///The choice of slot the user chooses to put the chip into
	double plinkoPosition = 0.0;///Stores the plinko position as it falls and the final position
	const int ROW_NUM = 12;///The number of rows total the chip falls down.
	const int RANDOM_SEED = 42;///this is the seed for our rand function we could include ctime to make it more random but for error checking we make it constant
	srand(RANDOM_SEED);///setting our random function using the seed
	const int MENU_MAX = 4;
	const int MENU_MIN = 1;
	const int DROP_ONE_CHIP = 1;
	const int DROP_MULITPLE_CHIPS = 2;
	const int OPTIONS_INT = 3;
	const int QUIT_PROGRAM = 4; ///FIXME: making arrays
	const int SLOT_ZERO = 0;
	const int SLOT_ONE = 1;
	const int SLOT_TWO = 2;
	const int SLOT_THREE = 3;
	const int SLOT_FOUR = 4;
	const int SLOT_FIVE = 5;
	const int SLOT_SIX = 6;
	const int SLOT_SEVEN = 7;
	const int SLOT_EIGHT = 8;
	const int WINNINGS[9] = { 100, 500, 1000, 0 , 10000, 0, 1000, 500, 100 }; ///This is a change that was was suggested by someone I talked to who already knows a little c++, to make these into arrays
	const int WINNINGS_SLOT_ZERO = 100;
	const int WINNINGS_SLOT_ONE = 500;
	const int WINNINGS_SLOT_TWO = 1000;
	const int WINNINGS_SLOT_THREE = 0;
	const int WINNINGS_SLOT_FOUR = 10000;
	const int WINNINGS_SLOT_FIVE = 0;
	const int WINNINGS_SLOT_SIX = 1000;
	const int WINNINGS_SLOT_SEVEN = 500;
	const int WINNINGS_SLOT_EIGHT = 100;
	double winnings = 0; ///stores the winnings of the player
	int numChips = 0;///stores the number of chips if the user selects dropping multiple chips
	double totalWinnings = 0.0;///the total winnings saved as the player plays multiple iterations through the outer while-loop
	double avgWinnings = 0.0; ///the average winnings for each play

	cout << "Welcome to the Plinko simulator! Enter 3 to see options." << endl;
	cout << endl;
	
	while (runProgram) { ///we will continue to play the game unless they want to stop
		cout << "Enter your selection now: ";
		cin >> userChoice;
		cout << endl;

		while (userChoice < MENU_MIN || userChoice > MENU_MAX) { ///This is error checking, to make sure they choose a corect option
			cout << "Invalid selection. Enter 3 to see options. " << endl;
			cout << endl;
			cout << "Enter your selection now: ";
			cin >> userChoice;
			cout << endl;
		}

		if (userChoice == DROP_ONE_CHIP) {
			cout << "*** Drop a single chip ***" << endl;
			cout << endl;
			cout << "Which slot do you want to drop the chip in (0-8)? ";
			cin >> slotChoice;
			cout << endl;

			if (slotChoice >= SLOT_ZERO && slotChoice <= SLOT_EIGHT) {
				plinkoPosition = slotChoice;
				cout << "*** Dropping chip into slot " << slotChoice << " ***" << endl;
				cout << "Path: [" << fixed << setprecision(1) << plinkoPosition << ", ";

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

					cout << fixed << setprecision(1) << plinkoPosition;

					if (i < (ROW_NUM-1)) {
						cout << ", ";
					}
				}
				cout << "]" << endl;

				plinkoPosition = static_cast<int>(plinkoPosition);

				if (plinkoPosition == SLOT_ZERO) {
					winnings = WINNINGS_SLOT_ZERO;
				}
				else if (plinkoPosition == SLOT_ONE) {
					winnings = WINNINGS_SLOT_ONE;
				}
				else if (plinkoPosition == SLOT_TWO) {
					winnings = WINNINGS_SLOT_TWO;
				}
				else if (plinkoPosition == SLOT_THREE) {
					winnings = WINNINGS_SLOT_THREE;
				}
				else if (plinkoPosition == SLOT_FOUR) {
					winnings = WINNINGS_SLOT_FOUR;
				}
				else if (plinkoPosition == SLOT_FIVE) {
					winnings = WINNINGS_SLOT_FIVE;
				}
				else if (plinkoPosition == SLOT_SIX) {
					winnings = WINNINGS_SLOT_SIX;
				}
				else if (plinkoPosition == SLOT_SEVEN) {
					winnings = WINNINGS_SLOT_SEVEN;
				}
				else if (plinkoPosition == SLOT_EIGHT) {
					winnings = WINNINGS_SLOT_EIGHT;
				}

				cout << "Winnings: $" << fixed << setprecision(2) << winnings << endl;
				cout << endl;
			}
			else {
				cout << "Invalid slot." << endl;
				cout << endl;
			}
		}

		if (userChoice == DROP_MULITPLE_CHIPS) {
			cout << "*** Drop multiple chips ***" << endl;
			cout << endl;
			cout << "How many Chips do you want to drop (>0)? ";
			cin >> numChips;
			cout << endl;

			if (numChips > 0) {
				cout << "Which slot do you want to drop the chip in (0-8)? ";
				cin >> slotChoice;
				cout << endl;

				if (slotChoice >= SLOT_ZERO && slotChoice <= SLOT_EIGHT) {
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

						if (plinkoPosition == SLOT_ZERO) {
							winnings = WINNINGS_SLOT_ZERO;
						}
						else if (plinkoPosition == SLOT_ONE) {
							winnings = WINNINGS_SLOT_ONE;
						}
						else if (plinkoPosition == SLOT_TWO) {
							winnings = WINNINGS_SLOT_TWO;
						}
						else if (plinkoPosition == SLOT_THREE) {
							winnings = WINNINGS_SLOT_THREE;
						}
						else if (plinkoPosition == SLOT_FOUR) {
							winnings = WINNINGS_SLOT_FOUR;
						}
						else if (plinkoPosition == SLOT_FIVE) {
							winnings = WINNINGS_SLOT_FIVE;
						}
						else if (plinkoPosition == SLOT_SIX) {
							winnings = WINNINGS_SLOT_SIX;
						}
						else if (plinkoPosition == SLOT_SEVEN) {
							winnings = WINNINGS_SLOT_SEVEN;
						}
						else if (plinkoPosition == SLOT_EIGHT) {
							winnings = WINNINGS_SLOT_EIGHT;
						}

						static_cast<double>(plinkoPosition);
						plinkoPosition = slotChoice;

						totalWinnings += winnings;
					}

					avgWinnings = totalWinnings / numChips;

					cout << "Total winnings on " << numChips << " chips: $" << fixed << setprecision(2) << totalWinnings << endl;
					cout << "Average winnings per chip: $" << avgWinnings << endl;
					cout << endl;
					totalWinnings = 0.0;
				}
				else {
					cout << "Invalid slot." << endl;
					cout << endl;
				}
			}
			else {
				cout << "Invalid number of chips." << endl;
				cout << endl;
			}			
		}

		if (userChoice == OPTIONS_INT) {
			cout << "Menu: Please select one of the following options: " << endl;
			cout << endl;
			cout << "1 - Drop a single chip into one slot" << endl;
			cout << "2 - Drop multiple chips into one slot" << endl;
			cout << "3 - Show the options menu" << endl;
			cout << "4 - Quit the program" << endl;
			cout << endl;
		}
		
		if (userChoice == QUIT_PROGRAM) {
			runProgram = false;
		}
	}

	cout << "Goodbye!" << endl;

	return 0;
}