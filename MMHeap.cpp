#ifndef MMHEAP_CPP
#define MMHEAP_CPP

#include "MMHeap.h"

using namespace std;

template <typename Comparable>
MMHeap<Comparable>::MMHeap() 
{
	MMNode *dummyNode;
	m_heap.push_back(dummyNode);
}

template <typename Comparable>
MMHeap<Comparable>::~MMHeap()
{
	/* empty destructor body */
}

template <typename Comparable>
int MMHeap<Comparable>::size() 
{
	return 0;
}

template <typename Comparable>
void MMHeap<Comparable>::dump()
{
	cout << "dump()\n" << endl;
}

template <typename Comparable>
void MMHeap<Comparable>::insert(Comparable x)
{
	cout << "insert(Comparable x)\n" << endl;
	cout << "inserted element: " << x << endl;
}

template <typename Comparable>
Comparable MMHeap<Comparable>::getMin()
{
	cout << "getMin()" << endl;
}

template <typename Comparable>
Comparable MMHeap<Comparable>::deleteMin()
{
	cout << "deleteMin()" << endl;
}

#endif