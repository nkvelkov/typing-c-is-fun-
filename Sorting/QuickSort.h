#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED
#include <ctime>
#include <cstdlib>

template <typename T>
int quickSort(T* arr, int n)
{
    int numOperations = 0;
    if(n <= 2)
    {
        int ctr = 0;
        if(n == 2)
        {
            if(arr[0] > arr[1])
            {
                T temp = arr[0];
                arr[0] = arr[1];
                arr[1] = temp;
                ++ctr;
            }
        }
        return ctr;
    }

    int pivotIndex = rand() % n;
    T pivot = arr[pivotIndex];
    cout << pivotIndex << endl;

    if(pivotIndex != n-1)
    {
        T temp = arr[pivotIndex];
        arr[pivotIndex] = arr[n-1];
        arr[n-1] = temp;
        ++numOperations;
    }

    int left = 0, right = n-2;

    while( left < right )
    {

        for(int i=left; i<=n-2; ++i)
        {
            if(pivot <= arr[i])
            {
                left = i;
                break;
            }else
            {
                if(i == n-2)
                {
                    left = i;
                }
            }
        }
        for(int i=right; i>=0; --i)
        {
            if(pivot > arr[i])
            {
                right = i;
                break;
            }else
            {
                if(i == 0)
                {
                    right = i;
                }
            }
        }

        if(left < right)
        {
            T temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            ++numOperations;
        }

    }

    if(left != n-1) // why ? left is never reaches to n-1
    {
        T temp = arr[left];
        arr[left] = arr[n-1];
        arr[n-1] = temp;
        ++numOperations;
    }


    numOperations += quickSort(arr, left);
    numOperations += quickSort(arr + left + 1, n - 1- left);

    return numOperations;
}

void QuickSort(int * arr, int n)
{
    cout << "QS";
    if(n <= 2)
    {
        if(n == 2)
        {
            if(arr[0] > arr[1])
            {
                swap(arr[0], arr[1]);
            }
        }
        return;
    }
    int left = 0, right = n - 2;
    int pivotIndex = rand() % n;
    cout << pivotIndex << endl;
    int pivot = arr[pivotIndex];

    if(pivotIndex != n-1)
        swap(arr[n-1], arr[pivotIndex]);

    while (left < right)
    {
        for(int i=left; i <= n-2; ++i)
        {
           if(arr[i] >= pivot)
           {
               left = i;
               break;
           }else
           {
               if(i == n-2)
               {
                  left = i;
               }
           }
        }

        for(int i=right; i >= 0; --i)
        {
            if(arr[i] < pivot)
            {
                right = i;
                break;
            }else
            {
                if(i == 0)
                {
                  right = i;
                }
            }
        }

        if(left < right)
        {
            swap(arr[left], arr[right]);
        }
    }

    if(left != n-1) // why ? left is never reaches to n-1
        swap(arr[left], arr[n-1]);

    quickSort(arr, left);
    quickSort(arr+left, n-left);

}

void quickSortA(int* arr, int size)
{
    if (size <= 1)
        return;

    if (size == 2)
    {
        if (arr[0] > arr[1])
        {
            swap(arr[0], arr[1]);
        }
        return;
    }

    int pivotIndex = rand() % size;
    int pivot = arr[pivotIndex];

    if (pivotIndex != size - 1)
	{
        swap(arr[pivotIndex], arr[size - 1]);
	}

    int left = 0;
    int right = size - 2;

    while (left < right)
    {
        for (int i = left; i <= size - 2; i++)
        {
            if (arr[i] >= pivot)
            {
                left = i;
                break;
            }
            else
            {
                if (i == size - 2)
                {
                    left = i;
                }
            }
        }

        for (int j = right; j >= 0; j--)
        {
            if (arr[j] < pivot)
            {
                right = j;
                break;
            }
            else
            {
                if (j == 0)
                {
                    right = j;
                }
            }
        }

        if (left < right)
        {
            swap(arr[left], arr[right]);
        }
    }

    if (left != size - 1)
    {
        swap(arr[left], arr[size - 1]);
    }

    quickSort(arr, left);
    quickSort(arr + left + 1, size - left - 1);
}

#endif // QUICKSORT_H_INCLUDED
