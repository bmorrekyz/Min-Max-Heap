#ifndef MMHEAP_CPP
#define MMHEAP_CPP

#include "MMheap.h"

using namespace std;

template <typename Comparable>
MMheap<Comparable>::MMheap() 
{
	MMNode *dummyNode;
	m_heap.push_back(dummyNode);
}

template <typename Comparable>
MMheap<Comparable>::~MMheap()
{
	/* empty destructor body */
}

template <typename Comparable>
int MMheap<Comparable>::size() 
{
	return 0;
}

template <typename Comparable>
void MMheap<Comparable>::dump()
{
	cout << "dump()\n" << endl;
}

template <typename Comparable>
void MMheap<Comparable>::insert(Comparable x)
{
	cout << "insert(Comparable x)\n" << endl;
	cout << "inserted element: " << x << endl;
}

template <typename Comparable>
Comparable MMheap<Comparable>::getMin()
{
	cout << "getMin()" << endl;
}

template <typename Comparable>
Comparable MMheap<Comparable>::deleteMin()
{
	cout << "deleteMin()" << endl;
}

#endif