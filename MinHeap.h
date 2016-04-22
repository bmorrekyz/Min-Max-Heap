#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>
#include <vector>

using namespace std;

template <typename Comparable>
class MinHeap
{
public:
	MinHeap() 
	{
		MMNode *dummyNode;
		m_heap.push_back(dummyNode);
	}

	~MinHeap()
	{
		/* empty destructor body */
	}

	int size() 
	{
		return 0;
	}
	
	void dump()
	{
		cout << "dump()\n" << endl;
	}

	void insert(Comparable x)
	{
		cout << "insert(Comparable x)\n" << endl;
		cout << "inserted element: " << x << endl;
	}

	Comparable getMin()
	{
		cout << "getMin()" << endl;
	}

	Comparable deleteMin()
	{
		cout << "deleteMin()" << endl;
	}

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


// #include "MinHeap.cpp"
#endif

