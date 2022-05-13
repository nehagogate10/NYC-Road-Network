#include <iostream>
#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "GraphmlParser.h"
#include "traversal/Traversal.h"
#include "traversal/BFS.h"
#include "AStar/AStar.h"
#include "Kruskals.h"

int main() {
  Graph graph;
  GraphmlParser parser;
  std::string file = "manhattan.graphml";
  parser.parseFile(file, graph);

  std::map<long, int> map;

  //BFS
  BFS bfs(graph, 42434946);
  int numberOfNodes = 0;
  for(auto it = bfs.begin(); it != bfs.end(); ++it) {
    ++numberOfNodes;
  }

  std::cout << "Size of vertices: " << graph.vertices_.size() << std::endl;
  std::cout << "Size of edges: " << graph.edges_.size() << std::endl;
  std::cout << "Number of nodes traversed: " << numberOfNodes << std::endl;

  //A*
  AStar astar = AStar(graph);
  Node starting = graph.vertices_[42437018];
  Node ending = graph.vertices_[42434948];

  std::vector<int> bestPath = astar.findBestPath(starting, ending);
  std::cout << "testing astar" << bestPath.size() << std::endl;
  for (size_t i = 1; i < bestPath.size(); i++) {
    for(auto & edge : graph.edges_) {
      if(edge.from_id_ == bestPath[i-1] && edge.to_id_ == bestPath[i]) {
        std::cout << edge.name_ << std::endl;
      }

      if(edge.to_id_ == bestPath[i-1] && edge.from_id_ == bestPath[i]) {
        std::cout << edge.name_ << std::endl;
      }
    }
  }

  //kruskal algorithm
  Kruskals kruskals(graph);
  std::vector<Edge> edges_visited = kruskals.traverse_kruskal();
}