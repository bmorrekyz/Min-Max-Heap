#include <iostream>
#include "MMHeap.h"

using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	cout << "main() is quitting... " << endl;

	MMHeap<int> theHeap;
	theHeap.insert(6);

	return 0;
}