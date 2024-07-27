#ifndef _WEIGHTED_GRAPH_H_
#define _WEIGHTED_GRAPH_H_

#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <string>

using namespace std;

class WeightedGraph
{
private:
    unordered_map<string, vector<pair<string, int>>> adjacencyList;
    int vertexCount;
public:
    WeightedGraph();
    
    void addVertex(string);
    int getVertexNumber() const;
    void addEdge(string, string, int);
    void showConnections();
    void breadthFirstTraversel(string);
};

#endif // _WEIGHTED_GRAPH_H_
