#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED

#include <vector>
#include <iostream>
using namespace std;
template <typename T>
int mergeArr(T* arr, const T* arr1, int n, const T* arr2, int m);

int global = 0;

template <typename T>
int mergeSort(T* arr, unsigned n) // to do it with global variable
{
    int numOperations = 0;
   if(n <= 2)
   {
       int ctr = 0;
       if(n == 2)
       {
            if(arr[0] > arr[1])
            {
               // cout << arr[0] << " " << arr[1] << endl;
                T temp = arr[1];
                arr[1] = arr[0];
                arr[0] = temp;
                //++numOperations;
                ++ctr;
                //++global;
            }
       }

       return ctr;
   }

  // numOperations += mergeSort(arr, n/2, numOperations);
  // numOperations += mergeSort(arr + n/2, (n+1)/2, numOperations);

   numOperations += mergeSort(arr, n/2); // numOperations);
   numOperations += mergeSort(arr + n/2, (n+1)/2);// numOperations);
   numOperations += mergeArr(arr, arr, n/2, arr + n/2, (n+1)/2);
    //int p;
    //global += p;
   // numOperations += p;
    //cout << global << "<- global"<<endl;
   return numOperations;
}

template <typename T>
int mergeArr(T* arr, const T* arr1, int n, const T* arr2, int m)
{
    std:: vector<int> v;
    int ctr = 0;

    int i = 0, k = 0, j = 0;
    while( i < n || j < m )
    {
        if( i < n && j < m)
        {
            while( i < n && j < m)
            {
                if(arr1[i] < arr2[j])
                {
                    v.push_back(arr1[i]);
                    ++i;
                }else
                {
                    v.push_back(arr2[j]);
                    ++j;
                }
                ++ctr;
            }
        }else if(i < n)
        {
            while( i < n )
            {
                v.push_back(arr1[i]);
                ++i;
            }
        }else if( j < m )
        {
            while( j < m )
            {
                v.push_back(arr2[j]);
                ++j;
            }
        }
    }
    for(int i=0; i<v.size(); ++i)
    {
        arr[i] = v[i];
    }

    return ctr;
}


#endif // MERGESORT_H_INCLUDED
