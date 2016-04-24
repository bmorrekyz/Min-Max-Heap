/*****************************************
** File:    Driver.cpp
** Project: CMSC 341 Project 4, Spring 2016
** Author:  Dinara Sagitova
** Date:    4/22/16
** Section: 04
** E-mail:  dsagit1@umbc.edu 
**
**   This is the driver file for the MinMaxHeap project. 
** This file reads the heap data an input file passed from the command line. 
** Then it instantiates a MMheap class and inserts elements into this heap. 
***********************************************/

#include "MMheap.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    MMheap<int> theHeap;
  	vector<int> numbers;
  	string filename;

  	if(argc == 2)
    {
    	filename = argv[1];
    }
  	else
    {
    	cout << "Not enough command line arguments." << endl;
      	return 0;
    }

  	ifstream file(filename.c_str());

  	if (file.is_open())
    {
    	string line;

      	while(getline(file, line))
		{
	  		numbers.push_back(atoi(line.c_str()));
		}
    }
  	else
    {
    	cout << "File was not opened." << endl;
      	return 0;
    }



    cout << "--------------------" << endl;
    cout << "*** Make the min-max heap in Figure 6.57. ***" << endl;
    cout << "--------------------" << endl;
    for(int i; i<numbers.size();i++)
    {
      theHeap.insert(numbers[i]);
    }
    theHeap.dump();

    cout << "--------------------" << endl;
    cout << "*** Then insert 53, 57, 13, 12, 9, 10. ***" << endl;
    cout << "--------------------" << endl;

    theHeap.insert(53);
    theHeap.insert(57);
    theHeap.insert(13);
    theHeap.insert(12);
    theHeap.insert(9);
    theHeap.insert(10);
    theHeap.dump();

	return 0;
}