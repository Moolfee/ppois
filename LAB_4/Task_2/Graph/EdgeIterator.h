#pragma once

#include "Edge.h"
#include <iterator>
#include <list>

template <typename T> class EdgeIterator {
public:
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = Edge<T> *;
  using difference_type = std::ptrdiff_t;
  using pointer = Edge<T> *;
  using reference = Edge<T> *;

  explicit EdgeIterator(typename std::list<Edge<T>>::iterator it)
      : cursor(it) {}

  reference operator*() const { return &(*cursor); }
  pointer operator->() const { return &(*cursor); }

  EdgeIterator &operator++() {
    ++cursor;
    return *this;
  }
  EdgeIterator operator++(int) {
    EdgeIterator tmp(*this);
    ++(*this);
    return tmp;
  }
  EdgeIterator &operator--() {
    --cursor;
    return *this;
  }
  EdgeIterator operator--(int) {
    EdgeIterator tmp(*this);
    --(*this);
    return tmp;
  }
  bool operator==(const EdgeIterator &other) const {
    return cursor == other.cursor;
  }
  bool operator!=(const EdgeIterator &other) const {
    return !(*this == other);
  }

  typename std::list<Edge<T>>::iterator base() const { return cursor; }

private:
  typename std::list<Edge<T>>::iterator cursor;
};

template <typename T> class ConstEdgeIterator {
public:
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = const Edge<T> *;
  using difference_type = std::ptrdiff_t;
  using pointer = const Edge<T> *;
  using reference = const Edge<T> *;

  explicit ConstEdgeIterator(typename std::list<Edge<T>>::const_iterator it)
      : cursor(it) {}

  reference operator*() const { return &(*cursor); }
  pointer operator->() const { return &(*cursor); }

  ConstEdgeIterator &operator++() {
    ++cursor;
    return *this;
  }
  ConstEdgeIterator operator++(int) {
    ConstEdgeIterator tmp(*this);
    ++(*this);
    return tmp;
  }
  ConstEdgeIterator &operator--() {
    --cursor;
    return *this;
  }
  ConstEdgeIterator operator--(int) {
    ConstEdgeIterator tmp(*this);
    --(*this);
    return tmp;
  }
  bool operator==(const ConstEdgeIterator &other) const {
    return cursor == other.cursor;
  }
  bool operator!=(const ConstEdgeIterator &other) const {
    return !(*this == other);
  }

  typename std::list<Edge<T>>::const_iterator base() const { return cursor; }

private:
  typename std::list<Edge<T>>::const_iterator cursor;
};
