#pragma once

#include "Vertex.h"
#include <iterator>
#include <list>

template <typename T> class VertexIterator {
public:
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = Vertex<T> *;
  using difference_type = std::ptrdiff_t;
  using pointer = Vertex<T> *;
  using reference = Vertex<T> *;

  explicit VertexIterator(typename std::list<Vertex<T>>::iterator it)
      : cursor(it) {}

  reference operator*() const { return &(*cursor); }
  pointer operator->() const { return &(*cursor); }

  VertexIterator &operator++() {
    ++cursor;
    return *this;
  }
  VertexIterator operator++(int) {
    VertexIterator tmp(*this);
    ++(*this);
    return tmp;
  }
  VertexIterator &operator--() {
    --cursor;
    return *this;
  }
  VertexIterator operator--(int) {
    VertexIterator tmp(*this);
    --(*this);
    return tmp;
  }
  bool operator==(const VertexIterator &other) const {
    return cursor == other.cursor;
  }
  bool operator!=(const VertexIterator &other) const {
    return !(*this == other);
  }

  typename std::list<Vertex<T>>::iterator base() const { return cursor; }

private:
  typename std::list<Vertex<T>>::iterator cursor;
};

template <typename T> class ConstVertexIterator {
public:
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = const Vertex<T> *;
  using difference_type = std::ptrdiff_t;
  using pointer = const Vertex<T> *;
  using reference = const Vertex<T> *;

  explicit ConstVertexIterator(
      typename std::list<Vertex<T>>::const_iterator it)
      : cursor(it) {}

  reference operator*() const { return &(*cursor); }
  pointer operator->() const { return &(*cursor); }

  ConstVertexIterator &operator++() {
    ++cursor;
    return *this;
  }
  ConstVertexIterator operator++(int) {
    ConstVertexIterator tmp(*this);
    ++(*this);
    return tmp;
  }
  ConstVertexIterator &operator--() {
    --cursor;
    return *this;
  }
  ConstVertexIterator operator--(int) {
    ConstVertexIterator tmp(*this);
    --(*this);
    return tmp;
  }
  bool operator==(const ConstVertexIterator &other) const {
    return cursor == other.cursor;
  }
  bool operator!=(const ConstVertexIterator &other) const {
    return !(*this == other);
  }

  typename std::list<Vertex<T>>::const_iterator base() const { return cursor; }

private:
  typename std::list<Vertex<T>>::const_iterator cursor;
};
