# CS 225 Final Project

## Data
Data set of the Street Network of Manhattan

Data file: manhattan.graphml

Contains all information about edges and nodes, as well as properties of the graph itself stored in different keys. 


## Key Classes
Five major classes: Graph, GraphmlParser, BFS, AStar, & Kruskals

### Graph
Graph.h & Graph.cpp

Graph class contains the Node, Edge, and Graph classes and all their methods and variables. 

### GraphmlParser
GraphmlParser.h & GraphmlParser.cpp


The GraphmlParser class is where we wrote our own logic for parsing through our data, which was in Graphml format


While reading through the file, we store the data in Node and Edge objects and then add these attributes to the graph class. 

### BFS
BFS.h & BFS.cpp

We implemented our BFS traversal of our data in the BFS class. 

### AStar
AStar.h & AStar.cpp

Our implementation of the AStar algorithm for our dataset

### Kruskals
Kruskals.h & Kruskals.cpp

Our implementation of the Kruskals algorithm for minimum spanning tree for our dataset


## Running Executables
### For Make
To run the entire program and traversals:

$ 'module load llvm/6.0.1' (optional; only if necessary for your machine)

$ 'make' 


### For Tests

To run all test cases:


$ 'make test'

$ './test' to run all the test cases


Our test cases test simple graph functions and creation, and then our BFS, Kruskals, and AStar algorithms
