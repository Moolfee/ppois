#pragma once

#include "Edge.h"
#include "Vertex.h"
#include <iterator>

template <typename T> class IncidentEdgeIterator {
public:
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = Edge<T> *;
  using difference_type = std::ptrdiff_t;
  using pointer = Edge<T> *;
  using reference = Edge<T> *;

  IncidentEdgeIterator() = default;
  IncidentEdgeIterator(Vertex<T> *origin, Edge<T> *edge)
      : vertex(origin), current(edge) {}

  reference operator*() const { return current; }
  pointer operator->() const { return current; }

  IncidentEdgeIterator &operator++() {
    current = current ? current->nextFor(vertex) : nullptr;
    return *this;
  }
  IncidentEdgeIterator operator++(int) {
    IncidentEdgeIterator tmp(*this);
    ++(*this);
    return tmp;
  }
  IncidentEdgeIterator &operator--() {
    if (!vertex) {
      return *this;
    }
    if (!current) {
      Edge<T> *cursor = vertex->firstEdge;
      Edge<T> *prev = nullptr;
      while (cursor) {
        prev = cursor;
        cursor = cursor->nextFor(vertex);
      }
      current = prev;
      return *this;
    }
    Edge<T> *cursor = vertex->firstEdge;
    Edge<T> *prev = nullptr;
    while (cursor && cursor != current) {
      prev = cursor;
      cursor = cursor->nextFor(vertex);
    }
    current = prev;
    return *this;
  }
  IncidentEdgeIterator operator--(int) {
    IncidentEdgeIterator tmp(*this);
    --(*this);
    return tmp;
  }
  bool operator==(const IncidentEdgeIterator &other) const {
    return vertex == other.vertex && current == other.current;
  }
  bool operator!=(const IncidentEdgeIterator &other) const {
    return !(*this == other);
  }

private:
  Vertex<T> *vertex = nullptr;
  Edge<T> *current = nullptr;
};

template <typename T> class ConstIncidentEdgeIterator {
public:
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = const Edge<T> *;
  using difference_type = std::ptrdiff_t;
  using pointer = const Edge<T> *;
  using reference = const Edge<T> *;

  ConstIncidentEdgeIterator() = default;
  ConstIncidentEdgeIterator(const Vertex<T> *origin, const Edge<T> *edge)
      : vertex(origin), current(edge) {}

  reference operator*() const { return current; }
  pointer operator->() const { return current; }

  ConstIncidentEdgeIterator &operator++() {
    current = current ? current->nextFor(vertex) : nullptr;
    return *this;
  }
  ConstIncidentEdgeIterator operator++(int) {
    ConstIncidentEdgeIterator tmp(*this);
    ++(*this);
    return tmp;
  }
  ConstIncidentEdgeIterator &operator--() {
    if (!vertex) {
      return *this;
    }
    if (!current) {
      const Edge<T> *cursor = vertex->firstEdge;
      const Edge<T> *prev = nullptr;
      while (cursor) {
        prev = cursor;
        cursor = cursor->nextFor(vertex);
      }
      current = prev;
      return *this;
    }
    const Edge<T> *cursor = vertex->firstEdge;
    const Edge<T> *prev = nullptr;
    while (cursor && cursor != current) {
      prev = cursor;
      cursor = cursor->nextFor(vertex);
    }
    current = prev;
    return *this;
  }
  ConstIncidentEdgeIterator operator--(int) {
    ConstIncidentEdgeIterator tmp(*this);
    --(*this);
    return tmp;
  }
  bool operator==(const ConstIncidentEdgeIterator &other) const {
    return vertex == other.vertex && current == other.current;
  }
  bool operator!=(const ConstIncidentEdgeIterator &other) const {
    return !(*this == other);
  }

private:
  const Vertex<T> *vertex = nullptr;
  const Edge<T> *current = nullptr;
};
