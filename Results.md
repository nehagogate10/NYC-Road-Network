# Results (rlwei2, staneja3, ngogate2)
# CS225 Data Structures Final Project

## Presentation

[Slides](https://docs.google.com/presentation/d/1_NK-kpnRGuIGMQHD9LCOn5vvWKV5hm_2w-ArxXuJNrA/edit?usp=sharing)

[Video](https://www.youtube.com/watch?v=m6SsK9dvl3w)

## Traversal - Breadth First Search

We decided to implement BFS because it is commonly used in pathfinding algorithms like Dijkstra's. And from the perspective of online map functionality, being able to search closer nodes first makes more sense. 

We implemented BFS in a similar manner to the implementation in mp_traversals from earlier in the semester. To do so, we created a Traversal and BFS class. The overall traversal code is the same, but this object decomposition makes it easier to add in addtional traversals like Depth-First Search. BFS uses a queue in order to traverse closer nodes chosen for traversal earlier.

Because we implemented the Traversal class, we were able to easily implement an iterator and run a full BFS of the entire graph of Manhattan. We confirmed its success by noting that the total number of nodes in the graph is 4426, and BFS runs for 4426 iterations. We also ensured that it was visiting 4426 unique nodes by creating a map and storing the Node id BFS accesses each iteration in a map. We then confirmed that the size of the map was 4426. In addition to this, we also tested using test datasets that we created.

The input of our BFS was the Graph data structure we implemented, as well as the node ID for the node to start on (analagous to an intersection in Manhattan). Because we implemented an iterator, we decided our implementation should simply return the ID of the current node in the traversal upon being dereferenced.

## Covered Algorithm - Kruskal's Algorithm

For Kruskal's algorithm, we wanted to take in the Graph and output the Minimal Spanning Tree. The algorithm takes in a Graph data structure and outputs a vector of Edges in the order that they were added to the MST. We checked its performance by checking if the size of the outputted vector was equal to the (size of the Nodes map - 1). We also created a test suite for Kruskal's algorithm.

We had to implement the algorithm along with a Disjoint Sets data structure specific to our graph. Unlike the previous MP implementation, our Disjoint Sets data structure used a map of long key-value pairs. This was because the MP implementation had a simple array with indices from 0-n, but we had long Node IDs and creating a vector with a size in the millions was not feasable. We then initialized the Disjoint set with each Node in the tree in its own set, then unioned sets based on the edges that were added.

## Complex Algorithm - A* Algorithm

The complex algorithm we decided to implement is the A* algorithm, which is used in the official Google Maps implementation, although in a more complicated manner. 

The heuristic we decided to use for our A* algorithm was distance. For the purposes of our implementation we simply used latitude and longitude as x & y cooridinates for Euclidean distance i.e. direct distance as seen from above (goes through buildings etc). However, a better impelementation might have been using Manhattan Distance distance, which is the distance a pedestrian would actually require to walk to the specific location from the desired one. However, this implementation proved a bit too complicated as using accurate Manhattan distance would require knowing the lengths of the streets on the path.

The input for A* is the the Graph data structure along with a start and end Node ID. A way to improve this input system would be to create a KD-tree of our Nodes using the Latitude and Longitude, and then allowing the user to input a specific set of coordinates for the beginning and ending locations, and finding the closest Nodes to those to use for our algorithm.

The output of our A* algorithm is a vector of Node IDs. At first we simply confirmed that the beginning and end Nodes in this vector were correct. In our main file, we created a small bit of code to output the street names on the edges linking the Nodes in the vector, and we used this to cross-reference our code with Google Maps. One such example is given below:

Some streets are repeated, so a multiplier has been added for how many edges lied on that street

Union Square Park - (40.7359443, -73.9893605), Node ID: 
- Union Square East
- Park Avenue South (x 14)
- East 31st Street
- Lexington Avenue (x 3)
- East 34th Street (x 6)
- Madison Avenue

Empire State Building - (40.748432, -73.982473)

![map image](https://i.ibb.co/hyGZqVJ/Capture.png)

We also created a test suite to test A* on a small amount of Nodes. We created two different graphs to test the parsing, BFS, A*, and Kruskal on: one of a line graph with the layout 0 -- 1 -- 2, and another of a cycle of 6 nodes. We were able to verify the correctness of the algorithms on these two graphs by either checking that the order of the bestPath was correct, or by checking that the size of the vector returned was accurate. By passing these tests, we have more confidence that these implementations would work correctly for the original dataset. 
