#include "Graph.h"
#include <gtest/gtest.h>
#include <vector>

TEST(Graph, AddsVerticesAndEdges) {
  Graph<int> graph;
  auto v1 = graph.addVertex(1);
  auto v2 = graph.addVertex(2);
  auto v3 = graph.addVertex(3);

  EXPECT_EQ(graph.vertexCount(), 3u);
  EXPECT_TRUE(graph.containsVertex(v1));
  EXPECT_TRUE(!graph.containsEdge(v1, v2));

  auto e1 = graph.addEdge(v1, v2);
  auto e2 = graph.addEdge(v2, v3);
  EXPECT_EQ(graph.edgeCount(), 2u);
  EXPECT_TRUE(graph.containsEdge(v1, v2));
  EXPECT_TRUE(graph.containsEdge(v2, v1));
  EXPECT_TRUE(e1 != nullptr);
  EXPECT_TRUE(e2 != nullptr);
}

TEST(Graph, IteratesAdjacentVerticesForward) {
  Graph<char> graph;
  auto a = graph.addVertex('A');
  auto b = graph.addVertex('B');
  auto c = graph.addVertex('C');
  graph.addEdge(a, b);
  graph.addEdge(a, c);

  std::vector<char> neighbours;
  for (auto it = graph.adjacentBegin(a); it != graph.adjacentEnd(a); ++it) {
    neighbours.push_back((*it)->data);
  }
  EXPECT_EQ(neighbours.size(), 2u);
  // Порядок определён вставкой в список инцидентности (последний addEdge идёт первым).
  EXPECT_EQ(neighbours[0], 'C');
  EXPECT_EQ(neighbours[1], 'B');
}

TEST(Graph, RemovesVertexAndIncidentEdges) {
  Graph<int> graph;
  auto v1 = graph.addVertex(10);
  auto v2 = graph.addVertex(20);
  auto v3 = graph.addVertex(30);
  graph.addEdge(v1, v2);
  graph.addEdge(v2, v3);
  EXPECT_EQ(graph.edgeCount(), 2u);
  EXPECT_TRUE(graph.removeVertex(v2));
  EXPECT_EQ(graph.vertexCount(), 2u);
  EXPECT_EQ(graph.edgeCount(), 0u);
  EXPECT_TRUE(!graph.containsVertex(v2));
}

TEST(Graph, IncidentEdgeReverseIteration) {
  Graph<int> graph;
  auto a = graph.addVertex(1);
  auto b = graph.addVertex(2);
  auto c = graph.addVertex(3);
  graph.addEdge(a, b);
  graph.addEdge(a, c);

  std::vector<int> values;
  for (auto it = graph.incidentEdgesRBegin(a);
       it != graph.incidentEdgesREnd(a); ++it) {
    values.push_back((*it)->other(a)->data);
  }
  EXPECT_EQ(values.size(), 2u);
  EXPECT_EQ(values[0], 2);
  EXPECT_EQ(values[1], 3);
}
