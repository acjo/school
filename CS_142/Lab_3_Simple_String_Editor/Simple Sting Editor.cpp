#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {

	string editStr = "A"; // string that gets edited
	string insertStr = "B"; // input text for second if-else statement (gets inserted into editString)
	string findOrCopy = "C"; // input text activates 3rd if-else statement (either find or copy)
	string findThisText = "D"; // string is the userinput for what they want to find/copy/replace/delete
	string findDeleteReplace = "E"; // string activates find/delete/replace imbedded if statements for find, Delete , & Replace
	string replacementStr = "F"; // stringreplaces the "find" string in the 3rd imbedded if statement.
	char userYN1 = 'a'; // activates first if-else statement (y/n)
	char userYN2 = 'a'; // activates second if-else statement (y/n)
	int insertInt = 0; // Where the user wants to insert insertString into editString
	int editStrSize = 0; //size of editString
	int userIndexFind = 0; // the index of where "find" was found at
	int copyPosition = 0; // the index of the copy
	int copyLength = 0; // the length of the copy
	int pastePosition = 0; // where the copied text will be inserted and pasted

	cout << "Welcome to the Simple Editor. Enter a string to be edited: " << endl;
	getline(cin, editStr);
	cout << editStr << endl;
	cout << endl;

	cout << "Do you want to make this string a sentence (y/n)? " << endl;
	cin >> userYN1;
	cin.ignore(1000, '\n');

	if (userYN1 == 'y') {
		editStr.at(0) = toupper(editStr.at(0));

		if (editStr.at(editStr.size() - 1) == '!' || editStr.at(editStr.size() - 1) == '.' || editStr.at(editStr.size() - 1) == '?') {
			cout << editStr << endl;
		}

		else {
			editStr = editStr.insert(editStr.size(), ".");
			cout << editStr << endl;
		}
	}

	cout << "Do you want to insert more text into your current text (y/n)? " << endl;
	cin >> userYN2;
	cin.ignore(1000, '\n');

	if (userYN2 == 'y') {
		cout << "Enter text to be inserted:" << endl;
		getline(cin, insertStr);
		cout << "Enter position where text is to be inserted: " << endl;
		cin >> insertInt;
		cin.ignore(1000, '\n');

		if (insertInt > editStr.size() || insertInt < 0) {
			editStrSize = editStr.size();
			cout << "No change made. Position must be non-negative and not exceed ";
			cout << editStrSize << ", the length of the current text." << endl;
			cout << endl;
		}

		else {
			editStr = editStr.insert(insertInt, insertStr);
			cout << editStr << endl;
		}
	}

	cout << "If you would like to find/replace or copy/paste, enter find or copy:" << endl;
	cin >> findOrCopy;
	cin.ignore(1000, '\n');

	if (findOrCopy == "find") {
		cout << "Enter substring to find:" << endl;
		getline(cin, findThisText);
		cout << "Do you want to find if/where the substring occurs, delete it, or replace it (find, delete, replace)? " << endl;
		cin >> findDeleteReplace;
		cin.ignore(1000, '\n');

		if (findDeleteReplace == "find") {

			if (editStr.find(findThisText) != string::npos) {
				userIndexFind = editStr.find(findThisText);
				cout << findThisText << " was found at position " << userIndexFind << "." << endl;
			}

			else {
				cout << findThisText << " was not found." << endl;
			}
		}

		if (findDeleteReplace == "delete") {

			if (editStr.find(findThisText) != string::npos) {
				editStr = editStr.erase(editStr.find(findThisText), findThisText.size());
			}

			else {
				cout << findThisText << " was not found. No change made." << endl;
			}
		}

		if (findDeleteReplace == "replace") {

			if (editStr.find(findThisText) != string::npos) {
				cout << "Enter replacement string: " << endl;
				getline(cin, replacementStr);
				editStr.replace(editStr.find(findThisText), findThisText.size(), replacementStr);
			}

			else {
				cout << findThisText << " was not found. No change made." << endl;
			}
		}
	}

	else if (findOrCopy == "copy") {
		cout << "Enter position and length of text to be copied, and position for paste: " << endl;
		cin >> copyPosition;
		cin.ignore(1000, '\n');
		cin >> copyLength;
		cin.ignore(1000, '\n');
		cin >> pastePosition;
		cin.ignore(1000, '\n');

		if (copyPosition < (editStr.size() - 1) && pastePosition < (editStr.size() - 1)
			&& copyLength < (editStr.size() - 1 - copyPosition)) { // make lines less than 120 characters
			editStr = editStr.insert(pastePosition, editStr.substr(copyPosition, copyLength));
		}

		else {
			cout << "Values entered do not support copy/paste." << endl;
		}
	}

	cout << "Final text is" << endl;
	cout << editStr << endl;

	return 0;
}