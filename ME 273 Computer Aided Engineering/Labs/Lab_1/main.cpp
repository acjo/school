//--------------------------------------------------------------    
//  File:     lab1.cpp         
//  By:      Caelan Osman         
//  Date:  14 January 2020        
//  This program  computes the average of four numbers,
//	using two different data types. 
//--------------------------------------------------------------
#include <iostream> //accesses input output

using namespace std; //using the standard library
int main()
{

	cout << "Hello World!" << endl; //outputs Hello World! to the console.

	float m, w, x, y, z;
	cout << "Enter four numbers to average:" << endl;
	cin >> w;
	cin >> x;
	cin >> y;
	cin >> z;
	m = (w + x + y + z) / 4; //computes the average
	cout << "You entered: " << w << ", " << x << ", " << y << ", " << z << endl;
	cout << "The mean is: " << m << endl; //outputs the mean to the screen
	cout << endl;

	//declaring four more variables, of integer types instead for the final 2 cases. 
	int a;
	int b;
	int c;
	int d;

	cout << "Enter four more numbers:" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	m = (a + b + c + d) / 4;
	cout << "You entered: " << a << ", " << b << ", " << c << ", " << d << endl;
	cout << "The mean is: " << m << endl;
	cout << endl;

	cout << "Enter four final numbers:" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	m = (a + b + c + d) / 4.0; //computes the average, but since 4.0 is a float, the result will be a float instead of an int
	cout << "You entered: " << a << ", " << b << ", " << c << ", " << d << endl;
	cout << "The mean is: " << m << endl;
	cout << endl;
}