#include <iostream>
#include <cstdlib>

#ifndef binSearch_h_
#define binSearch_h_

using namespace std;

int binSearch(int arr[], int x, bool& success, int size)
{
    int l = 0;
    int h = size - 1;
    int runs = 0;
    int m = (l + h) / 2;
    while((arr[m] != x && l <= h))
    {
        runs++;
        if(arr[m] > x)
        {
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
        m = (l + h) / 2;
    }
    if(arr[m] == x)
        success = true;
    else
        success = false;
    return runs;
}

#endif