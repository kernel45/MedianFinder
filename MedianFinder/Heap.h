#pragma once
#include <vector>

class Heap
{
public:
	/*
	* initialize an empty min/max heap
	* parameter isMin: if true, this is a min heap. Otherwise, it's a max heap
	* parameter maxSize: the maximum size limit of the heap
	*/
	Heap(bool isMin, int maxSize);

	/*
	* destructs the min/max heap
	*/
	~Heap();

	/*
	* inserts an integer to the heap
	*/
	void insert(int value);

	/*
	* Retrieves the value of the root (first element - minimal element in a min heap, maximal element in a max heap)
	* Does not remove the root from the heap
	*/
	int getRoot();

	/*
	* Retrieves the value of the root and removes it from the heap
	*/
	int extractRoot();

	/*
	* Retrieves the current size of the heap (amount of elements in it)
	*/
	int heapSize();

private:

	/*
	* Receives two indexes and retrieves the index of the element with the larger value
	*/
	int getMaxIndex(int firstIndex, int secondIndex);

	/*
	* Receives two indexes and retrieves the index of the element with the smaller value
	*/
	int getMinIndex(int firstIndex, int secondIndex);

	/*
	* Retrieves the parent index of the given index
	*/
	int parent(int index);

	/*
	* Retrieves the left child index of the given index
	*/
	int left(int index);

	/*
	* Retrieves the right child index of the given index
	*/
	int right(int index);

	/*
	* Receives an index and bubbles it down as long it is not positioned currectly in the heap
	* This function is necessary after we replace the root with anoter value, in order to find the new root
	* and position it at the top of the heap
	*/
	void heapify(int index);

	/*
	* Receives two indexes and swaps the elements in those indexes
	*/
	void swapIndexes(int index1, int index2);

	/*
	* Receives an index and bubbles it up as long it is not positioned currectly in the heap
	* This function is necessary after we insert a new value to the heap, in order to find the correct
	* position for the new value in the heap
	*/
	void increaseKey(int index);

	bool m_isMin; // If true, this is a Minimum Heap, otherwise this is a Maximum Heap
	int m_length; // The size of the heap
	int m_maxLength; // The size of the heap
	int* m_array; // The array that holds the values
};