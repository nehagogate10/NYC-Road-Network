#pragma once
#include "Graph.h"
#include <map>
#include <vector>
#include <queue>
#include <iostream>

class Traversal {
    public:
        std::vector<Node> BFS(Graph g);
        std::vector<Edge> findEdges(Node & node, Graph & g, bool directed = false);
};