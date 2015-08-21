/* Bryan Wood Lib.cpp */

#include "lib.h"

/*-------------------------------------------------------
opens files to be used as input and output
Receives: input, output
Returns: nothing
---------------------------------------------------------*/
char openfiles (ifstream &input1, ofstream &output1)
{	
	char infile1[20],
		 outfile1[20];

	// opens the file that will be used as the first input file
	cout << "Enter the name of the first input file to be opened: ";
	cin >> infile1;
	input1.open(infile1, ios::nocreate);
	while (input1.fail())
	{
		input1.clear();
		cout << "Could not open " << infile1 
			 << " please re-enter the file name: " << endl;
		cin >> infile1;
		input1.open(infile1, ios::nocreate);
	}
	
	// opens the file that will be used as the output file
	cout << "Enter the name of output file to be opened: ";
	cin >> outfile1;
	output1.open (outfile1, ios::app);    // creates output file for output

	return infile1[20];
}//end openfiles

/*-------------------------------------------------------
Read all the name information into the dynamic array
Receives: input, floats, size
Returns: nothing
---------------------------------------------------------*/
void readin (istream &input1, ftptr &floats, int &size)
{
	int counter = 0;      //psuedo read in         
	float inflt; //read in
	size = 0;
	floats = NULL;

	resize (floats, size, 10);
	
	input1 >> inflt;
	while (!input1.eof())
	{
		if (counter >= size)     //resize array
		{
			resize (floats, size, 2*size);
		}
		
		floats[counter] = inflt;
		counter++;
		input1 >> inflt;
	}
	resize (floats, size, counter);    // Only keep what we need.
}

/*-------------------------------------------------------
resizes array to size needed by input file
Receives: floats, size, newsize
Returns: nothing
---------------------------------------------------------*/
void resize (ftptr &floats, int &size, int newsize)
{
	int x, y;
	ftptr temp = floats;

	// Determine number of elements to copy into the new Array
	if (floats == NULL)
	{
		y = 0;                  // Initial call; there IS no array yet
	}
	else if (newsize > size)
	{
		y = size;               // Copy ALL of the existing array
	}
	else
	{
		y = newsize;            // Else only copy portion being kept.
	}
	
	floats = new float[newsize];  // Allocate space for the new float array
	size  = newsize;              // Update the Size

	if (floats == NULL)
	{//teminate program because of Allocation error
		cerr << "Program failed to allocate " << newsize << " elements, and exited" << endl;
		exit (-1);
	}
	//copy across original data to the new array
	for (x = 0; x < y; x++)
	{
		 floats[x] = temp[x];
	}
	if (temp != NULL)
	{
		delete [] temp;
	}
}

/*-------------------------------------------------------
fills the output file with all the needed information
Receives: output, floats, size
Returns: nothing
---------------------------------------------------------*/
void fillfile (ofstream &output1, char file[], ftptr &floats, int size)
{
	int x, y, z, a, b;
	float high, low, mean, temp1, median, holder = 0, holder1, holder2 = 0, deviation;

	high = floats[0];
	low = floats[0];
	/*---high and low---------------------------*/
	for (x = 0; x < size; x++)
	{
		if (high < floats[x])
		{
			high = floats[x];
		}
		else if (low > floats[x])
		{
			low = floats[x];
		}
	}
	/*---order numbers--------------------------*/
	for (x = 0; x < size; x++)
	{//sort array
		for (y = 0; y < size; y++)
		{
			if (floats[x] > floats[y])
			{
				temp1 = floats[x];
				floats[x] = floats[y];
				floats[y] = temp1;
			}
		}
	}
	/*---median---------------------------------*/
	//this needs some work
	if (size % 2 == 1)
	{
		z = x - y / 2;
	}
	else if (size % 2 == 0)
	{
		a = (x - 1) / 2;
		b = (x + 1) / 2;
		z = (a + b) / 2;
	}
	median = floats[z];
	/*---mean-----------------------------------*/
	for (x = 0; x < size; x++)
	{
		holder += floats[x];
	}
	mean = holder / float (size);
	/*---Standard Deviation---------------------*/
	for (x = 0; x < size; x++)
	{
		holder1 = mean - floats[x];
		holder2 += holder1*holder1;
	}
	deviation = float (sqrt (holder2 / size));
	/*---Final Output---------------------------*/
	output1 << setw(11) << "File:  "    << file << endl
		    << setw(11) << "Size:  "    << size << " values" << endl
			<< setiosflags (ios:: fixed | ios:: showpoint) << setprecision(2) 
			<< setw(11) << "Mean:  "     << mean      << endl
			<< setw(11) << "Std.Dev.:  " << deviation << endl
			<< setw(11) << "Median:  "   << median    << endl
			<< setw(11) << "Maximum:  "  << high      << endl
			<< setw(11) << "Minimum:  "  << low       << endl
			<< endl     << endl;
} 

/*-------------------------------------------------------
closes files used as input and output
Receives: input, output
Returns: nothing
---------------------------------------------------------*/
void closefiles (ifstream &input1, ofstream &output1)
{
	input1.close();
	output1.close();  
}