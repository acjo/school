/*Manually found inputs.
after iteration 1:
[1][0] = 0.000
[1][1] = 25.000
[1][2] = 25.000
[2][1] = 0.000
[2][2] = 0.000

after iteration 2:
[1][0] = 0.000
[1][1] = 31.250
[1][2] = 37.500
[2][1] = 6.250
[2][2] = 6.250
*/

#include <iostream>
#include <ios>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {

	const double ALLOWED_DIFFERENCE = 0.1;
	const int WIDTH = 9;
	const int PRECISION = 3;
	const int NUM_ROWS = 10;
	const int NUM_COLS = 10;
	double steadyStateTemp[NUM_ROWS][NUM_COLS];
	double tempArray[NUM_ROWS][NUM_COLS];
	double differenceArray[NUM_ROWS][NUM_COLS];
	bool iterate = true;
	double maxDifference = 0.0;
	ofstream outputFile;
	ifstream inputFile;
	int inputIterations = 3;
	unsigned int i;
	double topBoundaryCondition = 100.0;
	double sideBoundaryCondition = 0.0;

	for (int row = 0; row < NUM_ROWS; ++row) {
		for (int col = 0; col < NUM_COLS; ++col) {
			if (col > 0 && col < (NUM_COLS - 1) &&
				(row == 0 || row == (NUM_ROWS - 1))) {
				steadyStateTemp[row][col] = topBoundaryCondition;
			}
			else {
				steadyStateTemp[row][col] = sideBoundaryCondition;
			}
		}
	}

	for (int row = 0; row < NUM_ROWS; ++row) {
		for (int col = 0; col < NUM_COLS; ++col) {
			tempArray[row][col] = steadyStateTemp[row][col];
		}
	}

	cout << "Hotplate simulator" << endl;
	cout << endl;
	cout << "Printing initial plate..." << endl;
	cout << fixed << setprecision(PRECISION);

	for (int row = 0; row < NUM_ROWS; ++row) {
		for (int col = 0; col < NUM_COLS; ++col) {
			if (col < NUM_COLS - 1) {
				cout << setw(WIDTH) << steadyStateTemp[row][col] << ",";
			}
			else {
				cout << setw(WIDTH) << steadyStateTemp[row][col] << endl;
			}
		}
	}

	for (int row = 0; row < NUM_ROWS; ++row) {
		for (int col = 0; col < NUM_COLS; ++col) {
			if (row == 0 || col == 0 || row == NUM_ROWS - 1 || col == NUM_COLS - 1) {
				continue;
			}

			steadyStateTemp[row][col]
				= (tempArray[row - 1][col]
					+ tempArray[row + 1][col]
					+ tempArray[row][col - 1]
					+ tempArray[row][col + 1]) / 4;

		}
	}

	cout << endl;
	cout << "Printing plate after one iteration..." << endl;

	for (int row = 0; row < NUM_ROWS; ++row) {
		for (int col = 0; col < NUM_COLS; ++col) {
			if (col < NUM_COLS - 1) {
				cout << setw(WIDTH) << steadyStateTemp[row][col] << ",";
			}
			else {
				cout << setw(WIDTH) << steadyStateTemp[row][col] << endl;
			}
		}
	}

	for (int row = 0; row < NUM_ROWS; ++row) {
		for (int col = 0; col < NUM_COLS; ++col) {
			tempArray[row][col] = steadyStateTemp[row][col];
		}
	}

	while (iterate) {

		for (int row = 0; row < NUM_ROWS; ++row) {
			for (int col = 0; col < NUM_COLS; ++col) {
				if (row == 0 || col == 0 || row == NUM_ROWS - 1 || col == NUM_COLS - 1) {
					continue;
				}

				steadyStateTemp[row][col]
					= (tempArray[row - 1][col]
						+ tempArray[row + 1][col]
						+ tempArray[row][col - 1]
						+ tempArray[row][col + 1]) / 4;
			}
		}

		for (int row = 0; row < NUM_ROWS; ++row) {
			for (int col = 0; col < NUM_COLS; ++col) {
				differenceArray[row][col] = (steadyStateTemp[row][col] - tempArray[row][col]);
			}
		}

		maxDifference = differenceArray[0][0];
		for (int row = 0; row < NUM_ROWS; ++row) {
			for (int col = 0; col < NUM_COLS; ++col) {
				if (maxDifference < differenceArray[row][col]) {
					maxDifference = differenceArray[row][col];
				}
			}
		}

		if (maxDifference < ALLOWED_DIFFERENCE) {
			iterate = false;
		}
		else {
			for (int row = 0; row < NUM_ROWS; ++row) {
				for (int col = 0; col < NUM_COLS; ++col) {
					tempArray[row][col] = steadyStateTemp[row][col];
				}
			}
		}
	}

	cout << endl;
	cout << "Printing final plate..." << endl;

	for (int row = 0; row < NUM_ROWS; ++row) {
		for (int col = 0; col < NUM_COLS; ++col) {
			if (col < NUM_COLS - 1) {
				cout << setw(WIDTH) << steadyStateTemp[row][col] << ",";
			}
			else {
				cout << setw(WIDTH) << steadyStateTemp[row][col] << endl;
			}
		}
	}

	cout << endl;
	cout << "Outputting final plate to file \"Hotplate.csv\"..." << endl;

	outputFile.open("Hotplate.csv");
	if (!outputFile.is_open()) {
		cout << "Could not open file myoutfile.txt." << endl;
		return 1;
	}

	outputFile << fixed << setprecision(PRECISION);
	for (int row = 0; row < NUM_ROWS; ++row) {
		for (int col = 0; col < NUM_COLS; ++col) {
			if (col < NUM_COLS - 1) {
				outputFile << setw(WIDTH) << steadyStateTemp[row][col] << ",";
			}
			else {
				outputFile << setw(WIDTH) << steadyStateTemp[row][col] << endl;
			}
		}
	}
	outputFile.close();

	inputFile.open("Inputplate.txt");
	if (!inputFile.is_open()) {
		cout << "Could not open file Inputplate.txt." << endl;
		return 1;
	}

	for (int row = 0; row < NUM_ROWS; ++row) {
		for (int col = 0; col < NUM_COLS; ++col) {
			inputFile >> steadyStateTemp[row][col];
		}
	}

	inputFile.close();

	for (int row = 0; row < NUM_ROWS; ++row) {
		for (int col = 0; col < NUM_COLS; ++col) {
			tempArray[row][col] = steadyStateTemp[row][col];
		}
	}

	for (i = 0; i < inputIterations; ++i) {

		for (int row = 0; row < NUM_ROWS; ++row) {
			for (int col = 0; col < NUM_COLS; ++col) {
				if (row == 0 || col == 0 || row == NUM_ROWS - 1 || col == NUM_COLS - 1) {
					continue;
				}

				steadyStateTemp[row][col]
					= (tempArray[row - 1][col]
						+ tempArray[row + 1][col]
						+ tempArray[row][col - 1]
						+ tempArray[row][col + 1]) / 4;
			}
		}

		if (i < (inputIterations - 1)) {
			for (int row = 0; row < NUM_ROWS; ++row) {
				for (int col = 0; col < NUM_COLS; ++col) {
					tempArray[row][col] = steadyStateTemp[row][col];
				}
			}
		}
	}

	cout << endl;
	cout << "Printing input plate after 3 updates..." << endl;

	for (int row = 0; row < NUM_ROWS; ++row) {
		for (int col = 0; col < NUM_COLS; ++col) {
			if (col < NUM_COLS - 1) {
				cout << setw(WIDTH) << steadyStateTemp[row][col] << ",";
			}
			else {
				cout << setw(WIDTH) << steadyStateTemp[row][col] << endl;
			}
		}
	}

	return 0;
}