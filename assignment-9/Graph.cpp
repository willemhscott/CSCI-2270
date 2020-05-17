#include "Graph.hpp"

void Graph::addEdge(string v1, string v2, int num) {
    vertex *n1, *n2;
    for (int i = 0; i < (int) vertices.size(); i++) {
        vertex *v = vertices[i];
        if (v->name == v1) {
            n1 = v;
        } else if (v->name == v2) {
            n2 = v;
        }
    }
    adjVertex av1;
    adjVertex av2;
    av1.v = n2;
    av1.weight = num;
    av2.v = n1;
    av2.weight = num;
    n1->adj.push_back(av1);
    n2->adj.push_back(av2);
}

void DFTraversal(vertex *n) {
    n->visited = true;
    cout << n->name << " --> ";

    for (int x = 0; x < (int) n->adj.size(); x++) {
        if (!n->adj[x].v->visited) {
            n->adj[x].v->distance = n->distance + 1;
            DFTraversal(n->adj[x].v);
        }
    }
}

void Graph::depthFirstTraversal(string sourceVertex) {
    for (int i = 0; i < (int) vertices.size(); i++) {
        if (vertices[i]->name == sourceVertex) {
            DFTraversal(vertices[i]);
            break;
        }
    }
    cout << "Done" << endl;
}

void DijkstraTraverse(vertex *n) {
    n->visited = true;


    for (int x = 0; x < (int) n->adj.size(); x++) {
        adjVertex edge = n->adj[x];
        if (edge.v->distance > (n->distance + edge.weight)) {
            edge.v->distance = n->distance + edge.weight;
            edge.v->pred = n;
        }
        if (!n->adj[x].v->visited) {
            DijkstraTraverse(n->adj[x].v);
        }
    }
}

vertex* Graph::DijkstraAlgorithm(string start, string end) {
    vertex *s = NULL;
    vertex *e = NULL;

    for (int i = 0; i < (int) vertices.size(); i++) {
        vertices[i]->visited = false;
        vertices[i]->distance = 9999999;
        if (vertices[i]->name == start) {
            s = vertices[i];
        } else if (vertices[i]->name == end) {
            e = vertices[i];
        }
    }
    s->distance = 0;
    DijkstraTraverse(s);
    //cout << "Dijkstra's Shortest distance from " << start << " to " << end << ": " << e->distance << endl;

    return e;
}

void printPath(vertex *n) {
    if (n->pred != NULL) {
        printPath(n->pred);
    }
    cout << n->name << " ";
}

void Graph::shortestpath(string start, string end) {
    vertex *s = NULL;
    vertex *e = NULL;

    for (int i = 0; i < (int) vertices.size(); i++) {
        vertices[i]->visited = false;
        vertices[i]->distance = 9999999;
        if (vertices[i]->name == start) {
            s = vertices[i];
        } else if (vertices[i]->name == end) {
            e = vertices[i];
        }
    }
    s->distance = 0;
    DijkstraTraverse(s);
    //cout << "Dijkstra's Shortest distance from " << start << " to " << end << ": " << e->distance << endl;
    printPath(e);
    cout << endl;
}