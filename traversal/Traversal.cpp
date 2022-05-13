//Code Refactored from mp_traversals Spring 2021
#include <cmath>
#include <iterator>
#include <iostream>

#include "Traversal.h"

/**
 * Default iterator constructor.
 */
Traversal::Iterator::Iterator() : traversal_(nullptr) {
}

Traversal::Iterator::Iterator(Traversal* traversal, long start, Graph graph) : traversal_(nullptr) {
  traversal_ = traversal;
  curr_ = start;
  start_ = start;
  graph_ = graph;

  for (auto const& node : graph_.vertices_) {
    visited_[node.first] = false;
  }

  if(canIterate(start_)) {
    visited_[start_] = true;
  }
}

bool Traversal::Iterator::canIterate(long id) {
  return ((graph_.vertices_.count(id) > 0) && !visited_[id]);
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
Traversal::Iterator & Traversal::Iterator::operator++() {
  if(!traversal_->empty()) {
    long temp = curr_;

    traversal_->pop();
    visited_[temp] = true;

    while (!traversal_->empty() && !canIterate(traversal_->peek())) {
      curr_ = traversal_->pop();
    }

    for (auto const& edge : graph_.edges_) { 
      if(edge.from_id_ == temp) {
        if(canIterate(edge.to_id_)) {
          traversal_->add(edge.to_id_); 
        }
      }

      if(edge.to_id_ == temp) {
        if(canIterate(edge.from_id_)) {
          traversal_->add(edge.from_id_);
        }
      }
    }

    if (!traversal_->empty()) {
      curr_ = traversal_->peek();
    }
  }

  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current node id in the Traversal.
 */
long Traversal::Iterator::operator*() {
  return curr_;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool Traversal::Iterator::operator!=(const Traversal::Iterator &other) {
  if (traversal_ == nullptr && other.traversal_ == nullptr) {
    return false;
  }
  if (traversal_ == nullptr) {
    return !other.traversal_->empty();
  }
  if (other.traversal_ == nullptr) {
    return !traversal_->empty();
  }
  if (traversal_->empty() && other.traversal_->empty()) {
    return false;
  }
  return traversal_ != other.traversal_;
}

