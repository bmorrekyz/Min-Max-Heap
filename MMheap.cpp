/*****************************************
** File:    MMheap.cpp
** Project: CMSC 341 Project 4, Spring 2016
** Author:  Dinara Sagitova
** Date:    4/22/16
** Section: 04
** E-mail:  dsagit1@umbc.edu 
**
**   This file contains the implementation of the MMheap class.
***********************************************/

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
	return m_heap.size() - 1;
}

template <typename Comparable>
void MMheap<Comparable>::dump()
{
	cout << "dump()\n" << endl;
}

template <typename Comparable>
void MMheap<Comparable>::insert(Comparable x)
{
	cout << "insert(Comparable x)" << endl;
	cout << "inserted element: " << x << "\n" << endl;
}

template <typename Comparable>
Comparable MMheap<Comparable>::getMin()
{
	cout << "getMin()" << endl;
}

template <typename Comparable>
Comparable MMheap<Comparable>::getMax()
{
	cout << "getMax()" << endl;
}


template <typename Comparable>
Comparable MMheap<Comparable>::deleteMin()
{
	cout << "deleteMin()" << endl;
}

template <typename Comparable>
Comparable MMheap<Comparable>::deleteMax()
{
	cout << "deleteMax()" << endl;
}

#endif