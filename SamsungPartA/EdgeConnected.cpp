#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Graph {
    int V;
    vector<set<int>> adj;

    Graph(int vertices) : V(vertices), adj(vertices) {}

    void addEdge(int u, int v) {
        adj[u].insert(v);
        adj[v].insert(u);
    }

    bool isEdgeConnected() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (!isEdgeConnectedDFS(i, -1, visited)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isEdgeConnectedDFS(int current, int parent, vector<bool>& visited) {
        visited[current] = true;

        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                if (!isEdgeConnectedDFS(neighbor, current, visited)) {
                    return false;
                }
            } else if (neighbor != parent) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    //g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    // Kiểm tra tính liên thông cạnh
    if (g.isEdgeConnected()) {
        cout << "edge-connected." << endl;
    } else {
        cout << "not edge-connected." << endl;
    }

    return 0;
}
