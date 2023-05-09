#include <iostream>
#include "binSearch.h"
#include "deSelsort.h"

using namespace std;

const int ARRSIZE = 10000;
const int RANDOMLIMIT = 99999;
const int RANDOMVALUES = 10000;

int main()
{
    int sumSucCom = 0;
    int sumFailCom = 0;
    int runs = 0;
    bool result;
    int array[ARRSIZE], successTotal = 0;
    for(int i = 0; i < ARRSIZE; i++)
        array[i] = rand() % RANDOMLIMIT;
    deSelsort(array, ARRSIZE);
    for(int i = 0; i < RANDOMVALUES; i++)
    {
        result = false;
        int searchValue = rand() % RANDOMLIMIT;
        runs = binSearch(array, searchValue, result, ARRSIZE);
        if(result == true)
        {
            successTotal++;
            sumSucCom += runs;
        }
        else
            sumFailCom += runs;
    }
    int worseCaseUnsuccessful = (sumFailCom / (RANDOMVALUES - successTotal));
    int worstCaseSuccessful = (sumSucCom / successTotal);
    cout << worseCaseUnsuccessful << " for worst case unsuccessful finds." << endl;
    cout << worstCaseSuccessful << " for the worst case successful finds." << endl;
    return 0;
}


