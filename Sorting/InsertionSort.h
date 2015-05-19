#ifndef INSERTIONSORT_H_INCLUDED
#define INSERTIONSORT_H_INCLUDED

template <typename T>
int insertionSort(T* arr, int n)
{
    int numOperations = 0;

    for(int i=1; i<n; ++i)
    {
        T elem = arr[i];
        for(int j=i-1; j>=0; --j)
        {
            if( elem < arr[j])
            {
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                ++numOperations;
            }
        }
    }
    return numOperations;
}


#endif // INSERTIONSORT_H_INCLUDED
