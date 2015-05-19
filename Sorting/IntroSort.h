#ifndef INTROSORT_H_INCLUDED
#define INTROSORT_H_INCLUDED
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
template <typename T>
int heapSort(T* arr, int n);
template <typename T>
int printArr(T* arr, int n)
{
    for(int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }cout << endl;
}

template <typename T>
int introSort(T* arr, int n, int depth)
{
    int numSteps = 0;
    if(depth == 0)
    {
        int heapSteps = 0;
        heapSteps = heapSort(arr, n);
        return heapSteps;
    }
    int pivotIndex;
    pivotIndex = rand() % n;
    T pivot = arr[pivotIndex];

    if(pivotIndex != n-1)
    {
        T temp = arr[n-1];
        arr[n-1] = arr[pivotIndex];
        arr[pivotIndex]= temp;
    }

    int left = 0, right = n-2; // ne n-1

    while(left < right)
    {
        for(int i = left; i <= n-2; ++i)
        {
            if(arr[i] > pivot)
            {
                left = i;
                break;
            }else{
                if(i == n-2)
                {
                    left = n-2;
                }
            }
        }
        for(int i = right; i >= 0; --i)
        {
            if(arr[i] <= pivot)
            {
                right = i;
                break;
            }else
            {
                if(i == 0)
                {
                    right = 0;
                }
            }
        }
        if(left < right)
        {
            ++numSteps;
            T temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            //swap(arr[left], arr[right]);
        }
    }

    if(pivot < arr[left])
    {
        ++numSteps;
        T temp = arr[left];
        arr[left] = arr[n-1];
        arr[n-1] = temp;
    }

    int s = introSort(arr, left+1, depth-1);
    int ss = introSort(arr+left+1, n-1-left, depth-1);
    numSteps += s + ss;
    return numSteps;
}

template <typename T>
int heapify(T* arr, int i, int n);
template <typename T>
int arrange(T* arr, int n);
template <typename T>
int reverseArr(T* arr, int n);

template <typename T>
int heapSort(T* arr, int n)
{
    int ctr = 0;
    for(int i = (n-2)/2; i >= 0; --i)
    {
        ctr += heapify(arr, i, n);
    }
    ctr += arrange(arr, n);
    return ctr;
}

template <typename T>
int heapify(T* arr, int i, int n) // realno sink
{
    int ctr = 0;
    T root = arr[i];
    int j = i*2 + 1;

    while(j < n) //
    {
        if(j+1 < n && arr[j] > arr[j+1])
            ++j;

        if(arr[j] > root){
            break;
        }else
        {
            arr[(j-1)/2] = arr[j];
            ++ctr;
            j = j*2 + 1;
        }
    }
    arr[(j-1)/2] = root;
    ++ctr;

    return ctr;
}

template <typename T>
int arrange(T* arr, int n)
{
    int ctr = 0;
    int p = n;
    for(int i = n-1; i >= 0; --i)
    {
        T temp = arr[n-1];
        arr[n-1] = arr[0];
        arr[0] = temp;

        ctr += heapify(arr, 0, n-1);
        --n;
    }
    // ili bez reverseArr ako sortirame masiva v nizhodqsht red
    ctr += reverseArr(arr, p);
    return ctr;
}

template <typename T>
int reverseArr(T* arr, int n)
{
    int i;
    for(i = 0 ; i < n/2; ++i)
    {
        swap(arr[i], arr[n-i-1]);
    }
    return i;
}

#endif // INTROSORT_H_INCLUDED
