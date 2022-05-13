#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../Graph.h"
#include <map>
#include "../GraphmlParser.h"
#include "../traversal/Traversal.h"
#include "../traversal/BFS.h"
#include "../AStar/AStar.h"
#include "../Kruskals.h"

TEST_CASE("Sanity Check") {
    REQUIRE(true);
}

// valid edges txt + nodes graph: 0--1--2 
TEST_CASE("Parsing simple line graph") {
    GraphmlParser parser;
    Graph graph;
    std::string file = "tests/validlinegraph.graphml";
    parser.parseFile(file, graph);

    //check that parsed correctly
    std::map<long, Node> nodes = graph.vertices_;
    std::vector<Edge> edges = graph.edges_;
    
    //check size of nodes + edges
    REQUIRE(nodes.size() == 3);
    REQUIRE(edges.size() == 2);
    
    //check that edges are connected correctly
    REQUIRE(edges[0].to_id_ == 1);
    REQUIRE(edges[0].from_id_ == 0);
    REQUIRE(edges[1].to_id_ == 2);
    REQUIRE(edges[1].from_id_ == 1);
}

// A*
TEST_CASE("A* line graph test") {
    GraphmlParser parser;
    Graph graph;
    std::string file = "tests/validlinegraph.graphml";
    parser.parseFile(file, graph);

    //check that parsed correctly
    std::map<long, Node> nodes = graph.vertices_;
    std::vector<Edge> edges = graph.edges_;
    
    //check size of nodes + edges
    REQUIRE(nodes.size() == 3);
    REQUIRE(edges.size() == 2);
    
    //check that edges are connected correctly
    REQUIRE(edges[0].to_id_ == 1);
    REQUIRE(edges[0].from_id_ == 0);
    REQUIRE(edges[1].to_id_ == 2);
    REQUIRE(edges[1].from_id_ == 1);

    //check a*
    AStar astar = AStar(graph);
    Node starting = graph.vertices_[0];
    Node ending = graph.vertices_[2];

    //best path from 0 to 2
    std::vector<int> bestPath = astar.findBestPath(starting, ending);
    REQUIRE(bestPath[0] == 0);
    REQUIRE(bestPath[1] == 1);
    REQUIRE(bestPath[2] == 2);

    //best path from 2 to 0 (reverse direction)
    bestPath = astar.findBestPath(ending, starting);
    REQUIRE(bestPath[0] == 2);
    REQUIRE(bestPath[1] == 1);
    REQUIRE(bestPath[2] == 0);
}

// BFS
TEST_CASE("BFS line graph test") {
    GraphmlParser parser;
    Graph graph;
    std::string file = "tests/validlinegraph.graphml";
    parser.parseFile(file, graph);

    //check that parsed correctly
    std::map<long, Node> nodes = graph.vertices_;
    std::vector<Edge> edges = graph.edges_;
    
    //check size of nodes + edges
    REQUIRE(nodes.size() == 3);
    REQUIRE(edges.size() == 2);
    
    //check that edges are connected correctly
    REQUIRE(edges[0].to_id_ == 1);
    REQUIRE(edges[0].from_id_ == 0);
    REQUIRE(edges[1].to_id_ == 2);
    REQUIRE(edges[1].from_id_ == 1);

    //check bfs
    BFS bfs(graph, 0);
    std::vector<long> nodes_visited;

    for(auto it = bfs.begin(); it != bfs.end(); ++it) {
        nodes_visited.push_back(*it);
    }

    REQUIRE(nodes_visited[0] == 0);
    REQUIRE(nodes_visited[1] == 1);
    REQUIRE(nodes_visited[2] == 2);
}

// Kruskals
TEST_CASE("Kruskals line graph test") {
    GraphmlParser parser;
    Graph graph;
    std::string file = "tests/validlinegraph.graphml";
    parser.parseFile(file, graph);

    //check that parsed correctly
    std::map<long, Node> nodes = graph.vertices_;
    std::vector<Edge> edges = graph.edges_;
    
    //check size of nodes + edges
    REQUIRE(nodes.size() == 3);
    REQUIRE(edges.size() == 2);
    
    //check that edges are connected correctly
    REQUIRE(edges[0].to_id_ == 1);
    REQUIRE(edges[0].from_id_ == 0);
    REQUIRE(edges[1].to_id_ == 2);
    REQUIRE(edges[1].from_id_ == 1);

    //check kruskals
    Kruskals kruskals(graph);
    std::vector<Edge> edges_visited = kruskals.traverse_kruskal();

    REQUIRE(edges_visited[0].from_id_ == 0);
    REQUIRE(edges_visited[0].to_id_ == 1);
    REQUIRE(edges_visited[1].from_id_ == 1);
    REQUIRE(edges_visited[1].to_id_ == 2);
}

TEST_CASE("Valid cycle line graph-- parsing, BFS, A*") {
    GraphmlParser parser;
    Graph graph;
    std::string file = "tests/validcycle.graphml";
    parser.parseFile(file, graph);
    //check that parsed correctly
    std::map<long, Node> nodes = graph.vertices_;
    std::vector<Edge> edges = graph.edges_;
    
    //check size of nodes + edges
    REQUIRE(nodes.size() == 5);
    REQUIRE(edges.size() == 4);
    
    //check that edges are connected correctly
    REQUIRE(edges[0].to_id_ == 1);
    REQUIRE(edges[0].from_id_ == 0);
    REQUIRE(edges[1].to_id_ == 2);
    REQUIRE(edges[1].from_id_ == 1);

    //check bfs
    BFS bfs(graph, 0);
    std::vector<long> nodes_visited;

    for(auto it = bfs.begin(); it != bfs.end(); ++it) {
        nodes_visited.push_back(*it);
    }
    REQUIRE(nodes_visited[0] == 0);
    REQUIRE(nodes_visited[1] == 1);
    REQUIRE(nodes_visited[2] == 3);

    //check a*
    AStar astar = AStar(graph);
    Node starting = graph.vertices_[0];
    Node ending = graph.vertices_[3];

    //best path from 0 to 3
    std::vector<int> bestPath = astar.findBestPath(starting, ending);
    std::cout << bestPath.size() << std::endl;
    REQUIRE(bestPath[0] == 0);
    REQUIRE(bestPath[1] == 3);
}