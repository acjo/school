//--------------------------------------------------------------
// File: arraysorting.cpp
// By: Caelan Osman
// Date: 2 March 2020
// This program reads in a set of  numbers from a file
// inputs them into an array and then sorts the numbers in
// numerical ascending order.
// p.s. I know I submitted this late, but I had the assignment done
// but I completely spaced it. I know this is correct and I honestly didn't
//cheat but I will mark myself off for turning it in late
//--------------------------------------------------------------
#include <iostream>
#include <fstream>

using namespace std;

#define MAXIMUM 100 ///max numbers allowed

int main()
{

	double numsFromFile[ MAXIMUM ]; ///our array
	unsigned int amountOfNums = 0; ///numbers we are inputing
	string inputFileName = "randomnumbers.txt"; ///our input/output files
	string outputFileName = "sortednumbers.txt";
	ifstream myInputFile;
	ofstream myOutputFile;
	double numberFromFile;

	myInputFile.open( inputFileName );///open the file
	while( myInputFile.is_open() )
	{
		myInputFile >> numberFromFile;
		if( myInputFile.eof() )///if we are at the end break from the while loop
		{
			break;
		}
		else
		{
			numsFromFile[ amountOfNums ] = numberFromFile;///the new number at the new index
			++amountOfNums;///increment amount of numbers
		}
	}
	for( unsigned int i = 0; i < amountOfNums; ++i ) ///outerloop iterating over all numbers
	{
		for( unsigned int j = i + 1; j < amountOfNums; ++j )///inner loop iterating over the numbers not yet added
		{
			if( numsFromFile[ i ] > numsFromFile[ j ] )///if our num at index i (outer loop) is greater than our number at index j
			{
				double temp  = numsFromFile[ i ]; ///define a temp
				numsFromFile[ i ]= numsFromFile[ j ]; ///switch the numbers
				numsFromFile[ j ] = temp;
			}
		}
	}
	myInputFile.close();///close input file
	myOutputFile.open( outputFileName );///open input file
	for( unsigned int i = 0; i < amountOfNums; ++i )///output to the output file
	{
		myOutputFile << numsFromFile[ i ] << endl;
	}
	myOutputFile.close();

	return 0;
}
