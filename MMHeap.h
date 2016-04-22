#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>
#include <vector>

using namespace std;

template <typename Comparable>
class MMHeap
{
public:
	MMHeap();

	~MMHeap();

	int size(); 
	
	void dump();

	void insert(Comparable x);

	Comparable getMin();

	Comparable deleteMin();

private:


	/* TRICKLE DOWN function(s) */

	/* PERCOLATE UP function(s) */

	struct MMNode
	{
		Comparable data;
		MMNode *leftChild;
		MMNode *rightChild;
		MMNode *parent;
		int index, leftChildIndex, rightChildIndex;
		int level;
		int parentLevel;


		MMNode() 
		{	/* default constructor body */
			data = NULL;
			leftChild = NULL;
			rightChild = NULL;
			parent = NULL;
			index = 0;
			leftChildIndex = NULL;
			rightChildIndex = NULL;
			level = 0;
			parentLevel = NULL;

		}

	};

	MMNode *dummyNode;

	int m_size;

	vector<MMNode*> m_heap;

};

#include "MMHeap.cpp"

#endif

