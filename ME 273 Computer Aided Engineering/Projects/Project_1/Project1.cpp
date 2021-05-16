//--------------------------------------------------------------
// File: Project.cpp
// By: Caelan Osman
// Date: 24 February 2020
// This program reads in a movie id, a change in time and either a change in velocity
// or position and computes the acceleration or velocity respectively
// then outputs those to a file to be viewed.
//--------------------------------------------------------------

#include <iostream> ///lets us access input-output
#include <fstream> ///lets us acces file input-output
#include <string> ///lets us access the string library
#include <vector> ///lets us access the vector library
#include <iomanip> ///output manipulation I use it make the files look nicer

using namespace std; ///we will be using the standard namespace

typedef unsigned int uint; ///messing around with type def

double ComputeFinalComponent( double, double ); ///this will use finite difference to find our changes

class Movie///I created a class to hold the conditions of each movie
{
public:
	Movie(); ///default constructor
	Movie( string, double, double ); ///paramaterized constructor
	void SetID(string id) { state_id = id; }///sets the movie id
	void SetDeltaXOrV( double delta ) { delta_x_or_v = delta; }
	void SetDeltaT( double deltaT) { delta_time = deltaT; }
	void SetFinalVOrA( double computedComp ) { final_velc_or_accel = computedComp; }
	string GetID() const { return state_id; } ///gets the movie id
	double GetDeltaXOrV() const { return delta_x_or_v; }
	double GetDeltaT() const { return delta_time; }
	double GetFinalVOrA() const { return final_velc_or_accel; }
private:
	string state_id; ///these are all of our data members
	double delta_x_or_v; ///stores change in position or velocity
	double delta_time; ///the time over which the change occors
	double final_velc_or_accel;
};
Movie::Movie(){}///default constructor
Movie::Movie( string idOfState, double changeInTime, double changeInComponent )
{
	state_id = idOfState;
	delta_time = changeInTime;
	delta_x_or_v =  changeInComponent;
	final_velc_or_accel = 0;
}

int main()
{
	vector<Movie*> movies; ///these are our vector of pointers to the objects
	Movie* moviePointer = nullptr; ///declaring a new pointer
	vector <string> allProgramStrings = { "MovieInputs.txt", "MovieOutputs.txt" }; ///all strings needed for this program
	uint hitCount = 0; ///hit count for first if statement inside do-while loop we only want it entering that if statement once
	string idOfState; ///state id
	double changeInTime;///holds change in time
	double changeInComponent; /// holds change in velocity or position
	ifstream myInput;///file input
	ofstream myOutput;///file output
	myInput.open( allProgramStrings.at( 0 ) ); ///opens our input file
	if ( myInput.is_open() ) ///if it is open execute
	{
		do
		{
			myInput >> idOfState;
			if ( myInput.eof() )///if end of file, break from loop
			{
				break;
			}
			myInput >> changeInTime;
			myInput >> changeInComponent;
			moviePointer = new Movie( idOfState, changeInTime, changeInComponent );	///allocating new memory
			moviePointer->SetFinalVOrA( ComputeFinalComponent( changeInTime, changeInComponent ) );
			movies.push_back( moviePointer );///adds our pointer to the vecotr
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
		myOutput << "Movie ID" << setw( 40 ) << "Computed Trajectory Component" << endl;
		for ( uint i = 0; i < movies.size(); ++i ) ///iterates through the vector adding all the contents of the objects to the files.
		{
			myOutput << movies.at( i )->GetID() << setw( 25 );
			myOutput << right <<  movies.at( i )->GetFinalVOrA();
			myOutput << endl;
		}
		myOutput.close();///closes the output file
	}
	else///executes if we can't open the file
	{
		cout << "Unable to open: " << allProgramStrings.at( 1 );
	}
	for ( uint i = 0; i < movies.size(); ++i )///deleting memory allocation
	{
		delete movies.at( i );
	}
	movies.clear();///clearing our vector of pointers. 

	return 0;
}

double ComputeFinalComponent( double deltaTime, double deltaComponent )///uses finite difference i.e. slopecalculation
{
	double FinalCompontent = deltaComponent / deltaTime;
	return FinalCompontent;

}
