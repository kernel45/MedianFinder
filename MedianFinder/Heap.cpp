#include "Heap.h"

Heap::Heap(bool isMin, int maxSize):
	m_isMin(isMin),
	m_length(0),
	m_maxLength(maxSize),
	m_array(new int[maxSize])
{
}

Heap::~Heap()
{
	delete[] m_array;
}

void Heap::insert(int value)
{
	// Increase the size by 1
	m_length++;
	if (m_length > m_maxLength)
	{
		throw std::exception("Heap Overflow");
	}
	// insert the value to the end
	int indexToInsert = m_length - 1;
	m_array[indexToInsert] = value;
	// move the key up the heap until it's positioned correctly in the heap
	increaseKey(indexToInsert);
}

int Heap::parent(int index)
{
	return (index - 1) / 2; // The integer division rounds down as needed
}

int Heap::left(int index)
{
	return (2 * index) + 1;
}

int Heap::right(int index)
{
	return (2 * index) + 2;
}

int Heap::heapSize()
{
	return m_length;
}

int Heap::getRoot()
{
	if (m_length < 1)
	{
		throw std::exception("Heap Overflow");
	}
	return m_array[0];
}

int Heap::extractRoot()
{
	if (m_length < 1)
	{
		throw std::exception("Heap Overflow");
	}
	// Save the root value
	int rootValue = m_array[0];
	// overwrite the root with the last value
	m_array[0] = m_array[m_length - 1];
	// delete the last value in the heap by decreasing it's size by 1
	m_length--;
	// Now the first key is not correctly positioned
	// move the root key down until it's positioned correctly
	heapify(0);
	// returned the saved root value
	return rootValue;
}

int Heap::getMaxIndex(int firstIndex, int secondIndex)
{
	if (m_array[firstIndex] < m_array[secondIndex])
	{
		// the second index is higher
		return secondIndex;
	}
	// the first index is lower
	return firstIndex;
}

int Heap::getMinIndex(int firstIndex, int secondIndex)
{
	if (m_array[firstIndex] > m_array[secondIndex])
	{
		// the second index is lower
		return secondIndex;
	}
	// the second index is higher
	return firstIndex;
}

void Heap::heapify(int index)
{
	int leftChildIndex = left(index); // index of the left child
	int rightChildIndex = right(index); // index of the right child
	// indexToSwap will hold the index of the child we want to swap (or the current index if we don't need to swap)
	// if min heap it should hold the index of the minimum among the current node and it's children
	// if max heap it should hold the index of the maximum among the current node and it's children
	int indexToSwap = index; 

	// check if it has a left child
	if (leftChildIndex < m_length)
	{
		// if min heap, get the smaller number between the parent and left child
		// if max heap, get the larger
		indexToSwap = m_isMin ? getMinIndex(indexToSwap, leftChildIndex) : getMaxIndex(indexToSwap, leftChildIndex);
	}

	// check if it has a right child
	if (rightChildIndex < m_length)
	{
		// if min heap, get the smaller number between the minimum we already found and right child
		// if max heap, get the larger number between the maximum we already found and right child
		indexToSwap = m_isMin ? getMinIndex(indexToSwap, rightChildIndex) : getMaxIndex(indexToSwap, rightChildIndex);
	}

	// Check if we need to swap the current index with one of it's children
	if (indexToSwap != index)
	{
		// swap the indexes and recursivly call Heapify on the swapped index (to check if more swaps are needed)
		swapIndexes(indexToSwap, index);
		heapify(indexToSwap);
	}
}

void Heap::swapIndexes(int index1, int index2)
{
	// hold one of the values in a temporary value
	int temp = m_array[index1];
	m_array[index1] = m_array[index2];
	m_array[index2] = temp;
}


void Heap::increaseKey(int index)
{
	int parentIndex = parent(index); // the parent index
	int currentIndex = index; // The current index

	// In a min/max heap while the parent is bigger/smaller than the current key, swap them
	while (currentIndex > 0 &&
		m_isMin ? m_array[parentIndex] > m_array[currentIndex] : m_array[parentIndex] < m_array[currentIndex])
	{
		swapIndexes(currentIndex, parentIndex);
		// go up one level
		currentIndex = parentIndex; // set the current index to the parent
		parentIndex = parent(currentIndex); // set the parent to the parent of the new index
	}
}
