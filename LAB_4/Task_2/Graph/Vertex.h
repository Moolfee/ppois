#pragma once

#include <utility>

template <typename T> struct Edge;

template <typename T> struct Vertex {
  explicit Vertex(T value) : data(std::move(value)) {}

  T data;
  Edge<T> *firstEdge = nullptr;
};
