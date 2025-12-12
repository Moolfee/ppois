#pragma once

#include <utility>

template <typename T> struct Edge;

// Вершина графа, хранит значение и указатель на первое инцидентное ребро.
template <typename T> struct Vertex {
  explicit Vertex(T value) : data(std::move(value)) {}

  T data;
  Edge<T> *firstEdge = nullptr;
};
