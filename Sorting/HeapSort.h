#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED

#include "Heap.h"


template <typename T>
int HeapSort(T* arr, int n)
{
    Heap<T> heap;

    int numOperations = 0;
    for(int i=0; i<n; ++i)
    {
       numOperations += heap.insert(arr[i]);
    }
    cout << "ok" << endl;
    int i = 0;
    while(!heap.isEmpty())
    {
        T x; int asdf;
        numOperations += heap.pop(x, asdf);
        arr[i++] = x;
    }
    return numOperations;
}

#endif // HEAPSORT_H_INCLUDED
