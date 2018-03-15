#pragma once
#include "Heap.h"
#include <iostream>

/*
* MedianHeap allows to extract the median of its memebers in constant time
* It devides the values inserted to it into 2 halves: 1 half is the highest values and the other is the lowest.
* 1. A min heap will hold half of the highest values
* 2. A max heap will hold half of the lowest values
*/
class MedianHeap
{
public:
	/*
	* Initializes a median heap contanining:
	* build 2 heaps, each is supposed one half of the values in the struct
	* 1. A min heap to hold the highest values in the heap
	* 2. A max heap to hold the lowest values in the heap
	*/
	MedianHeap(int size);

	/*
	* Inserts a member to the struct, and updates the median if needed
	* Runtime: O(log n)
	*/
	void insert(int x);

	/*
	* Prints the median number
	* Runs in O(1)
	*/
	void printMedian();

private:
	Heap m_minHeap; // A min heap holding the half of the highest values in the struct
	Heap m_maxHeap; // A max heap holding the half of the lowest values in the struct
};
