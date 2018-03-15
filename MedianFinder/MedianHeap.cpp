#include "MedianHeap.h"

MedianHeap::MedianHeap(int size):
	m_minHeap(true, size),
	m_maxHeap(false, size)
{
}

void MedianHeap::insert(int value)
{
	if (m_minHeap.heapSize() == 0) 
	{
		// Initial insert
		m_minHeap.insert(value);
		return;
	}

	// check if the value is bigger than the root of the min heap
	if (m_minHeap.getRoot() < value)
	{
		// this value belongs to the higher half of the values
		m_minHeap.insert(value);
	}
	else 
	{
		// this value belongs to the lower half of the values
		m_maxHeap.insert(value);
	}

	// balance the heap in case it's imbalanced
	if (m_minHeap.heapSize() > m_maxHeap.heapSize() + 1)
	{
		// move the highest value of the max heap to the min heap
		m_maxHeap.insert(m_minHeap.extractRoot());
	}
	else if (m_maxHeap.heapSize() > m_minHeap.heapSize() + 1)
	{
		// move the lowest value of the min heap to the max heap
		m_minHeap.insert(m_maxHeap.extractRoot());
	}
}

void MedianHeap::printMedian()
{
	// There are 2 possible cases:
	// 1. One of the heaps has 1 more value than the other
	//    In this case we need to print the root of the larger heap
	// 2. The two heaps have the same, and we should just print the root of the max heap (arbitrary selection)
	if (m_maxHeap.heapSize() + 1 == m_minHeap.heapSize())
	{
		std::cout << m_minHeap.getRoot() << std::endl;
	}
	else
	{
		std::cout << m_maxHeap.getRoot() << std::endl;
	}
}
