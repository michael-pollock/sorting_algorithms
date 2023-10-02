
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <math.h>
#include "SortingAlgorithms.h"
using namespace std;

int main() {

	//Tests
	int testBubble[] = { 9, 7, 5, 3, 1, 8, 6, 4, 2, 5 };
	int testInsert[] = { 9, 7, 5, 3, 1, 8, 6, 4, 2, 5 };
	int testMerge[] = { 9, 7, 5, 3, 1, 8, 6, 4, 2, 5 };
	int testQuick[] = { 9, 7, 5, 3, 1, 8, 6, 4, 2, 5 };
	bubbleSort(testBubble, 10);
	insertionSort(testInsert, 10);
	mergeSort(testMerge, 0, 9);
	quicksort(testQuick, 0, 9);
	testSorted(testBubble, 10);
	testSorted(testBubble, 10);
	testSorted(testMerge, 10);
	testSorted(testQuick, 10);

	
	srand(time(NULL));
	int numOfArrays = 10;
	int* bubbleArrayHolder[10];
	int bubbleArraySize[10];
	int* instertionArrayHolder[10];
	int insertionArraySize[10];
	int* mergeArrayHolder[10];
	int mergeArraySize[10];
	int* quickArrayHolder[10];
	int quickArraySize[10];
	
	allocateArray("BubbleSort", bubbleArrayHolder, bubbleArraySize, numOfArrays, 5000);
	allocateArray("InsertionSort", instertionArrayHolder, insertionArraySize, numOfArrays, 8000);
	allocateArray("MergeSort", mergeArrayHolder, mergeArraySize, numOfArrays, 300000);
	allocateArray("Quicksort", quickArrayHolder, quickArraySize, numOfArrays, 1000000);
	cout << endl;
	

	ofstream outputFile;
	outputFile.open("algorithm_runtime_data.csv");
	outputFile << "t(n) = actual runtime in seconds | T(n) = calculated runtime | t(n)/T(n) = ratio" << endl;
	outputFile << endl;
	outputFile << "Sorting Type, n, t(n), T(n), t(n)/T(n)" << endl;
	
	long double estimatedRunTime;
	clock_t timer;
	cout << "BubbleSort is running..." << endl;
	for (int i = 0; i < 10; i++) {
		timer = clock();
		bubbleSort(bubbleArrayHolder[i], bubbleArraySize[i]);
		timer = clock() - timer;
		estimatedRunTime = ((bubbleArraySize[i] / 1000) * (bubbleArraySize[i]/1000));
		double runtime = (double)timer / CLOCKS_PER_SEC;
		double ratio = (runtime / estimatedRunTime)*10000;
		outputFile << "BubbleSort:," << bubbleArraySize[i] << ","
			<< runtime << "," << estimatedRunTime << "," << ratio << endl;
	}
	outputFile << endl;
	deleteArray("BubbleSort", bubbleArrayHolder, numOfArrays);

	outputFile << "Sorting Type, n, t(n), T(n), t(n)/T(n)" << endl;
		cout << "InsertionSort is running..." << endl;
	for (int i = 0; i < 10; i++) {
		timer = clock();
		insertionSort(instertionArrayHolder[i], insertionArraySize[i]);
		timer = clock() - timer;
		estimatedRunTime = ((insertionArraySize[i]/1000) * (insertionArraySize[i]/1000));
		double runtime = (double)timer / CLOCKS_PER_SEC;
		double ratio = (runtime / estimatedRunTime)*10000;
		outputFile << "InsertionSort:," << insertionArraySize[i] << ","
			<< runtime << "," << estimatedRunTime << "," << ratio << endl;
	}
	outputFile << endl;
	deleteArray("InsertionSort", instertionArrayHolder, numOfArrays);

	outputFile << "Sorting Type, n, t(n), T(n), t(n)/T(n)" << endl;
	cout << "MergeSort is running..." << endl;
	for (int i = 0; i < 10; i++) {
		timer = clock();
		mergeSort(mergeArrayHolder[i], 0, mergeArraySize[i] - 1);
		timer = clock() - timer;
		estimatedRunTime = (mergeArraySize[i]*log(mergeArraySize[i]))/10000;
		double runtime = (double)timer / CLOCKS_PER_SEC;
		double ratio = (runtime / estimatedRunTime)*100000;
		outputFile << "MergeSort," << mergeArraySize[i] << ","
			<< runtime << "," << estimatedRunTime << "," << ratio << endl;
	}
	outputFile << endl;
	deleteArray("MergeSort", mergeArrayHolder, numOfArrays);

	outputFile << "Sorting Type, n, t(n), T(n), t(n)/T(n)" << endl;
	cout << "Quicksort is running..." << endl;
	for (int i = 0; i < 10; i++) {
		timer = clock();
		quicksort(quickArrayHolder[i], 0, quickArraySize[i] - 1);
		timer = clock() - timer;
		estimatedRunTime = (quickArraySize[i] * log(quickArraySize[i]))/10000;
		double runtime = (double)timer / CLOCKS_PER_SEC;
		double ratio = (runtime / estimatedRunTime)*100000;
		outputFile << "Quicksort:," << quickArraySize[i] << ","
			<< runtime << "," << estimatedRunTime << "," << ratio << endl;
	}
	deleteArray("Quicksort", quickArrayHolder, numOfArrays);
	cout << endl;
	
	cout << "Done. Runtime table stored in algorithm_runtime_data.csv" << endl;
	outputFile.close();	
	return 0;
}

