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

void merge(int arr[], int const left, int const middle, int const right) {

	auto const subArr1 = middle - left + 1;
	auto const subArr2 = right - middle;

	auto* LArr = new int[subArr1]; //left array
	auto* RArr = new int[subArr2]; //right array

	for (auto i = 0; i < subArr1; i++)
		LArr[i] = arr[left + i];
	for (auto j = 0; j < subArr2; j++)
		RArr[j] = arr[middle + 1 + j];

	auto iOfSubArr1 = 0; //index of sub array one
	auto iOfSubArr2 = 0; //index of sub array two
	int iOfMergedArr = left; //index of merged array

	while (iOfSubArr1 < subArr1 && iOfSubArr2 < subArr2)
	{
		if (LArr[iOfSubArr1] <= RArr[iOfSubArr2])
		{
			arr[iOfMergedArr] = LArr[iOfSubArr1];
			iOfSubArr1++;
		}
		else
		{
			arr[iOfMergedArr] = RArr[iOfSubArr2];
			iOfSubArr2++;
		}
		iOfMergedArr++;
	}

	while (iOfSubArr1 < subArr1)
	{
		arr[iOfMergedArr] = LArr[iOfSubArr1];
		iOfSubArr1++;
		iOfMergedArr++;
	}

	while (iOfSubArr2 < subArr2)
	{
		arr[iOfMergedArr] = RArr[iOfSubArr2];
		iOfSubArr2++;
		iOfMergedArr++;
	}

	delete[] LArr; // equivalent to free(LArr), but when using 'new' instead of malloc/calloc
	delete[] RArr;
}
void MergeSort(int arr[], int const begin, int const end) {
	if (begin >= end)
		return;

	auto mid = begin + (end - begin) / 2;
	MergeSort(arr, begin, mid);
	MergeSort(arr, mid + 1, end);
	merge(arr, begin, mid, end);
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
		MergeSort(arr, 0, ARRAY_LENGTH - 1);
		tEnd = clock();
		cout << "Merge Sort\nNUmber of elements: " << ARRAY_LENGTH << "\nTime for sort: " << tEnd - tStart << " ms\n";
		PrintArray(arr, ARRAY_LENGTH);
	}
	else {
		int sum = 0;
		for (int i = 0; i < REPEATS; i++) {
			tStart = clock();
			MergeSort(arr, 0, ARRAY_LENGTH - 1);
			tEnd = clock();
			sum += tEnd - tStart;
			RearrangeArray(arr, ARRAY_LENGTH);
		}
		cout << "Merge Sort\nNumber of elements: " << ARRAY_LENGTH << "\nNumber of repetitions: " << REPEATS << "\nTime for sort: " << (float)sum / REPEATS << " ms\n";
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
