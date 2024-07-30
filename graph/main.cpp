#include <iostream>


#include "WeightedGraph.hpp"

using namespace std;



int main()
{
    WeightedGraph graph;
    
    graph.addVertex("A");
    graph.addVertex("B");
    graph.addVertex("C");
    graph.addVertex("D");
    graph.addVertex("E");
    graph.addVertex("F");
    
    graph.addEdge("A", "B", 4);
    graph.addEdge("A", "C", 2);
    graph.addEdge("B", "D", 3);
    graph.addEdge("B", "X", 10);
    graph.addEdge("B", "E", 3);
    graph.addEdge("C", "D", 2);
    graph.addEdge("C", "Y", 20);
    graph.addEdge("C", "F", 4);
    graph.addEdge("D", "F", 1);
    graph.addEdge("E", "F", 1);
    graph.addEdge("E", "Z", 30);
    
//    graph.breadthFirstTraversal("D");

    graph.depthFirstTraversalRec("X");
    

	cout << endl;
	return 0;
}
