#include "d_except.h"
#include "d_random.h"
#include "d_stree.h"
#include "int.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    stree<int> integerTree;
    integer num0(0), num1(1), num2(2), num3(3), num4(4), num5(5), num6(6);
    srand(time(NULL));
    for(int i = 0; i < 10000; i++)
    {
        int value = rand() % 7;
        if(value == num0.getInt())
            num0.incCount();
        else
            integerTree.insert(value);
           
        if(value == num1.getInt())
            num1.incCount();
        else
            integerTree.insert(value);  

        if(value == num2.getInt())
            num2.incCount();
        else
            integerTree.insert(value);
            
        if(value == num3.getInt())
            num3.incCount();
        else
            integerTree.insert(value);
           
        if(value == num4.getInt())
            num4.incCount();
        else
            integerTree.insert(value);
           
        if(value == num5.getInt())
            num5.incCount();
        else
            integerTree.insert(value);
           
        if(value == num6.getInt())
            num6.incCount();
        else
            integerTree.insert(value);
        }
    cout << "Values in the tree:" << endl;
    cout << num0 << endl;
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    cout << num4 << endl;
    cout << num5 << endl;
    cout << num6 << endl;
    cout << "The tree is" << endl;
    integerTree.displayTree(4);

    return 0;
}