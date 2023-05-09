#include <iostream>
#include "max.h"

using namespace std;

int main()
{
    int max = 0;
    tnode<int> *t = buildIntTreeLab02();
    countMax(t, max);
    cout << "-----------------------------------------------------" << endl;
    cout << "The max value in the binary tree is " << max << endl;
    cout << "-----------------------------------------------------" << endl;
    return 0;
}