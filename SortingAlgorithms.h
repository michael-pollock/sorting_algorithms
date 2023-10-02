
#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <math.h>
using namespace std;

template <class T>
void bubbleSort(T data[], int size);

template <class T>
void insertionSort(T data[], int size);

template <class T>
void merge(T data[], int begin, int mid, int end);

template <class T>
void mergeSort(T data[], int begin, int end);

template <class T>
T partition(T data[], int begin, int end);

template <class T>
void quicksort(T data[], int begin, int end);

template <class T>
void testSorted(T data, int size);

template <class T>
void fillArray(T data[], int size);

template <class T>
void allocateArray(string sorter, T* data[], int dataSize[], int size, int baseSize);

template <class T>
void deleteArray(string sorter, T* data[], int size);

int main();