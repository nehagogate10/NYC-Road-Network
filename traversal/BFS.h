/**
 * @file BFS.h
 */
//Code Refactored from mp_traversals Spring 2021
#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <queue>

#include "Traversal.h"

/**
 * A breadth-first Traversal.
 * Derived from base class Traversal
 */
class BFS : public Traversal {
public:
  BFS(const Graph & graph, long start);

  Traversal::Iterator begin();
  Traversal::Iterator end();

  void add(long id);
  long pop();
  long peek() const;
  bool empty() const;

private:
  std::queue<long> queue_;
  Graph graph_;
  long start_;
};
