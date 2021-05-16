#include <iostream>///input/output library
#include <vector>///vector library
#include <string>///string library
#include <fstream>///file input and output
#include <cmath> ///use for absolute value function

using namespace std; ///the standard namespace

vector< vector< double > > MatrixAddition( const vector< vector< double > >&, const vector< vector< double > >& ); /// our matrix addition function
vector< vector< double > > MatrixMultiplication( vector< vector < double > >&, vector< vector< double > >& ); ///matrix multiplication function
double RowColumnRule( vector< vector< double > >&, vector< vector< double > >&, unsigned int, unsigned int ); ///use this to compute a row-column rule product for each entry.

int main ()
{
	string fileName;///this is the filename where we will get our matrices to add.
	string resultFile; ///This is the filename the results will be listed to.
	ifstream myInput; ///file input  variable
	ofstream myOutput; ///file output variable
	vector< vector < double > > eigen1( 0, vector< double > ( 0 ) ); ///these vectors of vectors will hold our matrices. Initialized to size 0, holding sized 0 vectors.
	vector< vector < double > > eigen2( 0, vector< double > ( 0 ) );
	vector< vector < double > > result( 0, vector< double > ( 0 ) ); /// this holds the result of our matrix operation.
	vector< double > tempVector( 0 ); ///this holds the temporary vector we will insert to each eigen.
	bool iterate( true ); ///use this for our outter while loop.
       	bool firstMatrix; ///use this for our do-while loop we need to know if we are on the first line or not
	unsigned int numRows;///will hold the number of rows and columns
	unsigned int numCols;
	double tempElement; ///this will hold a temporary element
	char matrixOperation; ///the matrix option the user chooses to do either multiply or add
	bool end; ///if we are at the end of the file
	char userChoice; ///determines if the user wants to make another operation on another set of matrices
	const char characters [68] = {'$','@','B','%','8','&','W','M','#','*','o','a','h','k','b','d','p','q','w','m','Z','O','0','Q','L','C','J','U','Y','X','z','c','v','u','n','x','r','j','f','t','/','|','(',')','1','{','}','[',']','?','-','_','+','~','<','>','i','!','l','I',';',':',',','^','`','.',' ','"' }; ///we'll use this to draw or picture.

	while ( iterate ) ///while iterate is true
	{
		cout << "Enter the name of the file that contains the two matrices: " << endl;
		cin >> 	fileName; ///get the file name from the user
		myInput.open( fileName ); ///open the file
		if( myInput.is_open() ) /// if the file can be opened
		{
			firstMatrix = true; ///set firstmatrix to true
			end = false; ///set end of file to false
			do //start inputting elments into our first matrix
			{
				myInput >> numRows; ///get the number of rows

				if( myInput.eof() ) ///if we reached the end of file break from the loop this is just error checking. 
				{
					break;
				}

				myInput >> numCols; ///get number of columns

				for( auto i = 0; i < numRows; ++i ) ///we create a nested set of for loops for to populate our matrix
				{
					for( auto j = 0; j < numCols; ++j )
					{
						myInput >> tempElement; ///get the lement
						tempVector.push_back( tempElement ); ///push back our element into our temporary vecotr
					}
					if ( !end && firstMatrix ) ///we need to know if we are to add our temporary vector to our first or our second vector
					{
						eigen1.push_back( tempVector ); ///add then clear if we aren't at the end and if we are in the first matrix. Note that we clear our matrices and then reset the size to 0 for th  next iteration
						tempVector.clear();
						tempVector.resize( 0 );
					}
					else if( !end && !firstMatrix ) ///same only if we are at our second matrix
					{
						eigen2.push_back( tempVector );
						tempVector.clear();
						tempVector.resize( 0 );
					}
					else ///otherwise
					{
						tempVector.clear();
						tempVector.resize( 0 );
						break;
					}
				}
				firstMatrix = false; ///after the first iteration firstmatrix flag gets set to false

			}while( !myInput.eof() ); ///we iterate while we are not at the end of th efile
			myInput.close(); ///close the file
		}
		else///execute if we cannot open the file
		{
			cout << "Unable to open " << fileName << "!" << endl;
		}
		cout << "Do you want to add or multiply the matrices together? Enter A for add and M for mulitply: " << endl; ///ask if we want to multiply or add
		cin >> matrixOperation; ///gets the user choice
		if ( eigen1.size() == 0 || eigen2.size() == 0 ) ///if either of the matrices are of size 0 we tell them
		{
			cout << "You have at least one empty matrix! unable to add or multiply" << endl;
		}
		else if ( matrixOperation == 'A' ) ///if we want to add
		{
			if ( eigen1.size() == eigen2.size() && eigen1.at( 0 ).size() == eigen2.at( 0 ).size() )///check that both the number of rows and columns are the same
			{
				result = MatrixAddition( eigen1, eigen2 ); ///send this to our matrix addition function
				eigen1.clear();///clear and reset the size on both of our matrices
				eigen2.clear();
				eigen1.resize( 0 );
				eigen2.resize( 0 );
				cout << "Enter the file you want the result to be written to: " << endl; ///ask what file the want the matrix to be written to
				cin >> resultFile;
				myOutput.open( resultFile ); ///open that file
				if ( myOutput.is_open() ) ///if we can open it
				{
					for( auto i = 0; i < numRows; ++ i) ///we output one row at a time
					{
						for( auto j = 0; j < numCols; ++j )
						{
							myOutput << characters[ static_cast<unsigned int>( result.at( i ).at( j ) ) ];///static cast from a double to an integer so we can output the array at that element number. 
						}
						myOutput << endl;
					}
					cout << "The resultant matrix has been written to " << resultFile << "." << endl; ///tell them when it is finished
					myOutput.close();///close the file
				}
				else///executes if we can't open the file( note that in most cases the program will just create the desired output file name )
				{
					cout << "Unable to open " << resultFile << " try again! " << endl;
				}
				result.clear();///clear and reset the size of the result matrix
				result.resize( 0 );
			}
			else///executes if the two matrices are not compatible for adding
			{
				cout << "The matrices are not compatible and cannot be added! Try again!" << endl;
			}
		}
		else if ( matrixOperation == 'M') ///if they want to multiply the two matrices
		{
			unsigned int commuteID; ///we ask if they want to multiply the first by the second or the second by the first
			cout << "Do you want to multiply the first matrix by the second matrix or the second matrix by the first? i.e. AB or BA" << endl;
			cout << "enter 1 for the first option or 2 for the second option: ";
			cin >> commuteID; ///get their choice
			if( commuteID == 1) ///first option
			{
				if( eigen1.at( 0 ).size() == eigen2.size() ) ///have to check that the number of columns matches number of rows
				{
					result = MatrixMultiplication( eigen1, eigen2 ); ///send the matrices to our matrix multiplication function
					eigen1.clear();///clear and reset the sizes
					eigen2.clear();
					eigen1.resize( 0 );
					eigen2.resize( 0 );
					cout << "Enter the file you want the result to be written to: " << endl;
					cin >> resultFile;///gets the file to output to
					myOutput.open( resultFile ); /// the name of the file
					if ( myOutput.is_open() ) ///if we can open it
					{
						for( auto i = 0; i < result.size(); ++ i) ///outputs the file one row at a time
						{
							for( auto j = 0; j < result.at( 0 ).size(); ++j )
							{
								double outputDouble = result.at( i ).at( j ); ///we use the following to check if the element is greater than equal to zero or less than 68 so we can output the chaVracter array elements
								if( abs( outputDouble ) >= 0 && abs( outputDouble ) < 68 )
								{
									if( outputDouble < 0 )
									{
										outputDouble = outputDouble * -1; ///mutiply by negative one to make it positive
										myOutput << characters[ static_cast< unsigned int > ( outputDouble ) ]; ///static cast it to make it something we can call an index on. 
									}
									else
									{
										myOutput << characters[ static_cast< unsigned int > ( outputDouble ) ];
									}
								}

							}
							myOutput << endl;
						}
						cout << "The resultant matrix has been written to " << resultFile << "." << endl; ///says when it is completed
						myOutput.close();
					}
					else///otherwise we can't open that file ( almost will never go into this if statement)
					{
						cout << "Unable to open " << resultFile << " try again! " << endl;
					}
					result.clear();///clear and reset size of the result
					result.resize( 0 );
				}
				else ///if they cannot be multiplied in this way we tell them
				{
					cout << "These two matrices are not conformable in this way!" << endl;
				}
			}
			else if ( commuteID == 2 ) ///if the choose to multiply the second by the first. The operation is the same just with eigen2 multiplied by eigen1.
			{
				if( eigen2.at( 0 ).size() == eigen1.size() )
				{
					result = MatrixMultiplication( eigen2, eigen1 );
					eigen1.clear();
					eigen2.clear();
					eigen1.resize( 0 );
					eigen2.resize( 0 );
					cout << "Enter the file you want the result to be written to: " << endl;
					cin >> resultFile;
					myOutput.open( resultFile );
					if ( myOutput.is_open() )
					{
						for( auto i = 0; i < result.size(); ++ i)
						{
							for( auto j = 0; j < result.at( 0 ).size(); ++j )
							{
								double outputDouble = result.at( i ).at( j ); ///we use the following to check if the element is greater than equal to zero or less than 68 so we can output the chaVracter array elements
								// if( abs( outputDouble ) >= 0 && abs( outputDouble ) < 68 )
								// {
									if( outputDouble < 0 )
									{
										outputDouble = outputDouble * -1; ///mutiply by negative one to make it positive
										myOutput << characters[ static_cast< unsigned int > ( outputDouble ) ]; ///static cast it to make it something we can call an index on. 
									}
									else
									{
										myOutput << characters[ static_cast< unsigned int > ( outputDouble ) ];
									}
								// }
							}
							myOutput << endl;
						}
						cout << "The resultant matrix has been written to " << resultFile << "." << endl;
						myOutput.close();
					}
					else
					{
						cout << "Unable to open " << resultFile << " try again! " << endl;
					}
					result.clear();
					result.resize( 0 );
				}
				else
				{
					cout << "These two matrices are not conformable in this way!" << endl;
				}

			}
			else ///if they don't input a valid commute id we won't know what to do ( error checking )
			{
				cout << commuteID << " is not a valid option! Try again." << endl;
			}

		}
		else ///if they don't choose A or M this isn't a valid option
		{
			cout << "Invalid Option! Try Again." << endl;
		}

		cout << "Do you want to add or multiply two more matrices? Enter Y or y for yes or any other key for no: ";
		cin >> userChoice; ///ask if they want to perform another operation
		if( userChoice != 'y' && userChoice != 'Y') ///if they choose yes then iterate will remain true
		{
			iterate = false;
		}
	}
	cout << "Goodbye!" << endl;

	return 0;
}

