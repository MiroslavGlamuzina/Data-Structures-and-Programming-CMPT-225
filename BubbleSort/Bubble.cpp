#include "iostream"
#include "cstdlib"

using namespace std;
int *arr = new int[100];
int count=0;
void bubbleSortAlgorithm(int *arr) {
	bool complete = true;
	int temp = 0;
	for (int i = 0; i < 100; i++) {
		if (arr[i] > arr[i + 1]) {
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			complete = false;
		}
	}
	if (complete) {
		for (int i = 0; i < 100; i++) {
			cout << i << ": " << arr[i] << endl;
		}
		cout << "Total recursive calls: " << count << endl;
	}
	else{
		count++;
		bubbleSortAlgorithm(arr);
	}

}

int main() {
	cout << "test" << endl;
	for (int i = 0; i < 100; i++) {
		arr[i] = rand() % 1000;
	}
	bubbleSortAlgorithm(arr);
}
