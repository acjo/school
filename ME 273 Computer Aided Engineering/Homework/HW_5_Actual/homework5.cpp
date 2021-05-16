//--------------------------------------------------------------
// File: Homework5.cpp
// By: Caelan Osman
// Date: 11 February 2020
// This program reads in a state id, latitude, longitude, date, temperature,
// the name of the state and the day of year the reading was taken.
// We then compute the average latitude, longitude, and temperature for
// each state id, then output them to our own file.
//--------------------------------------------------------------
#include <iostream> ///lets us access input-output
#include <fstream> ///lets us acces file input-output
#include <string> ///lets us access the string library
#include <vector> ///lets us access the vector library
#include <iomanip> ///output manipulation I use it make the files look nicer

using namespace std; ///we will be using the standard namespace

typedef unsigned int uint; ///messing around with type def

class State///I created a state to hold the conditions of each object note that most member functions are defined and declared in-line
{
public:
	State(); ///default constructor
	uint GetID() const { return stateId; } ///gets the state id
	void SetID(double id) { stateId = id; } ///sets the state id
	void AddLatitude(double lat) { latitudeSum += lat; } ///adds the latitude to the old sum
	void AddLongitude(double longitude) { longitudeSum += longitude; } ///adds the new longitude to the old sum
	void AddTemp(double newTemp); ///adds the new temp to the old temp and increments the row number
	double GetLatitudeAvg() const { return latitudeAvg; } ///gets the latitude avg
	double GetLongitudeAvg() const { return longitudeAvg; } ///gets the longitude avg
	double GetTempAvg() const { return tempAvg; } ///gets the temp avg
	void IncrementRows() { ++numRows; } ///increments the rows
	void ComputeAvgs(); ///computes all avgs
private:
	uint stateId; ///these are all of our data member
	double latitudeSum = 0;
	double longitudeSum = 0;
	double tempSum = 0;
	double latitudeAvg = 0;
	double longitudeAvg = 0;
	double tempAvg = 0;
	uint numRows = 0;
};
State::State(){}///default constructor
void State::AddTemp(double newTemp)///adds temp then calls the increment rows function
{
	tempSum += newTemp;
	IncrementRows();
}
void State::ComputeAvgs()///computes the avg and sets the data memembers
{
	latitudeAvg = latitudeSum / numRows;
	longitudeAvg = longitudeSum / numRows;
	tempAvg = tempSum / numRows;
}

int main()
{
	vector<State*> states; ///these are our vector of pointers to the objects
	State* statePointer = nullptr; ///declaring a new pointer
	vector <string> allProgramStrings = { "daily_TEMP_2013_proc.txt", "homework5output.txt", "date", "name" }; ///all strings needed for this program
	uint hitCount = 0; ///hit count for first if statement inside do-while loop we only want it entering that if statement once
	uint currentId = 0; ///everything below her until myinput just collects the file input each iteration
	uint previousId = 0;
	double latitude;
	double longitude;
	double temp;
	uint dayOfYear;
	ifstream myInput;///file input
	ofstream myOutput;///file output
	bool iterate = true; ///this is for the inner while loop
	myInput.open( allProgramStrings.at( 0 ) ); ///opens our input file
	if ( myInput.is_open() ) ///if it is open execute
	{
		do
		{
			statePointer = new State(); ///allocating new memory
			while ( iterate ) ///while iterate = true
			{
				if ( hitCount == 0 ) ///only entering the very first iteration of the dowhile loop 
				{
					myInput >> currentId; ///input new id
					previousId = currentId; ///set previous id to current id
					++hitCount; ///increments hit count
				}
				statePointer->SetID( currentId ); ///sets the id for our object
				myInput >> latitude; ///input lat
				myInput >> longitude;///input long
				myInput >> allProgramStrings.at( 2 );///input date
				myInput >> temp;///input temp
				myInput >> allProgramStrings.at( 3 ); ///input name
				myInput >> dayOfYear;///input day of year
				statePointer->AddLatitude( latitude );///adds longitude,latitud and temp
				statePointer->AddLongitude( longitude );
				statePointer->AddTemp( temp );
				myInput >> currentId;///inputs the id on the next line
				if ( currentId != previousId || myInput.eof() )///checks if new id is same as old if not iterate gets sent to false, or if the file is at its end
				{
					iterate = false;
				}
			}
			previousId = currentId;///sets previous id to current id 
			iterate = true;///iterate to true
			states.push_back( statePointer );///adds our pointer to the vecotr
		} while ( !myInput.eof() );///checks if we are at the end of file
		myInput.close();///closes the file
	}
	else ///executes if we can't open our input file
	{
		cout << "Unable to open: " << allProgramStrings.at( 0 ) << endl;
	}
	myOutput.open( allProgramStrings.at( 1 ) ); ///opens our output file
	if ( myOutput.is_open() ) ///if we can open the output file
	{
		myOutput << setprecision( 6 ); ///we want 6 digits showing total
		myOutput << "State ID" << setw( 19 ) << "Latitude" << setw( 25 ) << "Longitude" << setw( 30 ) << "Average Temperature" << endl;
		for ( uint i = 0; i < states.size(); ++i ) ///iterates through the vector adding all the contents of the objects to the files. 
		{
			states.at( i )->ComputeAvgs();
			myOutput << states.at( i )->GetID() << setw( 25 );
			myOutput << states.at( i )->GetLatitudeAvg() << setw( 25 );
			myOutput << states.at( i )->GetLongitudeAvg() << setw( 25 );
			myOutput << states.at( i )->GetTempAvg();
			myOutput << endl;
		}
		myOutput.close();///closes the output file
	}
	else///executes if we can't open the file
	{
		cout << "Unable to open: " << allProgramStrings.at( 1 );
	}
	for ( uint i = 0; i < states.size(); ++i )///deleting memory allocation
	{
		delete states.at( i );
	}
	states.clear();///clearing our vector of pointers. 

	return 0;
}
