#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <boost/graph/adjacency_list.hpp>
#include <vector>

#include "LinearAlgebra.h"

using namespace std;
using namespace boost;

/**
 * Adjacency list graph data structure to represent directed
 * metric graphs. 
 *
 * These graphs are intended to be used as path specifications 
 * for the character on screen, with vertices representing 
 * on-screen positions and there is an edge from point A to 
 * point B iff the character can go from A to B in a straight 
 * line.
 *
 * The graph is metric because each vertex is associated a
 * position 2d space, and the edges are weighted by Euclidean
 * distance between these 2 points. It is directed because we
 * may want to allow one-way edges - although this provides
 * utility methods to add edges both ways.
 *
 * This data structure relies on boost's adjacency_list
 * data type.
 */
class Graph {
 public:
  /**
   * Internal graph data type.
   */
  typedef
    adjacency_list<listS, vecS, directedS, Vector2f, float>
    InternalGraphType;

 private:
  InternalGraphType adjacencyList;

 public:
  /**
   * Initializes the graph with isolated vertices at specific
   * positions.
   *
   * @param vertices vertices positions to use for the graph. 
   */
  Graph(const vector<Vector2f> &vertices);

  /**
   * Adds an undirected edge between vertex1 and vertex2.
   * This edge allows the character to go between the two
   * vertices in both directions. This actually adds 2 edges
   * to the adjacency list data structure.
   *
   * @param vertex1 index of the first vertex.
   * @param vertex2 index of the second vertex.
   */
  void addEdge(int vertex1, int vertex2);

  /**
   * Outputs a string representation of the graph adjacency
   * list into a stream.
   *
   * @param out output stream to modify.
   * @return the modified output stream.
   */
  friend ostream &operator<<(ostream &out, const Graph &graph);
};

#endif
