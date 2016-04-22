#include <iostream>
#include "MinHeap.h"

using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	cout << "main() is quitting... " << endl;

	MinHeap<int> minHeap;
	minHeap.insert(6);

	return 0;
}