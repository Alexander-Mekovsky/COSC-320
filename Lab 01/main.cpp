#include <iostream>
#include "deSelsort.h"

using namespace std;

template <typename T>
T deSelsort(T arr, int size);
const int SIZE = 8;

int main()
{
    int array[] = {13, 5, 2, 25, 47, 17, 8, 21};
    cout << "This is the unsorted array:" << endl;
    for(int i = 0; i < SIZE; i++)
        cout << array[i] << " ";
    cout << endl;
    cout << "This is the sorted array: " << endl;
    deSelsort(array, SIZE);
    return 0;
}