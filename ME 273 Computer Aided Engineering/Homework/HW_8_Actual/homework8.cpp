//--------------------------------------------------------------    
//  File:     ME273 Homework8.cpp         
//  By:      Caelan Osman        
//  Date:  8 March 2020        
// This program will use simpsons or the trapezoidal rule
// to numerically integrate a function
//-------------------------------------------------------------- 
#include <iostream> ///input output
#include <cmath> ///math library
#include <iomanip> ///input/ouput manipulator
#include <vector>///vector library

using namespace std; ///using the standard namepsace

double SimpsonsRule(const unsigned int, const double, const double, const double); ///function for simpsons rule
double TrapezoidalRule(const unsigned int, const double, const double, const double); ///function for using the trapezoidal rule
double Function(const unsigned int, const double);///function containing each function
double ActualValue(const unsigned int, const double, const double); ///this will give us the actual values for function 1 & 2. 
double ErrorPercent(const unsigned int, const double, const double, const double); ///This will give us the error percentage

int main()
{
	bool iterate = true; ///whether or not the while loop will execute
	while (iterate)
	{
		unsigned int function_id; ///the function id
		char method; ///the method used to numerical integrate
		double distanceOfPoints; ///the distance between points
		double firstPoint; ///the first point
		double lastPoint;///the last point
		double approxArea;///the approx area under the function
		///the following code just gets conditions from the user to decide how and what to numerically integrate
		cout << "What function are you wanting to numerically integrate? Enter 1 or 2: ";
		cin >> function_id;
		cout << "What method do you want to use? Enter S for Simpsons and T for Trapezoidal: ";
		cin >> method;
		cout << "Enter your first and last point seperated by a space: ";
		cin >> firstPoint;
		cin >> lastPoint;
		cout << "Enter the distance between your recussive points: ";
		cin >> distanceOfPoints;
		if (method == 'S') ///if the method is simpson's rule
		{
			approxArea = SimpsonsRule(function_id, distanceOfPoints, firstPoint, lastPoint); ///pass inputs into function
			cout << "The approximate area is: " << setprecision(6) << approxArea << endl; ///output approx area
		}
		else///other wise the only options is the trapezoidal rule
		{
			approxArea = TrapezoidalRule(function_id, distanceOfPoints, firstPoint, lastPoint); ///pass inputs into function
			cout << setprecision(6) << "The approximate area is: " << approxArea << endl; ///output the area
		}
		double errorOfMethod = ErrorPercent(function_id, approxArea, firstPoint, lastPoint); ///computes the error
		cout << "The error is: " << setprecision(6) << errorOfMethod << "%" << endl; ///outputs error only outputs 6 sig figs
		cout << "Do you want to numerically integrate again? Enter Y for yes or any other key for no: "; ///asks if they want to numerically integrate again
		char integrateAgain;
		cin >> integrateAgain;
		if (integrateAgain != 'Y')
		{
			iterate = false;
		}
	}
	cout << "GoodBye!" << endl;
	return 0;
}

