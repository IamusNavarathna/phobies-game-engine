#include "Graph.h"

Graph::Graph(const vector<Vector2f> &vertices)
{
  for (int i = 0; i < vertices.size(); i++) {
    add_vertex(vertices[i], this->adjacencyList);
  }
}

void Graph::addEdge(int vertex1, int vertex2) {
  float length = boost::numeric::ublas::norm_2(adjacencyList[vertex1] - adjacencyList[vertex1]);

  add_edge(vertex1, vertex2, length, this->adjacencyList);
  add_edge(vertex2, vertex1, length, this->adjacencyList);
}

ostream &operator<<(ostream &out, const Graph &graph) {
  pair<Graph::InternalGraphType::vertex_iterator,Graph::InternalGraphType::vertex_iterator>
    uit;

  for (uit = vertices(graph.adjacencyList); uit.first != uit.second; uit.first++) {
    out<<*(uit.first)<<" : [";

    pair<Graph::InternalGraphType::adjacency_iterator,Graph::InternalGraphType::adjacency_iterator>
      vit;

    for (vit = adjacent_vertices(*(uit.first), graph.adjacencyList); vit.first != vit.second; vit.first++) {
      out<<*(vit.first)<<", ";
    }
    out<<"]"<<endl;
  }
}
