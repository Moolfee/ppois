#pragma once

#include "AdjacentVertexIterator.h"
#include "Edge.h"
#include "EdgeIterator.h"
#include "IncidentEdgeIterator.h"
#include "Vertex.h"
#include "VertexIterator.h"

#include <cstddef>
#include <list>
#include <stdexcept>
#include <utility>
#include <vector>

template <typename T> class Graph {
public:
  using vertex_handle = Vertex<T> *;
  using edge_handle = Edge<T> *;

  using vertex_iterator = VertexIterator<T>;
  using const_vertex_iterator = ConstVertexIterator<T>;
  using reverse_vertex_iterator = std::reverse_iterator<vertex_iterator>;
  using const_reverse_vertex_iterator =
      std::reverse_iterator<const_vertex_iterator>;

  using edge_iterator = EdgeIterator<T>;
  using const_edge_iterator = ConstEdgeIterator<T>;
  using reverse_edge_iterator = std::reverse_iterator<edge_iterator>;
  using const_reverse_edge_iterator =
      std::reverse_iterator<const_edge_iterator>;

  using incident_edge_iterator = IncidentEdgeIterator<T>;
  using const_incident_edge_iterator = ConstIncidentEdgeIterator<T>;
  using reverse_incident_edge_iterator =
      std::reverse_iterator<incident_edge_iterator>;
  using const_reverse_incident_edge_iterator =
      std::reverse_iterator<const_incident_edge_iterator>;

  using adjacent_vertex_iterator = AdjacentVertexIterator<T>;
  using const_adjacent_vertex_iterator = ConstAdjacentVertexIterator<T>;

  Graph() = default;
  Graph(const Graph &other);
  Graph &operator=(const Graph &other);
  ~Graph();

  bool empty() const { return vertices.empty(); }
  void clear();

  vertex_handle addVertex(const T &value);
  std::size_t vertexCount() const { return vertices.size(); }
  vertex_handle getVertex(std::size_t index);
  const vertex_handle getVertex(std::size_t index) const;

  edge_handle addEdge(vertex_handle first, vertex_handle second);
  edge_handle addEdge(std::size_t firstIndex, std::size_t secondIndex);
  std::size_t edgeCount() const { return edges.size(); }

  bool containsVertex(const vertex_handle vertex) const;
  bool containsEdge(const vertex_handle first,
                    const vertex_handle second) const;

  std::size_t vertexDegree(const vertex_handle vertex) const;
  std::size_t edgeDegree(const edge_handle edge) const;

  bool removeEdge(edge_handle edge);
  bool removeEdge(const edge_iterator &it);
  bool removeEdge(const const_edge_iterator &it);

  bool removeVertex(vertex_handle vertex);
  bool removeVertex(const vertex_iterator &it);
  bool removeVertex(const const_vertex_iterator &it);

  vertex_iterator verticesBegin() { return vertex_iterator(vertices.begin()); }
  vertex_iterator verticesEnd() { return vertex_iterator(vertices.end()); }
  const_vertex_iterator verticesCBegin() const {
    return const_vertex_iterator(vertices.cbegin());
  }
  const_vertex_iterator verticesCEnd() const {
    return const_vertex_iterator(vertices.cend());
  }
  reverse_vertex_iterator verticesRBegin() {
    return reverse_vertex_iterator(verticesEnd());
  }
  reverse_vertex_iterator verticesREnd() {
    return reverse_vertex_iterator(verticesBegin());
  }
  const_reverse_vertex_iterator verticesCRBegin() const {
    return const_reverse_vertex_iterator(verticesCEnd());
  }
  const_reverse_vertex_iterator verticesCREnd() const {
    return const_reverse_vertex_iterator(verticesCBegin());
  }

  edge_iterator edgesBegin() { return edge_iterator(edges.begin()); }
  edge_iterator edgesEnd() { return edge_iterator(edges.end()); }
  const_edge_iterator edgesCBegin() const {
    return const_edge_iterator(edges.cbegin());
  }
  const_edge_iterator edgesCEnd() const {
    return const_edge_iterator(edges.cend());
  }
  reverse_edge_iterator edgesRBegin() { return reverse_edge_iterator(edgesEnd()); }
  reverse_edge_iterator edgesREnd() { return reverse_edge_iterator(edgesBegin()); }
  const_reverse_edge_iterator edgesCRBegin() const {
    return const_reverse_edge_iterator(edgesCEnd());
  }
  const_reverse_edge_iterator edgesCREnd() const {
    return const_reverse_edge_iterator(edgesCBegin());
  }

  incident_edge_iterator incidentEdgesBegin(vertex_handle vertex) {
    return incident_edge_iterator(vertex, vertex ? vertex->firstEdge : nullptr);
  }
  incident_edge_iterator incidentEdgesEnd(vertex_handle vertex) {
    (void)vertex;
    return incident_edge_iterator(vertex, nullptr);
  }
  const_incident_edge_iterator incidentEdgesCBegin(
      const vertex_handle vertex) const {
    return const_incident_edge_iterator(vertex,
                                        vertex ? vertex->firstEdge : nullptr);
  }
  const_incident_edge_iterator incidentEdgesCEnd(
      const vertex_handle vertex) const {
    (void)vertex;
    return const_incident_edge_iterator(vertex, nullptr);
  }
  reverse_incident_edge_iterator incidentEdgesRBegin(vertex_handle vertex) {
    return reverse_incident_edge_iterator(incidentEdgesEnd(vertex));
  }
  reverse_incident_edge_iterator incidentEdgesREnd(vertex_handle vertex) {
    return reverse_incident_edge_iterator(incidentEdgesBegin(vertex));
  }
  const_reverse_incident_edge_iterator incidentEdgesCRBegin(
      const vertex_handle vertex) const {
    return const_reverse_incident_edge_iterator(incidentEdgesCEnd(vertex));
  }
  const_reverse_incident_edge_iterator incidentEdgesCREnd(
      const vertex_handle vertex) const {
    return const_reverse_incident_edge_iterator(incidentEdgesCBegin(vertex));
  }

  adjacent_vertex_iterator adjacentBegin(vertex_handle vertex) {
    return adjacent_vertex_iterator(vertex, vertex ? vertex->firstEdge : nullptr);
  }
  adjacent_vertex_iterator adjacentEnd(vertex_handle vertex) {
    (void)vertex;
    return adjacent_vertex_iterator(vertex, nullptr);
  }
  const_adjacent_vertex_iterator adjacentCBegin(
      const vertex_handle vertex) const {
    return const_adjacent_vertex_iterator(vertex,
                                          vertex ? vertex->firstEdge : nullptr);
  }
  const_adjacent_vertex_iterator adjacentCEnd(
      const vertex_handle vertex) const {
    (void)vertex;
    return const_adjacent_vertex_iterator(vertex, nullptr);
  }

private:
  std::list<Vertex<T>> vertices;
  std::list<Edge<T>> edges;

  void linkEdge(edge_handle edge, vertex_handle vertex);
  void unlinkEdge(edge_handle edge, vertex_handle vertex);
  edge_iterator findEdgeIterator(edge_handle edge);
  vertex_iterator findVertexIterator(vertex_handle vertex);
};

