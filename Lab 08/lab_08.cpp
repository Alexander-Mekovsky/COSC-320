#include <iostream>
#include <vector>
#include "d_pqueue.h"
#include "preqrec.h"
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
    procReqRec proc1("Process A", rand() % 40);
    procReqRec proc2("Process B", rand() % 40);
    procReqRec proc3("Process C", rand() % 40);
    procReqRec proc4("Process D", rand() % 40);
    procReqRec proc5("Process E", rand() % 40);
    procReqRec proc6("Process F", rand() % 40);
    procReqRec proc7("Process G", rand() % 40);
    procReqRec proc8("Process H", rand() % 40);
    procReqRec proc9("Process I", rand() % 40);
    procReqRec proc10("Process J", rand() % 40);
    miniPQ<procReqRec> mpg;
    mpg.push(proc1);
    mpg.push(proc2);
    mpg.push(proc3);
    mpg.push(proc4);
    mpg.push(proc5);
    mpg.push(proc6);
    mpg.push(proc7);
    mpg.push(proc8);
    mpg.push(proc9);
    mpg.push(proc10);
    while(mpg.empty() == false)
    {
        cout << mpg.top() << endl;
        mpg.pop();
    }
    return 0;
}