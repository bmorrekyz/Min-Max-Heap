/*****************************************
** File:    MMheap.cpp
** Project: CMSC 341 Project 4, Spring 2016
** Author:  Dinara Sagitova
** Date:    4/22/16
** Section: 04
** E-mail:  dsagit1@umbc.edu 
**
**   This file contains the implementation of the MMheap class.
** MMheap has a structure property where even levels represent a min heap.
** Whereas, odd levels represent a max heap. 
***********************************************/

#ifndef MMHEAP_CPP
#define MMHEAP_CPP

#include "MMheap.h"

using namespace std;

template <typename Comparable>
MMheap<Comparable>::MMheap() : m_heap(1), m_size(0)
{ /* intentionally empty constructor body */ }


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


// used inside of insert(x)
template <typename Comparable>
void MMheap<Comparable>::percolateUp(int hole)
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

	else if (isMaxLevel(hole))
	{
		if (hasParent(hole)) 
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


// used inside of percolateUp(hole)
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


// used inside of percolateUp(hole)
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


// used inside of dump()
template <typename Comparable>
Comparable MMheap<Comparable>::getMin()
{
	if (size() == 2)
	{
		if (isSmaller(1, 2))
		{
			cout << "!" << endl;
			return m_heap[1];
		}

		else
		{
			cout << "?" << endl;
			return m_heap[2];
		}
	}
	return m_heap[1];
}


// used inside of dump()
template <typename Comparable>
Comparable MMheap<Comparable>::getMax()
{


	if (size() == 1)
	{
		return m_heap[1];
	}

	else if (size() == 2)
	{
		return m_heap[2];
	}

	else if (m_heap[2] > m_heap[3])
	{
		return m_heap[2];
	}

	else 
	{
		return m_heap[3];
	}


}


// used inside isMinLevel(), isMaxLevel()
template <typename Comparable>
int MMheap<Comparable>::getLevel(int hole)
{	
	int level = floor(log2(hole));
	return level;
}


// if true, go down the MIN path
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


// if true, go down the MAX path
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


// get the parent of the current element
// used in percolation functions
template <typename Comparable>
int MMheap<Comparable>::getParent(int hole)
{
	int parent = hole / 2; 

	return parent;
}


// used in percolation functions
template <typename Comparable>
bool MMheap<Comparable>::hasParent(int hole)
{
	if (getParent(hole) != 0)
	{
		return true;
	}

	else { return false; }
}


// exchanges the positions of two elements 
template <typename Comparable>
void MMheap<Comparable>::swap(int hole, int parent)
{
	int tempHole = m_heap[hole];
	int tempParent = m_heap[parent];

	m_heap[hole] = tempParent;
	m_heap[parent] = tempHole;
}

// displays the state of the min-max heap
template <typename Comparable>
void MMheap<Comparable>::dump()
{
	cout << "--- min-max heap dump --- " << endl;

  	cout << "  Size = " << size() << endl;
  	cout << "  Minimum = " << getMin() << endl;
  	cout << "  Maximum = " << getMax() << endl;

  	cout << "  Last level is ";
  	if (isMinLevel(size())) 
  	{ 
  		cout << "even" << endl;
  	}

  	else if (isMaxLevel(size())) 
  	{ 
  		cout << "odd" << endl;
  	}


	cout << "--- heap data items --- " << endl;
	for ( int i = 1; i <= size(); i++ ) 
	{
		cout << "H[" << i << "] = " << m_heap[ i ] << endl;
	}
}

// used in deleteMin() to get the smaller of two children
template <typename Comparable>
bool MMheap<Comparable>::isSmaller(int hole1, int hole2)
{
	if (m_heap[hole1] < m_heap[hole2])
	{
		return true;
	}

	else { return false; }
}


/* ----- TRICKLE DOWN functions ----- */

/* assumes that by min-heap order property, min element is at index 1. */
template <typename Comparable>
Comparable MMheap<Comparable>::deleteMin()
{
	// min element
	Comparable tmpCopy = m_heap[1];

	// exchange deleted min with the last element in the heap
	m_heap[1] = m_heap.back();

	// delete the last element
	m_heap.pop_back();

	// trickle down the heap the element with used to be at the last index
	trickleDown(1);

	// return deleted element
	return tmpCopy;
}


// used inside of deleteMin()
template <typename Comparable>
void MMheap<Comparable>::trickleDown(int hole)
{	
	// for min heap, trickle down the even levels
	if(isMinLevel(hole))
	{
		trickleDownMin(hole);
	}

	// for the max heap, trickle down the odd levels
	else if (isMaxLevel(hole))
	{
		trickleDownMax(hole);
	}
}

// used to trickle down the even levels
template <typename Comparable>
void MMheap<Comparable>::trickleDownMin(int hole)
{
	// get relationships between elements
	int child1 = 2 * hole;
	int child2 = 2 * hole + 1;

	int grandChild1 = 2 * child1;
	int grandChild2 = 2 * child1 + 1;
	int grandChild3 = 2 * child2;
	int grandChild4 = 2 * child2 + 1; 

	if (hasTwoRightGrandChildren(hole))
	{	
		// if min element is in the left subtree
		if ((m_heap[grandChild1] < m_heap[grandChild3] && m_heap[grandChild1] < m_heap[grandChild4]) ||
			(m_heap[grandChild2] < m_heap[grandChild3] && m_heap[grandChild2] < m_heap[grandChild4]))
		{
			// find the smallest element to swap with the current hole
			if (isSmaller(grandChild1, grandChild2))
			{
				if (m_heap[hole] > m_heap[grandChild1])
				{
					swap(hole, grandChild1);
					trickleDownMin(grandChild1);					
				}
			}

			else if (m_heap[grandChild1] == m_heap[grandChild2])
			{
				if (m_heap[hole] > m_heap[grandChild1]) 
				{ 			
					swap(hole, grandChild1);
					trickleDownMin(grandChild1);
				}
			}
			else
			{
				if (m_heap[hole] > m_heap[grandChild2]) 
				{
					swap(hole, grandChild2);
					trickleDownMin(grandChild2);
				}
			}
		}

		// if min element is in the right subtree
		else
		{
			// find the smallest element to swap with the current hole
			if (isSmaller(grandChild3, grandChild4))
			{
				if (m_heap[hole] > m_heap[grandChild3])
				{
					swap(hole, grandChild3);
					trickleDownMin(grandChild3);
				}
			}

			else if (m_heap[grandChild1] == m_heap[grandChild3])
			{
				if (m_heap[hole] > m_heap[grandChild1])
				{
					swap(hole, grandChild1);
					trickleDownMin(grandChild1);
				}
			}

			else if (m_heap[grandChild2] == m_heap[grandChild4])
			{
				if (m_heap[hole] > m_heap[grandChild2])
				{
					swap(hole, grandChild2);
					trickleDownMin(grandChild2);
				}
			}

			else if (m_heap[grandChild3] == m_heap[grandChild4])
			{
				if (m_heap[hole] > m_heap[grandChild3])
				{
	 				swap(hole, grandChild3);
					trickleDownMin(grandChild3);
				}
			}

			else
			{
				if (m_heap[hole] > m_heap[grandChild4])
				{
					swap(hole, grandChild4);
					trickleDownMin(grandChild4);
				}
			}
		}
	}

	else if (hasOneRightGrandChild(hole))
	{
		// if min element is in the left subtree
		if ((m_heap[grandChild1] < m_heap[grandChild3])  ||
			(m_heap[grandChild2] < m_heap[grandChild3] ))
		{
			// find the smallest element to swap with the current hole
			if (isSmaller(grandChild1, grandChild2))
			{
				if (m_heap[hole] > m_heap[grandChild1])
				{
					swap(hole, grandChild1);
					trickleDownMin(grandChild1);					
				}
			}

			else if (m_heap[grandChild1] == m_heap[grandChild2])
			{
				if (m_heap[hole] > m_heap[grandChild1]) 
				{ 			
					swap(hole, grandChild1);
					trickleDownMin(grandChild1);
				}
			}
			else
			{
				if (m_heap[hole] > m_heap[grandChild2]) 
				{
					swap(hole, grandChild2);
					trickleDownMin(grandChild2);
				}
			}
		}

		// if min element is in the right subtree
		else
		{
			if (m_heap[hole] > m_heap[grandChild3])
			{
				swap(hole, grandChild3);
				trickleDownMin(grandChild3);
			}
		}
	}

	else if (hasTwoLeftGrandChildren(hole))
	{
		if (isSmaller(grandChild1, grandChild2))
		{
			if (m_heap[hole] > m_heap[grandChild1])
			{
				swap(hole, grandChild1);
				trickleDownMin(grandChild1);				
			}
		}

		else
		{
			if (m_heap[hole] > m_heap[grandChild2])
			{
				swap(hole, grandChild2);
				trickleDownMin(grandChild2);					
			}
		}
	}

	else if (hasOneLeftGrandChild(hole))
	{
		if (m_heap[hole] > m_heap[grandChild1])
		{
			swap(hole, grandChild1);
			trickleDownMin(grandChild1);				
		}
	}
}

template <typename Comparable>
bool MMheap<Comparable>::hasLeftChild(int hole)
{
	if (2 * hole <= size())
	{
		return true;
	}

	else 
	{
		return false;
	}
}

template <typename Comparable>
bool MMheap<Comparable>::hasRightChild(int hole)
{
	if ((2 * hole + 1) <= size())
	{
		return true;
	}

	else 
	{
		return false;
	}	
}

template <typename Comparable>
bool MMheap<Comparable>::hasOneLeftGrandChild(int hole)
{
	int leftChild = 2 * hole;
	if (hasLeftChild(leftChild))
	{
		return true;
	}

	else
	{
		return false;
	}
}

template <typename Comparable>
bool MMheap<Comparable>::hasTwoLeftGrandChildren(int hole)
{
	int leftChild = 2 * hole;

	if (hasLeftChild(leftChild) && hasRightChild(leftChild))
	{
		return true;
	}

	else
	{
		return false;
	}
}

template <typename Comparable>
bool MMheap<Comparable>::hasOneRightGrandChild(int hole)
{
	int rightChild = 2 * hole + 1;

	if (hasLeftChild(rightChild)) 
	{
		return true;
	}

	else 
	{
		return false;
	}
}

template <typename Comparable>
bool MMheap<Comparable>::hasTwoRightGrandChildren(int hole)
{
	int rightChild = 2 * hole + 1;

	if (hasLeftChild(rightChild) && hasRightChild(rightChild))
	{
		return true;
	}

	else
	{
		return false;
	}	
}


template <typename Comparable>
Comparable MMheap<Comparable>::deleteMax()
{
	Comparable tmpCopy; 

	if (size() <= 1)
	{
		cout << "Error: can't delete from an empty heap" << endl;
		return 1;
	}

	else if (size() == 2)
	{
		tmpCopy = m_heap.back();
		m_heap.pop_back();
		return m_heap[2];
	}

	else if (size() == 3)
	{
		if (m_heap[2] > m_heap[3])
		{
			m_heap[2] = m_heap.back();
			tmpCopy = m_heap.back();
			m_heap.pop_back();
		}

		else if (m_heap[2] < m_heap[3])
		{
			tmpCopy = m_heap.back();
			m_heap.pop_back();	
		}

		return tmpCopy;
	}

	else if (size() == 4)
	{
		if (isSmaller(2, 3))
		{
			m_heap[3] = m_heap.back();
			tmpCopy = m_heap.back();
			m_heap.pop_back();
		}
		else 
		{
			m_heap[2] = m_heap.back();
			tmpCopy = m_heap.back();
			m_heap.pop_back();
		}
	}

	else 
	{
		if (isSmaller(2, 3))
		{
			m_heap[3] = m_heap.back();
			tmpCopy = m_heap.back();
			m_heap.pop_back();
			trickleDown(3);
		}
		else 
		{
			m_heap[2] = m_heap.back();
			tmpCopy = m_heap.back();
			m_heap.pop_back();
			trickleDown(2);
		}
	}
	return tmpCopy;
}


template <typename Comparable>
void MMheap<Comparable>::trickleDownMax(int hole)
{

	int child1 = 2 * hole;
	int child2 = 2 * hole + 1;

	int grandChild1 = 2 * child1;
	int grandChild2 = 2 * child1 + 1;
	int grandChild3 = 2 * child2;
	int grandChild4 = 2 * child2 + 1; 

	if (hasTwoRightGrandChildren(hole))
	{	
		// if min element is in the left subtree
		if ((m_heap[grandChild1] > m_heap[grandChild3] && m_heap[grandChild1] > m_heap[grandChild4]) ||
			(m_heap[grandChild2] > m_heap[grandChild3] && m_heap[grandChild2] > m_heap[grandChild4]))
		{
			// find the smallest element to swap with the current hole
			if (!isSmaller(grandChild1, grandChild2))
			{
				if (m_heap[hole] < m_heap[grandChild1])
				{
					swap(hole, grandChild1);
					trickleDownMax(grandChild1);					
				}
			}

			else if (m_heap[grandChild1] == m_heap[grandChild2])
			{
				if (m_heap[hole] < m_heap[grandChild1]) 
				{ 		
					swap(hole, grandChild1);
					trickleDownMax(grandChild1);
				}
			}
			else
			{
				if (m_heap[hole] < m_heap[grandChild2]) 
				{
					swap(hole, grandChild2);
					trickleDownMax(grandChild2);
				}
			}
		}

		// if min element is in the right subtree
		else
		{
			// find the smallest element to swap with the current hole
			if (!isSmaller(grandChild3, grandChild4))
			{
				if (m_heap[hole] < m_heap[grandChild3])
				{
					swap(hole, grandChild3);
					trickleDownMax(grandChild3);
				}
			}

			else if (m_heap[grandChild1] == m_heap[grandChild3])
			{
				if (m_heap[hole] < m_heap[grandChild1])
				{
					swap(hole, grandChild1);
					trickleDownMax(grandChild1);
				}
			}

			else if (m_heap[grandChild2] == m_heap[grandChild4])
			{
				if (m_heap[hole] < m_heap[grandChild2])
				{
					swap(hole, grandChild2);
					trickleDownMax(grandChild2);
				}
			}

			else if (m_heap[grandChild3] == m_heap[grandChild4])
			{
				if (m_heap[hole] < m_heap[grandChild3])
				{
	 				swap(hole, grandChild3);
					trickleDownMax(grandChild3);
				}
			}

			else
			{
				if (m_heap[hole] < m_heap[grandChild4])
				{
					swap(hole, grandChild4);
					trickleDownMax(grandChild4);
				}
			}
		}
	}

	else if (hasOneRightGrandChild(hole))
	{
		// if max element is in the left subtree
		if ((m_heap[grandChild1] > m_heap[grandChild3])  ||
			(m_heap[grandChild2] > m_heap[grandChild3] ))
		{
			// find the largest element to swap with the current hole
			if (!isSmaller(grandChild1, grandChild2))
			{
				if (m_heap[hole] < m_heap[grandChild1])
				{
					swap(hole, grandChild1);
					trickleDownMax(grandChild1);					
				}
			}

			else if (m_heap[grandChild1] == m_heap[grandChild2])
			{
				if (m_heap[hole] < m_heap[grandChild1]) 
				{ 			
					swap(hole, grandChild1);
					trickleDownMax(grandChild1);
				}
			}
			else
			{
				if (m_heap[hole] < m_heap[grandChild2]) 
				{
					swap(hole, grandChild2);
					trickleDownMax(grandChild2);
				}
			}
		}

		// if max element is in the right subtree
		else
		{
			if (m_heap[hole] < m_heap[grandChild3])
			{
				swap(hole, grandChild3);
				trickleDownMax(grandChild3);
			}
		}
	}

	else if (hasTwoLeftGrandChildren(hole))
	{
		if (isSmaller(grandChild1, grandChild2))
		{
			if (m_heap[hole] < m_heap[grandChild1])
			{
				swap(hole, grandChild1);
				trickleDownMax(grandChild1);				
			}
		}

		else
		{
			if (m_heap[hole] < m_heap[grandChild2])
			{
				swap(hole, grandChild2);
				trickleDownMax(grandChild2);					
			}
		}
	}

	else if (hasOneLeftGrandChild(hole))
	{
		if (m_heap[hole] < m_heap[grandChild1])
		{
			swap(hole, grandChild1);
			trickleDownMax(grandChild1);				
		}
	}

}





#endif