template <typename T>
Graph<T>::Graph(const Graph &other) {
  for (const Vertex<T> &vertex : other.vertices) {
    vertices.emplace_back(vertex.data);
  }
  auto otherVertexIt = other.vertices.begin();
  auto thisVertexIt = vertices.begin();
  std::vector<std::pair<const Vertex<T> *, Vertex<T> *>> mapping;
  for (; otherVertexIt != other.vertices.end(); ++otherVertexIt, ++thisVertexIt) {
    mapping.emplace_back(&(*otherVertexIt), &(*thisVertexIt));
  }
  auto mapVertex = [&](const Vertex<T> *source) -> Vertex<T> * {
    for (const auto &pair : mapping) {
      if (pair.first == source) {
        return pair.second;
      }
    }
    return nullptr;
  };
  for (const Edge<T> &edge : other.edges) {
    vertex_handle first = mapVertex(edge.endpointA);
    vertex_handle second = mapVertex(edge.endpointB);
    addEdge(first, second);
  }
}

template <typename T> Graph<T> &Graph<T>::operator=(const Graph &other) {
  if (this == &other) {
    return *this;
  }
  clear();
  Graph copy(other);
  vertices.swap(copy.vertices);
  edges.swap(copy.edges);
  return *this;
}

template <typename T> Graph<T>::~Graph() { clear(); }

template <typename T> void Graph<T>::clear() {
  edges.clear();
  vertices.clear();
}

template <typename T>
typename Graph<T>::vertex_handle Graph<T>::addVertex(const T &value) {
  vertices.emplace_back(value);
  return &vertices.back();
}

template <typename T>
typename Graph<T>::vertex_handle Graph<T>::getVertex(std::size_t index) {
  if (index >= vertices.size()) {
    throw std::out_of_range("vertex index is out of range");
  }
  auto it = vertices.begin();
  std::advance(it,
               static_cast<typename std::list<Vertex<T>>::difference_type>(index));
  return &(*it);
}

template <typename T>
const typename Graph<T>::vertex_handle
Graph<T>::getVertex(std::size_t index) const {
  if (index >= vertices.size()) {
    throw std::out_of_range("vertex index is out of range");
  }
  auto it = vertices.begin();
  std::advance(it,
               static_cast<typename std::list<Vertex<T>>::difference_type>(index));
  return &(*it);
}

