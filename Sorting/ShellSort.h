#ifndef SHELLSORT_H_INCLUDED
#define SHELLSORT_H_INCLUDED

#include <iostream>

template <typename T>
int ShellSort(T* arr, unsigned n)
{
    unsigned gaps[] = {21, 13, 8, 5, 3, 2, 1};
    unsigned gapsCount = 7, numOperations = 0;

    for(int k = 0; k < gapsCount; ++k)
    {
        T gap = gaps[k];
        for(int i = 1; i < n; ++i)
        {
            T elem = arr[i];
            for(int j = i - gap; j >= 0; j -= gap)
            {
                if(elem < arr[j])
                {
                    T temp = arr[j];
                    arr[j] = arr[j+gap];
                    arr[j+gap] = temp;

                    ++numOperations;
                }
            }
        }
    }

    return numOperations;
}

#endif // SHELLSORT_H_INCLUDED
