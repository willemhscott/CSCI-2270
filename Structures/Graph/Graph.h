#include <vector>
using namespace std;

#ifndef CSCI_2270_GRAPH_H
#define CSCI_2270_GRAPH_H

struct Edge{
    int dest;
    float weight;

    Edge (int dest, float w) {
        this->dest = dest;
        this->weight = w;
    }
};

struct Vertex {
    int value;
    int id;
    vector<Edge> edges;

    Vertex(int val, int i) {
        edges = vector<Edge>();
        value = val;
        id = i;
    }

    void insert_path(int v2, float w) {
        edges.emplace_back(Edge(v2, w));
    }
};

class Graph {
    vector<Vertex> vertices;

    void insert_path(int v1, int v2, float w);
    void insert_vertex(int value);
};


#endif //CSCI_2270_GRAPH_H
