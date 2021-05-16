#include "State.h"

State::State()
{
	stateId = 0;
	latitudeSum = 0;
	longitudeSum = 0;
	tempSum = 0;
	latitudeAvg = 0;
	longitudeAvg = 0;
	tempAvg = 0;
	numRows = 0;
}
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