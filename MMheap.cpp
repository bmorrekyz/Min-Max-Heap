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
MMheap<Comparable>::MMheap() : m_heap(1), m_size(0)
{ /* intentionally empty constructor body */ }

// Construct the binary heap.
// v is a vector containing the initial items.
template <typename Comparable>
MMheap<Comparable>::MMheap( const vector<Comparable> &v )
	: m_heap( v.size() + 1 ), m_size( v.size() )
{
	for( int i = 0; i < v.size(); i++ ) {
		m_heap[ i + 1 ] = v[ i ];
	}

	buildHeap();
}

template <typename Comparable>
MMheap<Comparable>::~MMheap()
{	/* empty destructor body */ }

template <typename Comparable>
int MMheap<Comparable>::size() 
{	
	int size = m_heap.size() - 1;
	return size;
}


template <typename Comparable>
void MMheap<Comparable>::dump()
{
	cout << "--- min-max heap dump --- " << endl;

  	cout << "  Size = " << size() << endl;
  	cout << "  Minimum = " << getMin() << endl;
  	cout << "  Maximum = " << getMax() << endl;

  	cout << "  Last level is ";
  	if (isMinLevel(size())) { cout << "even" << endl;}
  	else if (isMaxLevel(size())) { cout << "odd" << endl;}

	cout << "--- heap data items --- " << endl;

	for ( int i = 1; i <= size(); i++ ) 
	{
		cout << "H[" << i << "] = " << m_heap[ i ] << endl;
	}

	cout << "------------------------- " << endl;
}


template <typename Comparable>
void MMheap<Comparable>::insert(const Comparable &x)
{
	// dummy header node
	m_heap[0] = x;   

	if ( m_size + 1 == m_heap.size() ) {
		m_heap.resize( m_heap.size() + 1 );
	}

	int hole = ++ m_size;

	m_heap[hole] = x;

	percolateUp(hole);

}


template <typename Comparable>
Comparable MMheap<Comparable>::getMin()
{
	return m_heap[1];
}

template <typename Comparable>
Comparable MMheap<Comparable>::getMax()
{
	if (m_heap[2] > m_heap[3])
	{
		return m_heap[2];
	}

	else 
	{
		return m_heap[3];
	}
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

// template <typename Comparable>
// void MMheap<Comparable>::buildHeap() 
// {
// 	for (int i = m_size / 2; i > 0; i-- ) {
// 		percolateDown(i);
// 	}
// }

// template <typename Comparable>
// void MMheap<Comparable>::percolateDown( int hole )
// {
// 	int child;
// 	Comparable tmp = m_heap[ hole ];

// 	for( ; hole * 2 <= m_size; hole = child )
// 	{
// 		child = hole * 2;

// 		if( child != m_size && m_heap[ child + 1 ] < m_heap[ child ] ) {
// 			child++;
// 		}

// 		if( m_heap[ child ] < tmp ) {
// 			m_heap[ hole ] < m_heap[ child ];
// 		}

// 		else {
// 			break;
// 		}
// 	}

// 	m_heap[ hole ] = tmp;
// }

template <typename Comparable>
int MMheap<Comparable>::getLevel( int hole )
{	
	int level = floor(log2(hole));
	return level;
}

template <typename Comparable>
bool MMheap<Comparable>::isMinLevel(int hole)
{	
	int result = getLevel(hole) % 2;

	if ( result == 0 )
	{
		return true;
	}

	else { return false; }
}


template <typename Comparable>
bool MMheap<Comparable>::isMaxLevel(int hole)
{
	int result = getLevel(hole) % 2;
	
	if ( result == 0 )
	{
		return false;
	}

	else { return true; }
}

template <typename Comparable>
int MMheap<Comparable>::getParent(int hole)
{
	int parent = hole / 2; 

	return parent;
}

template <typename Comparable>
bool MMheap<Comparable>::hasParent(int hole)
{
	if (getParent(hole) != 0)
	{
		return true;
	}

	else { return false; }
}

template <typename Comparable>
void MMheap<Comparable>::percolateUp( int hole )
{
	if (isMinLevel(hole)) 
	{
		if (hasParent(hole)) 
		{
			Comparable child = m_heap[hole]; 
			Comparable parent = m_heap[getParent(hole)];

			if ( child > parent) 
			{
				swap(hole, getParent(hole));
				percolateUpMax(getParent(hole));
			}	

			else 
			{
				percolateUpMin(hole);
			}
		}
	}

	else
	{
		if(hasParent(hole)) 
		{
			Comparable child = m_heap[hole]; 
			Comparable parent = m_heap[getParent(hole)];

			if ( child < parent) 
			{
				swap(hole, getParent(hole));

				percolateUpMin(getParent(hole));
			}

			else
			{
				percolateUpMax(hole);
			}
		}
	}
}


template <typename Comparable>
void MMheap<Comparable>::percolateUpMin(int hole)
{
	int grandparent = getParent(getParent(hole));

	if (grandparent != 0) 
	{
		if (m_heap[hole] < m_heap[grandparent])
		{
			swap(hole, grandparent);

			percolateUpMin(grandparent);
		}
	}
}


template <typename Comparable>
void MMheap<Comparable>::percolateUpMax(int hole)
{
	int grandparent = getParent(getParent(hole));

	if (grandparent != 0) 
	{
		if (m_heap[hole] > m_heap[grandparent])
		{
			swap(hole, grandparent);

			percolateUpMax(grandparent);
		}
	}
}


template <typename Comparable>
void MMheap<Comparable>::swap(int hole, int parent)
{
	int tempHole = m_heap[hole];
	int tempParent = m_heap[parent];

	m_heap[hole] = tempParent;
	m_heap[parent] = tempHole;
}

#endif