#include <queue>

#include "WeightedGraph.hpp"

WeightedGraph::WeightedGraph()
    : adjacencyList {}, vertexCount {0}{
}

void WeightedGraph::addVertex(string newVertex) {
    if(this->adjacencyList.count(newVertex)) {
        cout << "Vertex: " << newVertex << " already exist!\n";
        return;
    }
    
    this->adjacencyList[newVertex];
    this->vertexCount++;
    
//    cout << "Vertex: " << newVertex << " added successfully!\n";
}

int WeightedGraph::getVertexNumber() const {
    return this->vertexCount;
}

void WeightedGraph::addEdge(string vertexOne, string vertexTwo, int weight) {
    this->adjacencyList[vertexOne].push_back({vertexTwo, weight});
    this->adjacencyList[vertexTwo].push_back({vertexOne, weight});
}

void WeightedGraph::showConnections() {
    string currVertex;
    
    for(auto itr = this->adjacencyList.begin(); itr != this->adjacencyList.end(); itr++) {
        currVertex = itr->first;
        string connectionString = currVertex + " -> ";
        size_t neighborCount = this->adjacencyList[currVertex].size();
        
        for(size_t i = 0; i < neighborCount; i++) {
            if(i == neighborCount - 1) {
                connectionString += this->adjacencyList[currVertex][i].first;
            } else {
                connectionString += this->adjacencyList[currVertex][i].first + ", ";
            }
        }
        cout << connectionString << endl;
    }
}

void WeightedGraph::breadthFirstTraversel(string startVertex) {
    unordered_map<string, bool> visited;
    queue<string> vertexQueue;
    string currVertex;
    string neighbor;
    size_t neighborCount;
    
    vertexQueue.push(startVertex);
    cout << "Breadth First Traversal: " << startVertex << " ";
    visited[startVertex] = true;
    
    while(!vertexQueue.empty()) {
        currVertex = vertexQueue.front();
        vertexQueue.pop();
        neighborCount = this->adjacencyList[currVertex].size();
        
        for(size_t i = 0; i < neighborCount; i++) {
            neighbor = this->adjacencyList[currVertex][i].first;
            
            if(!visited[neighbor]) {
                cout << neighbor << " "; 
                vertexQueue.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}
