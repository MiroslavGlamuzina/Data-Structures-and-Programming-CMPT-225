#include "iostream"
#include "cstdlib"

using namespace std;
int *arr = new int[100];
int count = 0;
void insertionSortAlgorithm(int *arr) {
	int temp = 0;
	int* sorted = new int[100];
	sorted[0] = arr[0];
	for (int i = 0; i < 100; i++) {
		int z =i;
		while (arr[z] < arr[z - 1]) {
			temp = arr[z - 1];
			arr[z - 1] = arr[z];
			arr[z] = temp;
			z--;
		}
	}

}

int main() {
	cout << "test" << endl;
	for (int i = 0; i < 100; i++) {
		arr[i] = rand() % 1000;
	}
	insertionSortAlgorithm(arr);

	for(int i =0; i < 100; i ++)
	{
		cout << "Index: " << i << ": " << arr[i] <<endl;
	}
}
