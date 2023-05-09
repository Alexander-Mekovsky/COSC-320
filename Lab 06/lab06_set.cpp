#include <iostream>
#include <set>
#include "d_state.h"
#include <string>

using namespace std;

int main()
{
    set<stateCity> s;
    stateCity state0("Arizona", "Phoenix");
    stateCity state1("Pennsylvania", "Philadelphia");
    stateCity state2("New York", "Albany");
    stateCity state3("Washington", "Seattle");
    stateCity state4("Texas", "Dallas");
    s.insert(state0);
    s.insert(state1);
    s.insert(state2);
    s.insert(state3);
    s.insert(state4);
    string search;
    cout << "Enter a State: ";
    getline(cin, search);
    auto it = s.find(search);
    if(it != s.end())
        cout << *it << endl;
    else
        cout << search << " is not in the set" << endl;
    return 0;
}