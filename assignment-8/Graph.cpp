#include "Graph.hpp"
#include <queue>

void Graph::addVertex(string name) {
    vertex *v = new vertex();
    v->name = name;
    vertices.push_back(v);
}

void Graph::addEdge(string v1, string v2) {
    vertex *n1, *n2;
    for (vertex *v : vertices) {
        if (v->name == v1) {
            n1 = v;
        } else if (v->name == v2) {
            n2 = v;
        }
    }
    adjVertex av1;
    adjVertex av2;
    av1.v = n2;
    av2.v = n1;
    n1->adj.push_back(av1);
    n2->adj.push_back(av2);
}

void Graph::displayEdges() {
    for (int i = 0; i < (int) vertices.size(); i++) {
        vertex *v = vertices[i];
        cout << v->name << " --> ";
        for (int j = 0; j < (int) v->adj.size(); j++) {
            adjVertex av = v->adj[j];
            cout << av.v->name << " ";
        }
        cout << endl;
    }
}


void Graph::breadthFirstTraverse(string sourceVertex) {
    cout << "Starting vertex (root): " << sourceVertex << "-> ";
    vertex *root;
    for (int i = 0; i < (int) vertices.size(); i++) {
        if (vertices[i]->name == sourceVertex) {
            root = vertices[i];
            break;
        }
    }

    root->visited = true;

    // Use the queue to keep track of visited vertices
    queue<vertex *> q;

    // Enqueue the source vertex
    q.push(root);

    vertex *n;

    // standard BFS
    root->distance = 0;
    while (!q.empty()) {

        n = q.front();
        q.pop();
        if (n != root)
            cout << n->name << "(" << n->distance << ")" << " ";

        // go to all the adjacent vertices of n
        for (int x = 0; x < (int) n->adj.size(); x++) {
            // If a adjacent has not been visited, then mark it visited and enqueue it
            // Update the distance of the adjacent vertices along the way
            // Stop when you reach the destination vertex and return the needful
            vertex *v = n->adj[x].v;
            if (!v->visited) {
                q.push(v);
                v->visited = true;
                v->distance = n->distance + 1;
            }
        }

    }
}

void plainTraverse(vertex *root) {
    root->visited = true;

    // Use the queue to keep track of visited vertices
    queue<vertex *> q;

    // Enqueue the source vertex
    q.push(root);

    vertex *n;

    // standard BFS
    root->distance = 0;
    while (!q.empty()) {

        n = q.front();
        q.pop();

        // go to all the adjacent vertices of n
        for (int x = 0; x < (int) n->adj.size(); x++) {
            // If a adjacent has not been visited, then mark it visited and enqueue it
            // Update the distance of the adjacent vertices along the way
            // Stop when you reach the destination vertex and return the needful
            vertex *v = n->adj[x].v;
            if (!v->visited) {
                q.push(v);
                v->visited = true;
                v->distance = n->distance + 1;
            }
        }
    }
}

int Graph::getConnectedComponents() {
    int count = 0;
    for (int i = 0; i < (int) vertices.size(); i++) {
        vertices[i]->visited = false;
        vertices[i]->color = "";
    }

    for (int i = 0; i < (int) vertices.size(); i++) {
        if (!vertices[i]->visited) {
            count++;
            plainTraverse(vertices[i]);
        }
    }
    return count;
}

bool Graph::checkBipartite() {
    for (int i = 0; i < (int) vertices.size(); i++) {
        vertices[i]->visited = false;
        vertices[i]->color = "";
    }

    for (int i = 0; i < (int) vertices.size(); i++) {
        if (!vertices[i]->visited) {
            vertex *root = vertices[i];
            root->visited = true;
            root->color = "red";

            // Use the queue to keep track of visited vertices
            queue<vertex *> q;

            // Enqueue the source vertex
            q.push(root);

            vertex *n;

            // standard BFS
            root->distance = 0;
            while (!q.empty()) {

                n = q.front();
                q.pop();
                //n->visited = true;

                // go to all the adjacent vertices of n
                for (int x = 0; x < (int) n->adj.size(); x++) {
                    // If a adjacent has not been visited, then mark it visited and enqueue it
                    // Update the distance of the adjacent vertices along the way
                    // Stop when you reach the destination vertex and return the needful
                    vertex *v = n->adj[x].v;
                    if (!v->visited) {
                        q.push(v);
                        v->visited = true;
                    }

                    if (v->color == "blue" && n->color == "blue") {
                        //cout << v->name << n->name << v->color << n ->color << endl;
                        return false;
                    } else if (v->color == "red" && n->color == "red") {
                        //cout << v->name << n->name << v->color << n ->color << endl;
                        return false;
                    } else if (v->color == "") {
                        //cout << v->name << n->name << v->color << n ->color << endl;
                        //cout << (n->color == "red") << endl;
                        if (n->color == "red") {
                            v->color = "blue";
                        } else  if (n->color == "red"){
                            v->color = "red";
                        }
                    }
                }
            }
        }
    }
    return true;
}