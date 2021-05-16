//--------------------------------------------------------------
// File: homework6.cpp
// By: Caelan Osman
// Date: 19 February
// This program reads in a set of data points from a file,
// then using newton-raphson iterations it computes the square root
// using f(x) = x^2 - r where r is the value we are trying to take
// a square root of. Note then when using linearizations, we get
// f'(x) = 2x
//--------------------------------------------------------------
#include <iostream>///access input output
#include <fstream>///access file input output
#include <vector>///vector library
#include <string>///string library
#include <iomanip>///input output manipulator
#include <ios>

using namespace std;///standard namespace containig ios, string, cout, etc.

typedef unsigned int uint;///creating a typdedef specifier for unsgined int

double ComputeSqrt( const double, double, double previousVal = 0 ); ///forward declaring our sqrt root computing funciton we are expecting the number
///to find a square root of, and an initial guess as arguments.

int main ()
{
	uint userChoice; ///stores if the user wants to find the square root of a number
	double getSqrt;///the number we want to find the square root of
	double numApprox = 0;///the square root of our number
	double initialGuess; ///stores our initial guess
	ifstream inputFile;///input and output variables
	ofstream outputFile;
	vector<double> sqrtArray; ///this will hold all the square root values, from our input file we are doing string so that we can hold i.
	vector<string> fileNames = { "testnumbers.txt", "sqrtoutputs.txt" }; /// this vector holds all of our file names
	cout << "Would you like to calculate a square root?" << endl; ///asks if they want to take the square root of a value
	cout << "Enter 1 for true and 0 for false ";
	cin >> userChoice;///stores the choice


	while ( userChoice )///checkes if the user wants to take a new square root or not
	{

		cout << "Enter a number you want to find the square root of: ";
		cin >> getSqrt;
		cout << "The square root of " << getSqrt << " is: ";
		if ( getSqrt == 0 )///if the number we are finding the square root of is zero, we don't bother entering our function
		{
			numApprox = 0;
			cout << numApprox << endl; ///outputting the square root
		}
		else if ( getSqrt < 0 )///I decided to make the output work for negative numbers too outputting i for sqrt(-1)
		{
			getSqrt = getSqrt * -1;
			initialGuess = getSqrt / 2; ///this is our initial guess to start the NR-iterations
			numApprox = ComputeSqrt( getSqrt, initialGuess );///calls our function
			cout << "i*" << numApprox << endl;///outputs the return value
		}

		else
		{
			initialGuess = getSqrt / 2;
			numApprox = ComputeSqrt( getSqrt, initialGuess );
			cout << numApprox << endl;
		}
		cout << "Would you like to take the square root of another number?" << endl; ///asking if they want to find the square root of another value or not
		cout << "Enter 1 for true and 0 for false ";
		cin >> userChoice;
		cout << endl;
	}
	inputFile.open( fileNames[ 0 ] );
	if( inputFile.is_open() )
	{
		do
		{
			inputFile >> getSqrt;
			if( inputFile.eof() ) ///if we are at the end of the file break from the do-while loop so we don't accidentlaly
				///output something stored inside of getSqrt to the file, or output more numbers than we mean to. 
			{
				break;
			}
			if ( getSqrt == 0 )///if the number we are finding the square root of is zero, we don't bother entering our function
			{
				numApprox = 0.0;
				sqrtArray.push_back( numApprox ); ///adds our approx value to the array
			}
			else if ( getSqrt < 0 )///I decided to make the output work for negative numbers too outputting i for sqrt(-1)
			{
				getSqrt = getSqrt * -1;
				initialGuess = getSqrt / 2; ///this is our initial guess to start the NR-iterations
				numApprox = ComputeSqrt( getSqrt, initialGuess );///calls our function
				numApprox = numApprox * -1; ///we are adding back the negative one for purposes of outputting the i*. 
				sqrtArray.push_back( numApprox );///adds our estimate to our vector. 
			}
			else
			{
				initialGuess = getSqrt / 2;
				numApprox = ComputeSqrt( getSqrt, initialGuess );
				sqrtArray.push_back( numApprox );
			}
		} while( !inputFile.eof() ); ///checks if file is closed or open
		inputFile.close();///closes input file
	}
	else///executes if we cannot open our output file
	{
		cout << "Unable to open " << fileNames[ 0 ] << endl;
	}
	outputFile.open( fileNames[ 1 ] ); ///opens the output file
	if( outputFile.is_open() )///checks if the output file is open
	{
		outputFile << fixed << setprecision( 5 );///want to output to 5 decimal places always;
		for( uint i = 0; i < sqrtArray.size(); ++i ) ///iterates through the vecotr
		{
			if( sqrtArray[ i ] < 0 )///executes if sqrtArray at index i is negative so we can output the i*.
			{
				outputFile << "i*" << sqrtArray[ i ] << endl;
			}
			else
			{
				outputFile << sqrtArray[ i ] << endl;
			}
		}
		outputFile.close(); ///closes the file
	}
	else///executes if we can't open the output file
	{
		cout << "Unable to open " << fileNames[ 1 ] << endl;
	}

	cout << "Goodbye!" << endl;///outputs good bye

	return 0;
}
double ComputeSqrt( const double takeSqrt, double estimate, double previousVal ) ///defining the function
{
	double newEstimate = estimate - ( ( ( estimate * estimate ) - takeSqrt) / ( 2 * estimate ) );///creating the next number in the NR-iteration
	double difference = newEstimate - previousVal; ///computing the difference between the value to find the square root of and
	///the square of our estimation

	if ( difference < 0) ///when comparing our final if-statement we want to make sure the differene is always positive, based on our initial guess always being
		///half, there is a chance the initial estimation will be greater if the value to find the square root of is between -1 and 1. 
	{
		difference = difference * -1;
	}
	if ( difference > 1e-5 )///if we are greater than the desired difference we recursively call our function
	{
		previousVal = newEstimate;
		return ComputeSqrt( takeSqrt, newEstimate, previousVal );///recursive call returning the value
	}
	return newEstimate;///otherwise we just return the newEstimate
}
