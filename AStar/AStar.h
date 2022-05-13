#pragma once
#include "../Graph.h"
#include <vector>
#include <tuple>
using namespace std;

//Class that holds components necessary for AStar traversal
class AStar {

    public:
    //constructor for AStar algorithm
    AStar(Graph & graph);

    //returns set of edges that connects to the node with currentId
    std::vector<Edge> findConnectingEdges(long currentId);

    //returns the best path from start node to end node
    //return in std::vector<int> format where the int represents the id of the node next in path
    std::vector<int> findBestPath(Node & start, Node & end);
    
    private:
    //graph being traversed. 
    Graph g;

    //finds the distance from the current node to the destination node
    //calculates distance from ||currentNode - destinationNode|| using its x and y coordinates
    //used as heuristic function
    double FindDistance(long currentId, long destination);
};