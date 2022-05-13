//Code Refactored from mp_traversals Spring 2021
#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "Traversal.h"
#include "BFS.h"

/**
 * Initializes a breadth-first Traversal on a given graph,
 * starting at `start`
 * @param graph The Graph this BFS is going to traverse
 * @param start The start node id of this BFS
 */
BFS::BFS(const Graph & graph, long start) {  
	graph_ = graph;
	start_ = start;
	queue_.push(start);
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
Traversal::Iterator BFS::begin() {
  return Traversal::Iterator(this, start_, graph_);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
Traversal::Iterator BFS::end() {
  return Traversal::Iterator();
}

/**
 * Adds an id for the traversal to visit at some point in the future.
 */
void BFS::add(long id) {
  queue_.push(id);
}

/**
 * Removes and returns the current id in the traversal.
 */
long BFS::pop() {
  long id = queue_.front();
  queue_.pop();
  return id;
}

/**
 * Returns the current id in the traversal.
 */
long BFS::peek() const {
  return queue_.front();
}

/**
 * Returns true if the traversal is empty.
 */
bool BFS::empty() const {
  return queue_.empty();
}
