#ifndef deSelsort_h_
#define deSelsort_h_

#include <iostream>

using namespace std;

template <typename T>
void swap(T *x, T *y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}

template <typename T>
void deSelsort(T arr[], int size)
{
    T min, max;
    int minIdx, maxIdx;
    for(int i = 0, j = size - 1; i < j; i++, j--)
    {
        min = arr[i], max = arr[i];
        minIdx = i;
        maxIdx = i;
        for(int k = i; k <= j; k++)
        {
            if(arr[k] > max)
            {
                max = arr[k];
                maxIdx = k;
            } 
            if(arr[k] < min)
            {
                min = arr[k];
                minIdx = k;
            }
        }
        swap(arr[minIdx], arr[i]);
        if(arr[minIdx] == max)
            swap(arr[minIdx], arr[j]);
        else
            swap(arr[maxIdx], arr[j]);
    }
}

#endif