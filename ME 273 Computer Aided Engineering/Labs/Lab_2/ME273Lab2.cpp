//--------------------------------------------------------------    
//  File:     ME273lab2.cpp         
//  By:      Caelan Osman         
//  Date:  30 January 2020        
// This program estimates the single and double precision machine
// epsilons experimentally and with the equation e = 2^(-n) and
// n=-log10(e)
//--------------------------------------------------------------
#include <iostream> ///input-output
#include <iomanip> ///input-ouput manipulators
#include <ios>
#include <cmath> ///access the math library

using namespace std; ///the namespace where cout and iostream live

int main()
{
	typedef unsigned int uint; // just messing around with typedef not necessary for this program.
	float x = 1.0;
	float dx = 0.0;
	uint flag = 0;
	cout.setf(ios::fixed);  /// Fixed point (not scientific)   
	cout.setf(ios::showpoint); /// Print trailing zeros   
	cout.precision(22);  /// Number of digits after decimal 
	long double singleEstimate = 1 / (pow(2.0, 23)); ///comparing these to what we found
	long double doubleEstimate = 1 / (pow(2.0, 52));
	uint singlePrecision = -log10(singleEstimate); ///These are our precisions
	uint doublePrecision = -log10(doubleEstimate);
	
	do
	{
		cout << "Enter a small value: ";
		cin >> dx; ///input our test machine epsilon
		x += dx;
		cout << x << "  " << dx << endl;
		cout << "If you want to exit enter 1:  "; 
		cin >> flag; ///user inputs if they want to contiue
		x = 1.0; ///reset x to 1.0 every single time so we can check
	} while(flag != 1);

	cout << "Single machine epsilon experimental: " << 2 * dx << endl;
	cout << "Machine Epsilon single estimate: " << singleEstimate << endl;
	cout << "Estimate digits of precision: " << singlePrecision << endl;
	double xd = 1.0;
	double dxd;; /// making new variables of type double 
	do
	{
		cout << "Enter a small value: ";
		cin >> dxd; ///input our test machine epsilon
		xd += dxd;
		cout << xd << "  " << dxd << endl;
		cout << "If you want to exit enter 1:  ";
		cin >> flag; ///user inputs if they want to contiue
		xd = 1.0; ///reset x to 1.0 every single time so we can check
	} while (flag != 1);

	cout << "Double machine epsilon experimental: " << 2 * dxd << endl;
	cout << "Machine epsilon double estimate: " << doubleEstimate << endl;
	cout << "Estimate digits of precision: " << doublePrecision << endl;
}