template <class T>
void bubbleSort(T data[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				T temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}

template <class T>
void insertionSort(T data[], int size) {
	for (int i = 1; i < size; i++) {
		int lastPosition = i - 1;
		int key = i;
		while (data[key] < data[lastPosition]) {
			T temp = data[key];
			data[key] = data[lastPosition];
			data[lastPosition] = temp;
			if (lastPosition > 0)
				lastPosition--;
			key--;
		}
	}
}

template <class T>
void merge(T data[], int begin, int mid, int end) {
	int resultSize = end - begin + 1;
	T* result = new T[resultSize];
	int leftIndex = begin;
	int rightIndex = mid + 1;
	int resultIndex = 0;
	while (leftIndex <= mid && rightIndex <= end) {
		if (data[leftIndex] < data[rightIndex]) {
			result[resultIndex] = data[leftIndex];
			leftIndex++;
		}
		else {
			result[resultIndex] = data[rightIndex];
			rightIndex++;
		}
		resultIndex++;
	}
	while (leftIndex <= mid) {
		result[resultIndex] = data[leftIndex];
		leftIndex++;
		resultIndex++;
	}
	while (rightIndex <= end && resultIndex <= resultSize) {
		result[resultIndex] = data[rightIndex];
		rightIndex++;
		resultIndex++;
	}
	for (int i = 0; i < resultSize; i++) {
		data[begin + i] = result[i];
	}
	delete[] result;
}

template <class T>
void mergeSort(T data[], int begin, int end) {
	if (begin < end) {
		int mid = (begin + end) / 2;
		mergeSort(data, begin, mid);
		mergeSort(data, mid + 1, end);
		merge(data, begin, mid, end);
	}
}

template <class T>
T partition(T data[], int begin, int end) {
	int j = begin;
	int i = begin - 1;
	T pivot = data[end];
	for (j; j <= (end - 1); j++) {
		if (data[j] < pivot) {
			i++;
			T temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	T temp = data[i + 1];
	data[i + 1] = data[end];
	data[end] = temp;
	return i + 1;
}

template <class T>
void quicksort(T data[], int begin, int end) {
	if (begin < end) {
		int p = partition(data, begin, end);
		quicksort(data, begin, p - 1);
		quicksort(data, p + 1, end);
	}
}


template <class T>
void testSorted(T data, int size) {
	for (int i = 0; i < size - 1; i++) {
		assert(data[i] <= data[i + 1]);
	}
	cout << "Properly sorted. Good work!" << endl;
}

template <class T>
void fillArray(T data[], int size) {
	for (int i = 0; i < size; i++) {
		data[i] = rand() % 100000;
	}
}

template <class T>
void allocateArray(string sorter, T* data[], int dataSize[], int size, int baseSize) {
	for (int i = 0; i < size; i++) {
		dataSize[i] = baseSize * (i + 1);
		data[i] = new int[dataSize[i]];
		fillArray(data[i], dataSize[i]);
		cout << "created array[" << i << "] for " << sorter << endl;
	}
}

template <class T>
void deleteArray(string sorter, T* data[], int size) {
	for (int i = 0; i < size; i++) {
		delete[] data[i];
		cout << "deleted array[" << i << "] for " << sorter << endl;
	}
}

