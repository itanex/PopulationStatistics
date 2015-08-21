/*
Bryan Wood
main.cpp

This program collects data from the sorce file and then uses that data to find the
    statistics of that data (high, low, mean, median, standard deviation) it also 
	orders the array of floats to make the search function opperate more efficiantly.
	After all this data is found then the output file is filled with the information.
	This program loops as so the user can manipulate muliple files without exiting.

Variables: output1, input1, floats, size, loopme, file
*/

#include "lib.h"

void main ( void )
{
   ofstream 
	   output1;
   ifstream 
	   input1;
   ftptr 
	   floats = NULL;
   int 
	   size = 0;
   char
	    file[20],
		loopme[4];
   do
   {
	   openfiles (input1, output1);
	   readin (input1, floats, size);
	   fillfile (output1, file, floats, size);
	   closefiles (input1, output1);
	   
	   cin.ignore (255, '\n');         // prevents unwanted drop throughs
	   cout << "Do you wish to process another file (y/n): ";
	   cin.getline(loopme, 4, '\n');
	   loopme[0] = tolower (loopme[0]);

	   while (loopme[0] != 'y' || loopme[0] != 'n')
	   {
		   cin.ignore (255, '\n');         // prevents unwanted drop throughs
		   cout << "That wasn't a propor answer. Try again." << endl
			    << "Do you wish to process another file: ";
		   cin.getline(loopme, 4, '\n');
		   loopme[0] = tolower (loopme[0]);

		   if (loopme[0] != 'y' || loopme[0] != 'n')
		   {
			   break;
		   }
	   }
   }while (loopme[0] == 'y');
}
