#pragma once

#include "Edge.h"
#include "Vertex.h"
#include <iterator>

// Последовательный итератор по вершинам, смежным заданной вершине.
template <typename T> class AdjacentVertexIterator {
public:
  using iterator_category = std::forward_iterator_tag;
  using value_type = Vertex<T> *;
  using difference_type = std::ptrdiff_t;
  using pointer = Vertex<T> *;
  using reference = Vertex<T> *;

  AdjacentVertexIterator() = default;
  AdjacentVertexIterator(Vertex<T> *origin, Edge<T> *edge)
      : vertex(origin), current(edge) {}

  reference operator*() const { return current->other(vertex); }
  pointer operator->() const { return current->other(vertex); }

  AdjacentVertexIterator &operator++() {
    current = current ? current->nextFor(vertex) : nullptr;
    return *this;
  }
  AdjacentVertexIterator operator++(int) {
    AdjacentVertexIterator tmp(*this);
    ++(*this);
    return tmp;
  }
  bool operator==(const AdjacentVertexIterator &other) const {
    return vertex == other.vertex && current == other.current;
  }
  bool operator!=(const AdjacentVertexIterator &other) const {
    return !(*this == other);
  }

private:
  Vertex<T> *vertex = nullptr;
  Edge<T> *current = nullptr;
};

template <typename T> class ConstAdjacentVertexIterator {
public:
  using iterator_category = std::forward_iterator_tag;
  using value_type = const Vertex<T> *;
  using difference_type = std::ptrdiff_t;
  using pointer = const Vertex<T> *;
  using reference = const Vertex<T> *;

  ConstAdjacentVertexIterator() = default;
  ConstAdjacentVertexIterator(const Vertex<T> *origin, const Edge<T> *edge)
      : vertex(origin), current(edge) {}

  reference operator*() const { return current->other(vertex); }
  pointer operator->() const { return current->other(vertex); }

  ConstAdjacentVertexIterator &operator++() {
    current = current ? current->nextFor(vertex) : nullptr;
    return *this;
  }
  ConstAdjacentVertexIterator operator++(int) {
    ConstAdjacentVertexIterator tmp(*this);
    ++(*this);
    return tmp;
  }
  bool operator==(const ConstAdjacentVertexIterator &other) const {
    return vertex == other.vertex && current == other.current;
  }
  bool operator!=(const ConstAdjacentVertexIterator &other) const {
    return !(*this == other);
  }

private:
  const Vertex<T> *vertex = nullptr;
  const Edge<T> *current = nullptr;
};