double SimpsonsRule(const unsigned int func_id, const double distance, const double first, const double last) ///simpsons rule
{
	double area = 0; ///area
	double area1 = 0;
	unsigned int recurssion_id = 0; ///the recurssion number
	unsigned int numPoints = (last - first) / distance; ///the number of intervals
	++numPoints; ///number of points
	vector< double > points(numPoints); ///sets a vector of size numpoints
	for (auto i = 0; i < numPoints; ++i) ///iterates through the vecotr and sets the point values
	{
		points.at(i) = first + (distance * i);
	}
	if (numPoints % 2 == 0) ///if the number of points is even we use simpsons 3/8ths rule
	{
		if( numPoints - 3 == 0 )
		{
			for (auto i = 0; i < numPoints; ++i)
			{
				if (i == 0 || i == (numPoints - 1) ) ///if we are at the first or last point we just add the function value
				{
					area += Function(func_id, points.at(i));
				}
				else///otherwise we multiply the function value by 3 and add it
				{
					area += 3 * Function(func_id, points.at(i));
				}
			}
			area = (3 * distance * area) / 8; ///multiply the area by 3/8 to get final approximation
		}
		else
		{
			for( auto i = 0; i < (numPoints - 3); ++i)
			{
				if (i == 0 || i == (numPoints - 1)) ///these two if else statements are the same as above
				{
					area += Function(func_id, points.at(i));
				}
				else
				{
					if (recurssion_id % 2 == 0) ///the multiplaction factor switches between 4 and 2 and the recurssion id decides which one to do. 
					{
						area += 4 * Function(func_id, points.at(i));
						++recurssion_id;
					}
					else
					{
						area += 2 * Function(func_id, points.at(i));
						++recurssion_id;
					}
				}
			}
			area = (distance / 3) * area; ///multiplies it by the distance / 3. 

			for(auto i = numPoints - 3; i < numPoints; ++ i)
			{
				if ( i == numPoints - 3 || i == numPoints - 1 )
				{
					area1 += Function( func_id, points.at( i ) );
				}
				else
				{
					area1 += 3 * Function( func_id, points.at( i ) );
				}
			}
			area1 = ( 3 * distance * area1 ) / 8;
			area += area1;
		}
	}
	else ///otherwise we will use simpsons 1/3 rule
	{
		for (auto i = 0; i < numPoints; ++i)
		{
			if (i == 0 || i == (numPoints - 1)) ///these two if else statements are the same as above
			{
				area += Function(func_id, points.at(i));
			}
			else
			{
				if (recurssion_id % 2 == 0) ///the multiplaction factor switches between 4 and 2 and the recurssion id decides which one to do. 
				{
					area += 4 * Function(func_id, points.at(i));
					++recurssion_id;
				}
				else
				{
					area += 2 * Function(func_id, points.at(i));
					++recurssion_id;
				}
			}
		}
		area = (distance / 3) * area; ///multiplies it by the distance / 3. 
	}
	return  area;///returns the area
}

double TrapezoidalRule(const unsigned int func_id, const double distance, const double first, const double last) ///trapezoidal rule function
{
	double area = 0; ///area
	unsigned int numPoints = (last - first) / distance; ///number of intervals
	++numPoints; ///number of points
	vector< double > points(numPoints); ///vector of size points
	for (auto i = 0; i < numPoints; ++i) ///sets point values
	{
		points.at(i) = first + (distance * i);
	}
	for (auto i = 0; i < numPoints; ++i)///decides the multiplication favor and iterates and adds over the vecotr. 
	{
		if (i == 0 || i == (numPoints - 1))
		{
			area += Function(func_id, points.at(i));
		}
		else
		{
			area += 2 * Function(func_id, points.at(i));
		}
	}
	area = (distance / 2) * area;
	return area;
}

double Function(const unsigned int func_id, const double x) ///this returns the function value for a function id and the value itself
{
	double funcValue = 3;
	if (func_id == 1)
	{
		funcValue = 0.2 * pow(x, 4) + 2.35 * pow(x, 3) - 3.96 * pow(x, 2) - 4.74 * x + 17.8;
	}
	else if(func_id == 2)
	{
		funcValue = 0.3 * pow(x, 4) + 0.55 * pow(x, 3) - 9.79 * pow(x, 2) + 20.5;
	}
	return funcValue;
}

double ActualValue(const unsigned int func_id, const double first, const double last) ///we can calculate the exact value of the integral of polynomials
{
	double exactVal = 0;
	if (func_id == 1)
	{
		exactVal = (0.04 * pow(last, 5) + 0.5875 * pow(last, 4) - 1.32 * pow(last, 3) - 2.37 * pow(last, 2) + 17.8 * last)
			- (0.04 * pow(first, 5) + 0.5875 * pow(first, 4) - 1.32 * pow(first, 3) - 2.37 * pow(first, 2) + 17.8 * first);
	}
	else
	{
		exactVal = (0.06 * pow(last, 5) + 0.1375 * pow(last, 4) - 3.2633 * pow(last, 3) + 20.5 * last)
			- (0.06 * pow(first, 5) + 0.1375 * pow(first, 4) - 3.2633 * pow(first, 3) + 20.5 * first);
	}
	return exactVal;
}

double ErrorPercent(const unsigned int func_id, const double approxValue, const double first, const double last) ///this will give us the error in percentage. 
{
	double exactVal = ActualValue(func_id, first, last);
	double error = (exactVal - approxValue) / exactVal;
	error = error * 100;
	return error;
}


