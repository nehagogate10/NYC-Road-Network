#pragma once
#include <map>
#include <string>
#include <utility>
#include <iostream>
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

class DisjointSets {
    public:
        void makeDisjointSet(Graph & graph);
        long find(long elem);
        void setunion(long a, long b);
        long size(long elem);

    private:
        std::map<long, long> disjoint_map;       
};

class Kruskals {
    public:
        Kruskals(Graph & graph);
        
        std::vector<Node> kruskals_alg;
        void sortEdges();
        std::vector<Edge> traverse_kruskal();

    private: 
        Graph graph_;
        DisjointSets ds_;
};