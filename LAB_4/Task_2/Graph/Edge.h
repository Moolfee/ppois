#pragma once

#include <stdexcept>

template <typename T> struct Vertex;

template <typename T> struct Edge {
  Edge(Vertex<T> *left, Vertex<T> *right)
      : endpointA(left), endpointB(right), nextFromA(nullptr),
        nextFromB(nullptr) {}

  Vertex<T> *other(const Vertex<T> *vertex) const {
    if (vertex == endpointA) {
      return endpointB;
    }
    if (vertex == endpointB) {
      return endpointA;
    }
    return nullptr;
  }

  Edge<T> *nextFor(const Vertex<T> *vertex) const {
    if (vertex == endpointA) {
      return nextFromA;
    }
    if (vertex == endpointB) {
      return nextFromB;
    }
    return nullptr;
  }

  Edge<T> *&nextRef(Vertex<T> *vertex) {
    if (vertex == endpointA) {
      return nextFromA;
    }
    if (vertex == endpointB) {
      return nextFromB;
    }
    throw std::invalid_argument("vertex is not endpoint of edge");
  }

  Vertex<T> *endpointA;
  Vertex<T> *endpointB;
  Edge<T> *nextFromA;
  Edge<T> *nextFromB;
};
