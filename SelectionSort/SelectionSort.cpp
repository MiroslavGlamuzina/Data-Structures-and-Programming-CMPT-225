#include "iostream"
#include "cstdlib"

using namespace std;
int *arr = new int[100];
int count = 0;
void insertionSortAlgorithm(int *arr) {
	int n = 100;
	int i, j, minIndex, tmp;
	for (i = 0; i < n - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;
		if (minIndex != i) {
			tmp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = tmp;
		}
	}

}

int main() {
	cout << "test" << endl;
	for (int i = 0; i < 100; i++) {
		arr[i] = rand() % 1000;
	}
	insertionSortAlgorithm(arr);

	for (int i = 0; i < 100; i++) {
		cout << "Index: " << i << ": " << arr[i] << endl;
	}
}
