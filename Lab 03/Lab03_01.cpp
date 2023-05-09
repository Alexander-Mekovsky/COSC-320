#include <iostream>
#include "countOneChild.h"


using namespace std;

int main()
{
    int count = 0;
    tnode<char> *t = buildCharTreeLab01();
    countOneChild(t, count);
    cout << "-----------------------------------------------------" << endl;
    cout << "There are " << count << " one child nodes in the binary tree." << endl;
    cout << "-----------------------------------------------------" << endl;
    return 0;
}