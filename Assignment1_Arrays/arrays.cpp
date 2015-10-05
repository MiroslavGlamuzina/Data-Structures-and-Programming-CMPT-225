#include <iostream>
using namespace std;

double sumArray(double arr[], int arrSize);

int main() {
	int size = 0;
	cout << "How many numbers do you want to sum? ";
	cin >> size;
	double* numbers = new (nothrow) double[size];
	for (int i = 0; i < size; i++) {
		cout << "Please Enter next value" << endl;
		cin >> numbers[i];
	}

	cout << endl << "The sum of the array is " << sumArray(numbers, size)
			<< endl;
	delete[] numbers;
	return 1;
}

double sumArray(double arr[], int arrSize) {
	double temp = 0;
	for (int i = 0; i < arrSize; i++) {
		temp += arr[i];
	}
	return temp;
}
