# Project Proposal (rlwei2, staneja3, ngogate2)
# CS225 Data Structures Final Project

## Leading Question: 

Using a dataset that stores the network of streets in New York City, we hope to analyze the fastest way to get from one location to another. By solving the issue, we hope to provide google maps-like functionality. If possible within the given time restraints, we would also like to visualize this shortest path by projecting the nodes and edges of the graph onto a map of NYC. 

## Dataset Acquisition and Processing:

The [dataset we chose to use](https://www.kaggle.com/crailtap/street-network-of-new-york-in-graphml) was from Kaggle.com, and its contents include one large graph for the street network of New York City in GraphML format and a subgraph of Manhattan. The map includes the graph nodes and edges that provide information such as how long the road is, what the speed limit it is, and other useful info. We plan to use the nodes to calculate the shortest path between two points in the city, which traversal of the nodes will allow one to get from one node to another faster.

We have stored the data files in our Git repository. Since the data is in a GraphML format which is based on XML, we are going to use an XML parser to convert the GraphML files into our Graph data structure we implement in C++. To limit the potential errors, we tried to find a well reputed and received dataset, but to handle the potential errors, we will ignore the information with missing entries when doing calculations or attempt to fill in the dataset with information we research.

## Graph Algorithms 

The traversal we've decided to implement is a Breadth First Search. We decided upon this because it is used to find the shortest distance between two nodes. It will take a starting and ending location/node. We will most likely have it return a vector of Node pointers to traverse, or just the specific location of each node. We could then use this to return a sequence of directions to go from one location to another. The worse case time complexity is O(V+E), where V is the number of vertices and E is the number of edges in the graph

The main algorithm we've decided implement is the A* algorithm, which is used in the official Google Maps implementation, although in a more complicated manner. The inputs and outputs for the algorithm should be the same as BFS, but A* also requires a heuristic which is what allows it to approximate the path in a shorter time than BFS. The worse case time complexity is O(E), where E is the number of edges in the graph

From here we either want to graphically represent the output of the A* algorithm using a real map of Manhattan, or if that proves to be too difficult, we will implement Prim's algorithm. 

For the graphical output, we intend to use the provided coordinates for each node to graph the path from the specified beginning and end onto a real map of Manhattan, potentially using a map API.  

For Prim's algorithm, we want to input a graph vertex/node, and get the tree root (the same as the graph location inputted) of the Minimally Spanning Tree using. This will represent paths from the one specified location to all parts of the city. The time complexity of Prim's is O(VlogV + ElogV) which simplifies to O(ElogV) where V is the number of vertices and E is the number of edges in the graph.

| Goal | Time Complexity |
| :------------- | :----------: |
| BFS | O(V+E) |
| A* | O(E) |
| Prim | O(ElogV) |
| Graphical output | N/A |

## Timeline

| Benchmark      | Tentative Outline     |
| :------------- | :----------: |
|  Creating the graph data structure | First week |
| Parsing GraphML data | Second week |
| A* algorithm | Third week |
| Prim's aglorithm/Graphical output | Fourth week |