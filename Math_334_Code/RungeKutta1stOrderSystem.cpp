#include <iostream>
#include <cmath>

///This runs the runge kutta algorithm to solv ea first order system.
///f1 and f2 are the functions making up the 1st order system

using namespace std;

double f1( const double, const double, const double );

double f2( const double, const double, const double );

int main()
{

	double x = 0.1;
	double y = 0.2;
	double h = 0.05;
	double r = h / 6;
	double l = h / 2;

	double k11;
	double k12;
	double k21;
	double k22;
	double k31;
	double k32;
	double k41;
	double k42;

	for( auto n = 0; n < 20; ++n )///runge-kutta algorithm
	{
		double j = n + 0.5;
		double i = n + 1;
		k11 = f1( h * n, x, y );
		k12 = f2( h * n, x, y );
		k21 = f1( h * j, x + ( k11 * l ), y + ( k12 * l ) );
		k22 = f2( h * j, x + ( k11 * l ), y + ( k12 * l ) );
		k31 = f1( h * j, x + ( k21 * l ), y + ( k22 * l ) );
		k32 = f2( h * j, x + ( k21 * l ), y + ( k22 * l ) );
		k41 = f1( h * i, x + ( k31 * h ), y + ( k32 * h ) );
		k42 = f2( h * i, x + ( k31 * h ), y + ( k32 * h ) );

		x += r * ( k11 + ( 2 * k21 ) + ( 2 * k31 ) + k41 );
		y += r * ( k12 + ( 2 * k22 ) + ( 2 * k32 ) + k42 );
	}

	cout << "x at 1 is: " << x << endl;
	cout << "y at 1 is: " << y << endl;

	return 0;
}

double f1( const double t, const double x, const double y )
{
	double result;
	result = pow( t, 2) -( y * sin( x ) );
	return result;
}

double f2( const double t, const double x, const double y )
{
	double result;
	result = ( cos( t ) * x ) + pow( y, 2 ) - t;
	return result;

}
