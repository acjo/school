#include <iostream>
#include <string>
using namespace std;

int main() {
	const string RANDOM_CHARS = "nai2f7!98qwrf$$NF*@Bsgh#aef51@3syvbQ0zjbalsjgas5ac245ff&*lasgaoygf334dbaljhc%Dd";
	int userKey = 0;
	string inputString = "A";
	string encodedString;
	unsigned int i = 0;
	char userChoice = 'a';
	bool iterate = false;

	cout << "--Word Encoder--" << endl;
	cout << "Enter a key: " << endl;
	cin >> userKey;
	cin.ignore();
	cout << "Enter the text to be encoded: " << endl;
	cin >> inputString;
	cin.ignore();


	for (i = 0; i < inputString.size(); ++i) {
		encodedString += RANDOM_CHARS.substr(encodedString.size() - i, userKey - 1) + inputString.substr(i, 1);
	}

	cout << "The encoded word is: " << encodedString << endl;
	cout << endl;
	cout << "Would you like to encode another word?(y/n)" << endl;
	cin >> userChoice;
	cin.ignore();

	if (userChoice == 'y' || userChoice == 'Y') {
		iterate = true;
	}

	while (iterate) {

		encodedString.clear();
		cout << "Enter a key: " << endl;
		cin >> userKey;
		cin.ignore();
		cout << "Enter the text to be encoded: " << endl;
		cin >> inputString;
		cin.ignore();

		for (i = 0; i < inputString.size(); ++i) {
			encodedString += RANDOM_CHARS.substr(encodedString.size() - i, userKey - 1) + inputString.substr(i, 1);
		}

		cout << "The encoded word is: " << encodedString << endl;
		cout << endl;
		cout << "Would you like to encode another word?(y/n)" << endl;
		cin >> userChoice;

		if (userChoice == 'n' || userChoice == 'N') {
			iterate = false;
		}
	}

	cout << "Thank you for using the encoder!" << endl;

	return 0;
}