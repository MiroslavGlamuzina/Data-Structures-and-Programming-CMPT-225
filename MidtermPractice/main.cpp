/*
 * main.cpp
 *
 *  Created on: Oct 16, 2015
 *      Author: miroslav
 */
#include "iostream"
#include "stdio.h"
#include "cstdlib"

int arr[100];
int arrHolder[100];
int count = 0;
void init() {
	count = 0;
	for (int i = 0; i < 100; i++) {
		arr[i] = rand() % 1000;
	}
}
void printArr(std::string str) {
	for (int i = 0; i < 100; i++) {
		std::cout << str << "| [" << i << "]: " << arr[i] << std::endl;
	}
	std::cout << str << " iterations: " << count << std::endl;
}

void printCount(std::string str) {
	std::cout << str << " iterations: " << count << std::endl;
}

//template
template<typename T>
void templateTest(T t1, T t2) {
	T sum = t1 + t2;
	T diff = t1 - t2;
	T div = t1 / t2;
	std::cout << "template test| SUM: " << sum << std::endl;
	std::cout << "template test| DIFFERNCE: " << diff << std::endl;
	std::cout << "template test| DIV: " << div << std::endl;
}

//Sorting algorithms Quicksort, mergeSort, Insertion Sort, Selection Sort, Bubble Sort

void BubbleSort(int *arr) {
	int temp = 0;
	for (int i = 0; i < 100; i++) {
		for (int z = i + 1; z < 100; z++) {
			if (arr[z] < arr[i]) {
				temp = arr[i];
				arr[i] = arr[z];
				arr[z] = temp;
				count++;
			}
		}
	}
}

void SelectionSort(int *arr) {
	int min = 0;
	int temp = 0;
	for (int i = 0; i < 100; i++) {
		min = i;
		for (int i2 = i + 1; i2 < 100; i2++) {
			if (arr[i2] < arr[min]) {
				min = i2;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
		count++;
	}
}

void InsertionSort(int *arr) {
	int temp = 0;
	int index = 0;
	for (int i = 0; i < 100; i++) {
		index = i;
		while ((arr[index] > arr[index - 1]) && index >= 0) {
			temp = arr[index];
			arr[index] = arr[index - 1];
			arr[index - 1] = temp;
			index--;
			count++;
		}
	}

}

void merge(int*, int*, int, int, int);

void mergesort(int *a, int*b, int start, int end) {
	int halfpoint;
	if (start < end) {
		halfpoint = (start + end) / 2;
		mergesort(a, b, start, halfpoint);
		mergesort(a, b, halfpoint + 1, end);
		merge(a, b, start, halfpoint, end);
	}
}

//merge
void merge(int *a, int *b, int start, int halfpoint, int end) {
	//iterators and index
	int h, i, j, k;
	h = start;
	i = start;
	j = halfpoint + 1;

	while ((h <= halfpoint) && (j <= end)) {
		if (a[h] <= a[j]) {
			b[i] = a[h];
			h++;
		} else {
			b[i] = a[j];
			j++;
		}
		i++;
	}
	if (h > halfpoint) {
		for (k = j; k <= end; k++) {
			b[i] = a[k];
			i++;
		}
	} else {
		for (k = h; k <= halfpoint; k++) {
			b[i] = a[k];
			i++;
		}
	}
	// Write the final sorted array to our original one
	for (k = start; k <= end; k++) {
		a[k] = b[k];
	}
}
//Also known as Partition sort
void QuickSort(int *arr, int left, int right) {
	int i = left;
	int j = right;

	int temp;
	int pivot = arr[(left + right) / 2];

//partition
	while (i <= j) {
		while (arr[i] < pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
		count++;
	}
	if (left < j) {
		QuickSort(arr, left, j);
	}
	if (right > i) {
		QuickSort(arr, i, right);
	}
}

int main() {

	init();
	mergesort(arr, arrHolder, 0, 100);
	printArr("Merge Sort");

	//templateTest(.33, .7);

	//	init();
	//	BubbleSort(arr);
	//	printArr("Bubble Sort");

	//	init();
	//	SelectionSort(arr);
	//	printArr("Selection Sort");

	//	init();
	//	InsertionSort(arr);
	//	printArr("Insertion Sort");

	//	init();
	//	QuickSort(arr, 0, 100);
	//	printArr("Quick Sort");
	////////////////////////////////////////////////
	//print iterations
	init();
	BubbleSort(arr);
	printCount("Bubble Sort");
	init();
	SelectionSort(arr);
	printCount("Selection Sort");
	init();
	InsertionSort(arr);
	printCount("InsertionSort Sort");
	init();
	QuickSort(arr, 0, 100);
	printCount("QuickSort Sort");
	init();
	mergesort(arr, arrHolder, 0, 100);
	printCount("Merge Sort");
//sorting

	return 0;
}

