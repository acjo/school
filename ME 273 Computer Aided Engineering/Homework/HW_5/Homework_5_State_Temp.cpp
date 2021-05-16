#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <ios> 

using namespace std;

typedef unsigned int uint;

class State
{
public:
	State();
	uint GetID() const { return stateId; }
	void SetID(double id) { stateId = id; }
	void AddLatitude(double lat) { latitudeSum += lat; }
	void AddLongitude(double longitude) { longitudeSum += longitude; }
	void AddTemp(double newTemp);
	double GetLatitudeAvg() const { return latitudeAvg; }
	double GetLongitudeAvg() const { return longitudeAvg; }
	double GetTempAvg() const { return tempAvg; }
	void IncrementRows() { ++numRows; }
	void ComputeAvgs();
private:
	uint stateId;
	double latitudeSum = 0;
	double longitudeSum = 0;
	double tempSum = 0;
	double latitudeAvg = 0;
	double longitudeAvg = 0;
	double tempAvg = 0;
	uint numRows = 0;
};
State::State() {}
void State::AddTemp(double newTemp)
{
	tempSum += newTemp;
	IncrementRows();
}
void State::ComputeAvgs()
{
	latitudeAvg = latitudeSum / numRows;
	longitudeAvg = longitudeSum / numRows;
	tempAvg = tempSum / numRows;
}

int main()
{
	vector<State*> states;
	State* statePointer = nullptr;
	vector <string> allProgramStrings = { "daily_TEMP_2013_proc.txt", "homework_5_output.txt", "date", "name" };
	uint hitCount = 0;
	uint currentId = 0;
	uint previousId = 0;
	double latitude;
	double longitude;
	double temp;
	uint dayOfYear;
	ifstream myInput;
	ofstream myOutput;
	bool iterate = true;
	bool run = true;
	myInput.open(allProgramStrings.at(0));
	if (myInput.is_open())
	{
		do
		{
			statePointer = new State();
			while (iterate)
			{
				if (hitCount == 0)
				{
					myInput >> currentId;
					previousId = currentId;
					++hitCount;
				}
				statePointer->SetID(currentId);
				myInput >> latitude;
				myInput >> longitude;
				myInput >> allProgramStrings.at(2);
				myInput >> temp;
				myInput >> allProgramStrings.at(3);
				myInput >> dayOfYear;
				statePointer->AddLatitude(latitude);
				statePointer->AddLongitude(longitude);
				statePointer->AddTemp(temp);
				cout << currentId;
				myInput >> currentId;
				if (currentId != previousId || myInput.eof())
				{
					iterate = false;
				}
			}
			previousId = currentId;
			iterate = true;
			states.push_back(statePointer);
		} while (!myInput.eof());
		myInput.close();
	}
	else
	{
		cout << "Unable to open: " << allProgramStrings.at(0) << endl;
	}
	myOutput.open(allProgramStrings.at(1));
	if (myOutput.is_open())
	{
		myOutput << fixed << setprecision(6);
		for (uint i = 0; i < states.size(); ++i)
		{
			states.at(i)->ComputeAvgs();
			myOutput << states.at(i)->GetID() << "\t";
			myOutput << states.at(i)->GetLatitudeAvg() << "\t";
			myOutput << states.at(i)->GetLongitudeAvg() << "\t";
			myOutput << states.at(i)->GetTempAvg() << "\t";
			myOutput << endl;
		}
		myOutput.close();
	}
	else
	{
		cout << "Unable to open: " << allProgramStrings.at(1);
	}
	for (uint i = 0; i < states.size(); ++i)
	{
		delete states.at(i);
	}
	states.clear();

	return 0;
}