template <typename T>
typename Graph<T>::edge_handle
Graph<T>::addEdge(vertex_handle first, vertex_handle second) {
  if (!first || !second || !containsVertex(first) || !containsVertex(second)) {
    throw std::invalid_argument("edge endpoints must belong to graph");
  }
  if (containsEdge(first, second)) {
    return nullptr;
  }
  edges.emplace_back(first, second);
  edge_handle handle = &edges.back();
  linkEdge(handle, first);
  linkEdge(handle, second);
  return handle;
}

template <typename T>
typename Graph<T>::edge_handle
Graph<T>::addEdge(std::size_t firstIndex, std::size_t secondIndex) {
  return addEdge(getVertex(firstIndex), getVertex(secondIndex));
}

template <typename T>
bool Graph<T>::containsVertex(const vertex_handle vertex) const {
  for (const Vertex<T> &candidate : vertices) {
    if (&candidate == vertex) {
      return true;
    }
  }
  return false;
}

template <typename T>
bool Graph<T>::containsEdge(const vertex_handle first,
                            const vertex_handle second) const {
  if (!first || !second) {
    return false;
  }
  for (Edge<T> *edge = first->firstEdge; edge; edge = edge->nextFor(first)) {
    if (edge->other(first) == second) {
      return true;
    }
  }
  return false;
}

template <typename T>
std::size_t Graph<T>::vertexDegree(const vertex_handle vertex) const {
  std::size_t degree = 0;
  for (Edge<T> *edge = vertex ? vertex->firstEdge : nullptr; edge;
       edge = edge->nextFor(vertex)) {
    ++degree;
  }
  return degree;
}

template <typename T>
std::size_t Graph<T>::edgeDegree(const edge_handle edge) const {
  if (!edge) {
    return 0;
  }
  return vertexDegree(edge->endpointA) + vertexDegree(edge->endpointB) - 2;
}

template <typename T> void Graph<T>::linkEdge(edge_handle edge, vertex_handle vertex) {
  edge->nextRef(vertex) = vertex->firstEdge;
  vertex->firstEdge = edge;
}

template <typename T>
void Graph<T>::unlinkEdge(edge_handle edge, vertex_handle vertex) {
  Edge<T> *current = vertex->firstEdge;
  Edge<T> *previous = nullptr;
  while (current && current != edge) {
    previous = current;
    current = current->nextFor(vertex);
  }
  if (!current) {
    return;
  }
  Edge<T> *next = current->nextFor(vertex);
  if (previous) {
    previous->nextRef(vertex) = next;
  } else {
    vertex->firstEdge = next;
  }
}

template <typename T>
typename Graph<T>::edge_iterator Graph<T>::findEdgeIterator(
    edge_handle edge) {
  auto it = edges.begin();
  for (; it != edges.end(); ++it) {
    if (&(*it) == edge) {
      break;
    }
  }
  return edge_iterator(it);
}

template <typename T>
typename Graph<T>::vertex_iterator Graph<T>::findVertexIterator(
    vertex_handle vertex) {
  auto it = vertices.begin();
  for (; it != vertices.end(); ++it) {
    if (&(*it) == vertex) {
      break;
    }
  }
  return vertex_iterator(it);
}

template <typename T> bool Graph<T>::removeEdge(edge_handle edge) {
  if (!edge) {
    return false;
  }
  unlinkEdge(edge, edge->endpointA);
  unlinkEdge(edge, edge->endpointB);
  auto it = findEdgeIterator(edge).base();
  if (it == edges.end()) {
    return false;
  }
  edges.erase(it);
  return true;
}

template <typename T>
bool Graph<T>::removeEdge(const edge_iterator &it) {
  if (it == edgesEnd()) {
    return false;
  }
  return removeEdge(*it);
}

template <typename T>
bool Graph<T>::removeEdge(const const_edge_iterator &it) {
  if (it == edgesCEnd()) {
    return false;
  }
  return removeEdge(*it);
}

template <typename T> bool Graph<T>::removeVertex(vertex_handle vertex) {
  if (!vertex || !containsVertex(vertex)) {
    return false;
  }
  Edge<T> *edge = vertex->firstEdge;
  while (edge) {
    Edge<T> *next = edge->nextFor(vertex);
    removeEdge(edge);
    edge = next;
  }
  auto it = findVertexIterator(vertex).base();
  vertices.erase(it);
  return true;
}

template <typename T>
bool Graph<T>::removeVertex(const vertex_iterator &it) {
  if (it == verticesEnd()) {
    return false;
  }
  return removeVertex(*it);
}

template <typename T>
bool Graph<T>::removeVertex(const const_vertex_iterator &it) {
  if (it == verticesCEnd()) {
    return false;
  }
  return removeVertex(*it);
}
