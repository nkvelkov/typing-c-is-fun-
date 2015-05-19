#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "InsertionSort.h"
#include "RadixSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "IntroSort.h"

using namespace std;

void printArr(const int* arr, int n)
{
    for(int i=0; i<n; ++i)
    {
        cout << arr[i] << " ";
    }cout << endl;
}

template <typename T>
void shuffle(T* arr, unsigned  n)
{
    for(int i=0; i<n; ++i)
    {
        int j = rand() % n;
        swap(arr[j], arr[i]);
    }
}

template <typename T>
int compareSorts(T* arr, unsigned n)
{
    unsigned op, m = 0; unsigned mi = 0;
    cout << "quicksort -> "<< (mi = op = quickSort(arr, n)) << endl;
    cout << "HeapSort -> "<< (op = HeapSort(arr, n)) << endl;
    mi = mi < op ? mi : op;
    cout << "radixSort -> "<< (op = radixSort(arr, n)) << endl;
    mi = mi < op ? mi : op;
    cout << "mergeSort -> "<< (op = mergeSort(arr, n)) << endl;
    mi = mi < op ? mi : op;
    shuffle(arr, n);
    cout << "ShellSort -> "<< (op = ShellSort(arr, n)) << endl;
    mi = mi < op ? mi : op;
    shuffle(arr, n);
    cout << "insertionSort -> "<< (op = insertionSort(arr, n)) << endl;
    mi = mi < op ? mi : op;

    return mi;
}

bool isSorted(int* arr, int n);

int main()
{
    int arr[12] = {1, 32, 12, 43, 1, 213};
//    int arr[100] = {1, 12, 19, 23, 12, 17, 111, 90, 71, 3};
    int n = 6, op;
    printArr(arr, n);
    //int* arr3 = arr + 1;
   // cout << compareSorts(arr, n) << endl;
    unsigned m = 0;
    // op = 3;
    //QuickSort(arr, n);
   // shuffle(arr, n);
    //printArr(arr, n);
     quickSortA(arr, n);
     //op = HeapSort(arr, n);
    //op = mergeSort(arr, n, m);
   //  op = radixSort(arr, n);
    // op = ShellSort(arr, n);
//   op = insertionSort(arr, n);
    //cout << op << endl;
    printArr(arr, n);

    n = 16;
    int arr2[] = {1, 2, 123, 321, 2, 12, 32, 1, 43, 1, 2, 34, 765, 36, 876, 16};

    srand(time(NULL));
    for(int i = 0; i < n; ++i)
    {
        arr2[i] = rand() % 100;
    }

    printArr(arr2, n);
    introSort(arr2, n, log(n)/log(2) - 2);

    //printArr(arr, n);
    //heapSort(arr, );
    printArr(arr2, n);
    return 0;
}

bool isSorted(int* arr, int n)
{
    //cout << "isSorted " << endl;
    for(int i = 0; i < n-1; ++i)
    {
        if(arr[i] > arr[i+1])
        {
            return false;
        }
    }
    return true;
}
