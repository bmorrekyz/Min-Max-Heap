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
  	cout << "  Minimum = " << endl;
  	cout << "  Maximum = " << endl;
  	cout << "  Last level is " << endl;

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
	m_heap[0] = x; // initialize sentinel
	
	if ( m_size + 1 == m_heap.size() ) {
		m_heap.resize( m_heap.size() + 1 );
	}

	int hole = ++m_size;

	for ( ; x < m_heap[ hole / 2 ]; hole /= 2 ) {

		m_heap[ hole ] = m_heap[ hole / 2 ];		
	}

	m_heap[ hole ] = x;

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

template <typename Comparable>
void MMheap<Comparable>::buildHeap() 
{
	for (int i = m_size / 2; i > 0; i-- ) {
		percolateDown(i);
	}
}

template <typename Comparable>
void MMheap<Comparable>::percolateDown( int hole )
{
	int child;
	Comparable tmp = m_heap[ hole ];

	for( ; hole * 2 <= m_size; hole = child )
	{
		child = hole * 2;

		if( child != m_size && m_heap[ child + 1 ] < m_heap[ child ] ) {
			child++;
		}

		if( m_heap[ child ] < tmp ) {
			m_heap[ hole ] < m_heap[ child ];
		}

		else {
			break;
		}
	}

	m_heap[ hole ] = tmp;
}

template <typename Comparable>
int MMheap<Comparable>::getLevel( int hole )
{	
	return floor(log2(hole));
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


#endif