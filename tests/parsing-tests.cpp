#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Graph.h"
#include "GraphmlParser.h"

//do we need this if we're using a library?

//valid edges txt + nodes graph: 0--1--2 
// TEST_CASE("Check parsing of valid graph") {
//   GraphmlParser parser;
//   Graph graph;
//   std::string edgesFile = "validedges.txt";
//   std::string nodesFile = "validnodes.txt";
//   std::string file = "manhattan.graphml";
//   parser.parseFile(file, graph);
// }