vector< vector< double > > MatrixAddition( const vector< vector< double > > &x, const vector< vector< double > > &y )/// our matrix addition function
{
	vector< vector< double > > sum( 0 );///we create our sum vector intialized of size 0 carrying size 0 vectors
	vector< double > rowSum( 0 );///this is a row sum vector just temporary
	double elementSum; ///this the an element that we will add which consists of the sums of two elements of addition matrices
	for( auto i = 0; i < x.size(); ++i ) ///iterate through the rows
	{
		for( auto j = 0; j < x.at( 0 ).size(); ++j ) ///iterate throw the columns
		{
			elementSum = x.at( i ).at( j ) + y.at( i ).at( j ); ///our elment sum
			rowSum.push_back( elementSum ); ///we push it back to our vector
			elementSum = 0; ///set it to zero
		}
		sum.push_back( rowSum ); ///push back the entire vector into our sum matrix
		rowSum.clear();///clear and resize the vector and repeat.
		rowSum.resize( 0 );
	}
	return sum;///return that matrix
}
vector< vector< double > > MatrixMultiplication( vector< vector < double > > &x, vector< vector< double > > &y ) ///matrix multiplication function
{
	vector< vector< double > > product( x.size(), vector< double > ( y.at( 0 ).size() ) ); ///we create a matrix intialized to be the number of rows of of x by th enumber of columns of y
	for( auto i = 0; i < product.size(); ++i )///this is for setting the value of each element.
	{
		for( auto j = 0; j < product.at( 0 ).size(); ++j)
		{
			product.at( i ).at( j ) = RowColumnRule( x, y, i, j); ///we call this function to set the value of each element. Note that I could have written it inline, but it seemed easier and more efficient to write a new function
			///also note that I pass the the function as arguments where we are at in the product matrix this is important
		}
	}
	return product;

}
double RowColumnRule( vector< vector< double > > &w, vector< vector< double > > &z, unsigned int rowIndex, unsigned int columnIndex ) ///this is our row column rule.
{
	vector< double > rowVec( w.at( 0 ).size() ); ///we create two new vectors each this one is the number of columns of each row in w
	vector< double > colVec( z.size() ); ///this is the size of the rows of z
	double sumProductResult = 0; ///our sumProducResult is initalized to 0.

	for ( auto i = 0; i < rowVec.size(); ++i ) ///we populate each vector by iterating through the desired row or column ( this is why we needed the row and column index)
	{
		rowVec.at( i ) = w.at( rowIndex ).at( i );
	}
	for( auto j = 0; j < colVec.size(); ++j )
	{
		colVec.at( j ) = z.at( j ).at( columnIndex );
	}
	for( auto k = 0; k < colVec.size(); ++k ) ///we go through each vector and multiply their respective element stogether then addthat to the sumproduct result
		///due to the way matrix multiplication is defined these vectors will always be the same size.
	{
		sumProductResult += colVec.at( k ) * rowVec.at( k );
	}
	return sumProductResult; ///return the result which sets our result matrix element at that point. 
}
