#include <iostream>
#include <vector>

using namespace std;

int main() {

	const int VECTOR_SIZE = 5;
	vector <int> jerseyNumbers(VECTOR_SIZE);
	vector <int> playerRatings(VECTOR_SIZE);
	vector <char> menu{ 'a', 'd', 'u', 'r', 'o', 'q' };
	unsigned int i = 0;
	bool quit = false;
	char menuOption = 'e';
	int tempVal1 = 0;
	int tempVal2 = 0;

	for (i = 0; i < jerseyNumbers.size(); ++i) {
		cout << "Enter player " << i + 1 << "'s jersey number: " << endl;
		cin >> jerseyNumbers.at(i);
		cout << "Enter player " << i + 1 << "'s rating: " << endl;
		cin >> playerRatings.at(i);
		cout << endl;
	}
	cout << endl;
	cout << "ROSTER" << endl;


	for (i = 0; i < jerseyNumbers.size(); ++i) {
		cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNumbers.at(i) << ", Rating: " << playerRatings.at(i);
		cout << endl;
	}

	cout << endl;

	do {

		cout << "MENU" << endl;
		cout << "a - Add player" << endl;
		cout << "d - Remove player" << endl;
		cout << "u - Update player rating" << endl;
		cout << "r - Output players above a rating" << endl;
		cout << "o - Output roster" << endl;
		cout << "q - Quit" << endl;
		cout << endl;
		cout << "Choose an option :" << endl;


		cin >> menuOption;


		if (menuOption == menu.at(5)) {
			quit = true;
		}
		else if (menuOption == menu.at(0)) {
			cout << endl;
			cout << "Enter another player's jersey number: " << endl;
			cin >> tempVal1;
			cout << "Enter another player's rating: " << endl;
			cin >> tempVal2;
			jerseyNumbers.push_back(tempVal1);
			playerRatings.push_back(tempVal2);
			cout << endl;
		}
		else if (menuOption == menu.at(1)) {
			cout << "Enter a jersey number: " << endl;
			cin >> tempVal1;
			i = 0;
			while (i < jerseyNumbers.size()) {
				if (jerseyNumbers.at(i) == tempVal1) {
					jerseyNumbers.erase(jerseyNumbers.begin() + i);
					playerRatings.erase(playerRatings.begin() + i);
					i = jerseyNumbers.size();
				}
				++i;
			}
			cout << endl;
		}
		else if (menuOption == menu.at(2)) {
			cout << "Enter a jersey number: " << endl;
			cin >> tempVal1;
			cout << "Enter a new rating for player: " << endl;
			cin >> tempVal2;
			for (i = 0; i < jerseyNumbers.size(); ++i) {
				if (jerseyNumbers.at(i) == tempVal1) {
					jerseyNumbers.erase(jerseyNumbers.begin() + i);
					playerRatings.erase(playerRatings.begin() + i);
					jerseyNumbers.insert(jerseyNumbers.begin() + i, tempVal1);
					playerRatings.insert(playerRatings.begin() + i, tempVal2);
					i = jerseyNumbers.size();
				}
			}
			cout << endl;
		}
		else if (menuOption == menu.at(3)) {
			cout << "Enter a rating: " << endl;
			cin >> tempVal1;
			cout << endl;
			cout << "ABOVE " << tempVal1 << endl;
			for (i = 0; i < jerseyNumbers.size(); ++i) {
				if (playerRatings.at(i) > tempVal1) {
					cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNumbers.at(i);
					cout << ", Rating: " << playerRatings.at(i) << endl;
				}
			}
			cout << endl;
		}
		else if (menuOption == menu.at(4)) {
			cout << "ROSTER" << endl;
			for (i = 0; i < jerseyNumbers.size(); ++i) {
				cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNumbers.at(i) << ", Rating: " << playerRatings.at(i);
				cout << endl;
			}
			cout << endl;

		}

	} while (quit == false);




	return 0;
}