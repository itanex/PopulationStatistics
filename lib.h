/*Bryan Wood Lib.h */

#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef float* ftptr;

/*-------------------------------------------------------
opens files to be used as input and output
Receives: input, output
Returns: nothing
---------------------------------------------------------*/
char openfiles (ifstream &input1, ofstream &output1);

/*-------------------------------------------------------
resizes array to size needed by input file
Receives: floats, size, newsize
Returns: nothing
---------------------------------------------------------*/
void resize (ftptr &floats, int &size, int newsize);

/*-------------------------------------------------------
Read all the name information into the dynamic array
Receives: input, floats, size
Returns: nothing
---------------------------------------------------------*/
void readin (istream &input1, ftptr &floats, int &size);

/*-------------------------------------------------------
fills the output file with all the needed information
Receives: output, floats, size
Returns: nothing
---------------------------------------------------------*/
void fillfile (ofstream &output1, char file[], ftptr &floats, int size);

/*-------------------------------------------------------
closes files used as input and output
Receives: input, output
Returns: nothing
---------------------------------------------------------*/
void closefiles (ifstream &input1, ofstream &output1);





