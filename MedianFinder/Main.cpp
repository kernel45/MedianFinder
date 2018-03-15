#include <iostream>
#include <random>
#include <ctime>
#include "MedianHeap.h"

const int RANDOM_NUMBERS_LIMIT = 1024; // The limit of the random numbers

/*
* Initializes a new array with random values in the range of 0-1023
*/
void initializeArray(int arr[], int size, int randomLimit)
{
	std::srand(std::time(nullptr)); // seed the random generator using current time
	for (int i = 0; i < size; i++)
	{
		arr[i] = std::rand() % randomLimit; // Generate a random number in the range of 0-1023
	}
}

/*
* receives an array of integers, and 3 different checkpoints
* inserts the elements to the MedianHeap one by one, and prints the median value at each checkpoint
*/
void processArray(int arr[], int size, int check1, int check2, int check3)
{
	// build an empty MedianHeap to hold the values
	MedianHeap medianHeap(size);
	for (int i = 0; i < size; i++)
	{
		// insert the current value to the struct
		medianHeap.insert(arr[i]); // this will also update the new median of the struct
		if (i == check1 || i == check2 || i == check3)
		{
			// if we reached one of the checkpoints print the current median
			std::cout << "median after reading the " << i << "th value: ";
			medianHeap.printMedian();
		}
	}
	std::cout << "median after reading the entire input array: ";
	medianHeap.printMedian();
	std::cout << std::endl; // print an additional line
}

/*
* creates 3 different arrays and initializes them with random numbers in the range of 0-1023
* then iterates the arrays and prints the median values at various checkpoints
*/
int main()
{
	// Initialize the sizes of the arrays
	const int n1 = 200;
	const int n2 = 400;
	const int n3 = 800;
	// Build the empty arrays
	int firstArray[n1] = { 0 };
	int secondArray[n2] = { 0 };
	int thirdArray[n3] = { 0 };

	// initialize each array with random numbers in the range of 0-1023
	initializeArray(firstArray, n1, RANDOM_NUMBERS_LIMIT);
	initializeArray(secondArray, n2, RANDOM_NUMBERS_LIMIT);
	initializeArray(thirdArray, n3, RANDOM_NUMBERS_LIMIT);

	// for each array:
	// 1. iterate it's values
	// 2. at each of the given checkpoint, print the current median of the values already iterated
	std::cout << "first array: " << std::endl; 
	processArray(firstArray, n1, n1 / 4, n1 / 2, (3 * n1) / 4);

	std::cout << "second array: " << std::endl;
	processArray(secondArray, n2, n2 / 4, n2 / 2, (3 * n2) / 4);

	std::cout << "third array: " << std::endl;
	processArray(thirdArray, n3, n3 /4, n3 /2, (3 * n3) / 4);

	getchar();
	return 0;
}