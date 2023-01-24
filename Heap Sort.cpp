#include <iostream>
using namespace std;
#define ARRAY_LENGTH 100000
#define RANGE 100 // elements will range from 0 - N
#define FORMAT 10 // N elements will be in one row when printing -> cant be 0
#define SPACES 3 // N spaces between elements when printing
#define TEST 0 // 0 -> tests will repeat, 1 -> only one test in conducted
#define REPEATS 100 // in loop test, N times it will be executed
#define PRINT_SIZE 100 // if ARRAY_LENGTH is greater then N array wont be printed

void PrintArray(int[], int);
void FillArray(int[], int);
void RearrangeArray(int[], int);

void heapify(int arr[], int numberOfElements, int i) {
	//N is size of heap, i is subtree rooted with node i (index of arr[])
	int largest = i;

	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < numberOfElements && arr[left] > arr[largest])
		largest = left;
	if (right < numberOfElements && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, numberOfElements, largest);
	}
}

void HeapSort(int arr[], int numberOfElements) {
	//N is size of heap

	for (int i = numberOfElements / 2 - 1; i >= 0; i--) {
		heapify(arr, numberOfElements, i);
	}

	for (int i = numberOfElements - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int main()
{
	srand(time(NULL));
	int* arr = (int*)malloc(sizeof(int) * ARRAY_LENGTH);
	FillArray(arr, ARRAY_LENGTH);
	time_t tStart, tEnd;
	if (TEST) {
		PrintArray(arr, ARRAY_LENGTH);
		tStart = clock();
		HeapSort(arr, ARRAY_LENGTH);
		tEnd = clock();
		cout << "Heap Sort\nNUmber of elements: " << ARRAY_LENGTH << "\nTime for sort: " << tEnd - tStart << " ms\n";
		PrintArray(arr, ARRAY_LENGTH);
	}
	else {
		int sum = 0;
		for (int i = 0; i < REPEATS; i++) {
			tStart = clock();
			HeapSort(arr, ARRAY_LENGTH);
			tEnd = clock();
			sum += tEnd - tStart;
			RearrangeArray(arr, ARRAY_LENGTH);
		}
		cout << "Heap Sort\nNumber of elements: " << ARRAY_LENGTH << "\nNumber of repetitions: " << REPEATS << "\nTime for sort: " << (float)sum / REPEATS << " ms\n";
	}
}

void PrintArray(int arr[], int size) {
	if (ARRAY_LENGTH <= PRINT_SIZE && FORMAT != 0) {
		for (int i = 1; i < size; i++) {
			cout << arr[i - 1];
			for (int j = 0; j < SPACES; j++)cout << " ";
			if (i % FORMAT == 0)cout << "\n";
		}
		cout << "\n\n\n";
	}
}
void FillArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (RANGE + 1);
	}
}
void RearrangeArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		int temp = rand() % size;
		swap(arr[i], arr[temp]);
	}
}