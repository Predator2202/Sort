#include <iostream>
using namespace std;
#define ARRAY_LENGTH 100
#define RANGE 100 // elements will range from 0 - N
#define FORMAT 10 // N elements will be in one row when printing -> cant be 0
#define SPACES 3 // N spaces between elements when printing
#define TEST 1 // 0 -> tests will repeat, 1 -> only one test in conducted
#define REPEATS 100 // in loop test, N times it will be executed
#define PRINT_SIZE 100 // if ARRAY_LENGTH is greater then N array wont be printed

void PrintArray(int[], int);
void FillArray(int[], int);
void RearrangeArray(int[], int);

void BubbleSort(int arr[], int numberOfElements) {
	for (int i = 0; i < numberOfElements - 1; i++) {
		for (int j = 0; j < numberOfElements - i - 1; j++) {
			//descending
			//if (arr[j] < arr[j + 1]) swap(arr[j], arr[j + 1]);

			//ascending
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
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
		BubbleSort(arr, ARRAY_LENGTH);
		tEnd = clock();
		cout << "Bubble Sort\nNUmber of elements: " << ARRAY_LENGTH << "\nTime for sort: " << tEnd - tStart << " ms\n";
		PrintArray(arr, ARRAY_LENGTH);
	}
	else {
		int sum = 0;
		for (int i = 0; i < REPEATS; i++) {
			tStart = clock();
			BubbleSort(arr, ARRAY_LENGTH);
			tEnd = clock();
			sum += tEnd - tStart;
			RearrangeArray(arr, ARRAY_LENGTH);
		}
		cout << "Bubble Sort\nNumber of elements: " << ARRAY_LENGTH << "\nNumber of repetitions: " << REPEATS << "\nTime for sort: " << (float)sum / REPEATS << " ms\n";
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
