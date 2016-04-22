/*****************************************
** File:    MMheap.h
** Project: CMSC 341 Project 4, Spring 2016
** Author:  Dinara Sagitova
** Date:    4/22/16
** Section: 04
** E-mail:  dsagit1@umbc.edu 
**
**   This file contains the interface of the MMheap class.
***********************************************/

#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>
#include <vector>

using namespace std;

template <typename Comparable>
class MMheap
{
public:

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/
	MMheap();

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/
	~MMheap();

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	int size(); 

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/
	void dump();

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/
	void insert(Comparable x);

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/
	Comparable getMin();

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/
	Comparable getMax();

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/
	Comparable deleteMin();

	/*	Description:    
		Pre-condition:  
		Post-condition:	
	*/	
	Comparable deleteMax();

private:

	/* Node class for a MinMaxHeap */
	class MMNode
	{
		Comparable data;
		MMNode *leftChild;
		MMNode *rightChild;
		MMNode *parent;
		int index, leftChildIndex, rightChildIndex;
		int level;
		int parentLevel;

		/* default constructor */
		MMNode() 
		{	
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

	/* DATA MEMBERS */

	MMNode *dummyNode;

	int m_size;

	vector<MMNode*> m_heap;

};

#include "MMheap.cpp"

#endif

