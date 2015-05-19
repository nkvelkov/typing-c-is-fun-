#ifndef RADIXSORT_H_INCLUDED
#define RADIXSORT_H_INCLUDED

#include <vector>
using namespace std;

template <typename T>
T getBiggest(T* arr, int n);

template <typename T>
int getNumDigits(T m);

template <typename T>
int radixSort(T* arr, int n)
{
    T maxNum = getBiggest(arr, n);
    int numDigits = getNumDigits(maxNum);
    int d = 1;
    int numOperations = 0, i = 0;
    for(; i<numDigits; ++i, d *= 10)
    {
        vector<T> buckets[10];

        for(int j=0; j<n; ++j)
        {
            T x = (arr[j] /d) % 10;
            buckets[x].push_back(arr[j]);
            ++numOperations;
        }
        int y = 0;
        for(int j=0; j<10; ++j)
        {
            for(int k=0; k<buckets[j].size(); ++k)
            {
                arr[y++] = buckets[j][k];
            }
        }
    }
    return numOperations;
}

template <typename T>
T getBiggest(T* arr, int n)
{
    T m = arr[0];
    for(int i=1; i<n; ++i)
    {
        if(arr[i] > m)
        {
            m = arr[i];
        }
    }
    return m;
}

template <typename T>
int getNumDigits(T m)
{
    int p = 0;

    while (m != 0)
    {
        ++p;
        m /= 10;
    }
    return p;
}
#endif // RADIXSORT_H_INCLUDED
