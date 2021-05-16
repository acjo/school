#pragma once
#ifndef STATE_H
#define STATE_H
#include "Utils.h"
//typedef unsigned int uint;
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
	double latitudeSum;
	double longitudeSum;
	double tempSum;
	double latitudeAvg;
	double longitudeAvg;
	double tempAvg;
	uint numRows;
};
#endif