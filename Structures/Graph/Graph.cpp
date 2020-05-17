#include "Graph.h"

void Graph::insert_path(int v1, int v2, float w) {
    vertices[v1].insert_path(v2, w);
}

void Graph::insert_vertex(int value) {
    int id = vertices.size();
    vertices.emplace_back(value, id);
}