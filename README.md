# CS 225 Final Project

### Data
The data set we used is the Street Network of Manhattan
This data is in the file manhattan.graphml, and contains all information about edges and nodes as well as properties of the graph itself stored in different keys. 

### Key Classes
We have five major classes: Graph, GraphmlParser, BFS, AStar, and Kruskals
#### Graph
Graph.h & Graph.cpp
The Graph class contains the Node, Edge, and Graph classes and all their methods and variables. 

#### GraphmlParser
GraphmlParser.h & GraphmlParser.cpp
The GraphmlParser class is where we wrote our own logic for parsing through our data, which was in Graphml format
While reading through the file, we put the data in Node and Edge objects and then add these attributes to the graph class. 

#### BFS
BFS.h & BFS.cpp
We implemented our BFS traversal of our data in the BFS class. 

#### AStar
AStar.h & AStar.cpp
Our implementation of the AStar algorithm for our dataset

#### Kruskals
Kruskals.h & Kruskals.cpp
Our implementation of the Kruskals algorithm for minimum spanning tree our dataset

### Results
- For Kruskals algorithm, we are outputting the list of edges that are visited

### Running Executables
#### For Make
To run the entire program and traversals, type 'make' into the terminal. Depending on what machine you're using, you may have to put in 'module load llvm/6.0.1' before doing 'make'

#### For Tests
To run tests, type 'make test' and then './test' to run all the test cases
Our test cases test simple graph functions and creation, and then our BFS, Kruskals, and AStar algorithms
