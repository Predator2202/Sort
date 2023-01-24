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

int partitionIndex(int arr[], int lowerBound, int upperBound) {
	int pivot = arr[lowerBound];
	int numberOfElementsLowerThenPivot = 0;

	for (int i = lowerBound + 1; i <= upperBound; i++) {
		if (arr[i] <= pivot)numberOfElementsLowerThenPivot++;
	}

	int pivotIndex = lowerBound + numberOfElementsLowerThenPivot;
	swap(arr[pivotIndex], arr[lowerBound]);

	int i = lowerBound, j = upperBound;
	while (i < pivotIndex && j > pivotIndex) {
		while (arr[i] <= pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}
	return pivotIndex;
}
void QuickSort(int arr[], int lowerBound, int upperBound) {

	if (lowerBound >= upperBound) return;

	int partition = partitionIndex(arr, lowerBound, upperBound);

	QuickSort(arr, lowerBound, partition - 1);
	QuickSort(arr, partition + 1, upperBound);

	return;
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
		QuickSort(arr, 0, ARRAY_LENGTH - 1);
		tEnd = clock();
		cout << "Quick Sort\nNUmber of elements: " << ARRAY_LENGTH << "\nTime for sort: " << tEnd - tStart << " ms\n";
		PrintArray(arr, ARRAY_LENGTH);
	}
	else {
		int sum = 0;
		for (int i = 0; i < REPEATS; i++) {
			tStart = clock();
			QuickSort(arr, 0, ARRAY_LENGTH - 1);
			tEnd = clock();
			sum += tEnd - tStart;
			RearrangeArray(arr, ARRAY_LENGTH);
		}
		cout << "Quick Sort\nNumber of elements: " << ARRAY_LENGTH << "\nNumber of repetitions: " << REPEATS << "\nTime for sort: " << (float)sum / REPEATS << " ms\n";
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
