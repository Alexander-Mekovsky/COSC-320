#include "d_util.h"
#include "d_graph.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    graph<string> graphA;
    ifstream graphData;
    string vertexName;
    string edgeEnd;
    int edgeWeight;
    int n = 0;
    graphData.open("graphA.dat");

    graphData >> n;

    for(int i = 0; i < n; i++)
    {
        graphData >> vertexName;
        graphA.insertVertex(vertexName);
    }

    graphData >> n;

    for(int i = 0; i < n; i++)
    {
        graphData >> vertexName;
        graphData >> edgeEnd;
        graphData >> edgeWeight;
        graphA.insertEdge(vertexName, edgeEnd, edgeWeight);
    }

    graphA.insertEdge("vertex_F", "vertex_D", 1);
    graphA.eraseVertex("vertex_B");
    graphA.eraseEdge("vertex_A", "vertex_D");
    string G;
    cout << "Insert a Vertex String: " << endl;
    cin >> G;
    graphA.insertVertex(G);
    graphA.insertEdge(G, "vertex_C", 1);
    graphA.insertEdge(G, "vertex_F", 1);
    graphA.insertEdge("vertex_D", G, 1);
    
    cout << graphA << endl;

    return 0;
}