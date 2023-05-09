#include "d_util.h"
#include "d_graph.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    graph<string> graphB;
    ifstream graphData;
    string vertexName;
    string edgeEnd;
    int edgeWeight;
    int n = 0;
    graphData.open("graphB.dat");

    graphData >> n;

    for(int i = 0; i < n; i++)
    {
        graphData >> vertexName;
        graphB.insertVertex(vertexName);
    }

    graphData >> n;

    for(int i = 0; i < n; i++)
    {
        graphData >> vertexName;
        graphData >> edgeEnd;
        graphData >> edgeWeight;
        graphB.insertEdge(vertexName, edgeEnd, edgeWeight);
    }

    string vertex;
    cout << "Insert a Vertex String: " << endl;
    cin >> vertex;

    set<string> BFS;
    list<string> DFS;
    BFS = bfs(graphB, vertex);
    dfs(graphB, DFS);
    cout << "Graph using BFS: " << endl;
    writeContainer(BFS.begin(), BFS.end(), " ");
    cout << endl;
    cout << "Graph using DFS: " << endl;
    writeContainer(DFS.begin(), DFS.end(), " ");
    cout << endl;
    return 0;
}