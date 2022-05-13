//Code Refactored from mp_traversals Spring 2021
#pragma once

#include "../Graph.h"
#include <iterator>
#include <vector>
#include <map>

/**
 * A base class for traversal algorithms on graph.
 *
 * BFS will inherit from this class
 * 
 * Each derived class must maintain an ordering of points on an image,
 * through calls to the virtual member functions `add` and `pop`.
 * 
 * A derived class provides a traversal by returning instances of
 * Traversal::Iterator.
 */
class Traversal {
public:
  /**
   * A forward iterator through a Traversal.
   */
  class Iterator : std::iterator<std::forward_iterator_tag, long> {
  public:
    Iterator();
    Iterator(Traversal* traversal, long start, Graph graph);

    Iterator & operator++();
    long operator*();
    bool operator!=(const Iterator &other);

    /**
     * Helper method to check if meets criteria to iterate: within bounds, within tolerance, not visited already
     */
    bool canIterate(long id);

  private:
    Traversal* traversal_;
    long curr_;
    long start_;
    std::map<long, bool> visited_;
    Graph graph_;
  };

  /**
   * The begining of an iterator
   * Virtual function. Derived class need to implement this
   */
  virtual Iterator begin() = 0;

  /**
   * The end of an iterator
   * Virtual function. Derived class need to implement this
   */
  virtual Iterator end() = 0;

  /**
   * Add new point to the traversal
   * Virtual function. Derived class need to implement this
   */
  virtual void add(long id) = 0;
  /**
   * Remove and return the next point of the traversal
   * Virtual function. Derived class need to implement this
   */
  virtual long pop() = 0;
  /**
   * Return but not remove the next point of the traversal
   * Virtual function. Derived class need to implement this
   */
  virtual long peek() const = 0;
  /**
   * To see if the traversal has no points left
   * Virtual function. Derived class need to implement this
   */
  virtual bool empty() const = 0;
};
