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


  theHeap.insert(18);
 


  return 0;
}