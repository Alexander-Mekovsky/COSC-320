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
    cout << "Insert a Vertex String: ";
    cin >> vertex;

    set<string> BFS;
    set<string>::iterator iter;
    list<string> vertices;
    list<string> paths;
    BFS = bfs(graphB, vertex);
    int largestPath = 0; 
    for(iter = BFS.begin(); iter != BFS.end(); iter++)
    {
        int temp = minimumPath(graphB, vertex, *iter, paths);
        if(temp > largestPath)
        {
            largestPath = temp;
            vertices = paths;
        }
    }
    cout << "Vertex with largest minimum-path value = " << *(--vertices.end()) << endl;
    cout << "Minimum-path value = " << largestPath << endl;
    cout << "Minimum path = ";
    writeContainer(vertices.begin(), vertices.end(), " ");
    return 0;
}