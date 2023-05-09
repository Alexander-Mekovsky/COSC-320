#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, string> m;
    m.insert(pair<string, string>("Arizona", "Phoenix"));
    m.insert(pair<string, string>("Pennsylvania", "Philadelphia"));
    m.insert(pair<string, string>("New York", "Albany"));
    m.insert(pair<string, string>("Washington", "Seattle"));
    m.insert(pair<string, string>("Texas", "Dallas"));
    string search;
    cout << "Enter a State: ";
    getline(cin, search);
    auto it = m.find(search);
    if(it != m.end())
        cout << m[search] << ", " << search << endl;
    else
        cout << search << " is not in the map." << endl;
    return 0;
}