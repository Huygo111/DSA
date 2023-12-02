#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjList;

    Graph(int v) : vertices(v), adjList(v) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int countParallelEdges() {
        int parallelEdges = 0;

        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < adjList[i].size(); ++j) {
                int neighbor = adjList[i][j];

                for (int k = j + 1; k < adjList[i].size(); ++k) {
                    if (neighbor == adjList[i][k]) {
                        parallelEdges++;
                    }
                }
            }
        }

        return parallelEdges;
    }
};

int main() {
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 0);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);

    int parallelEdges = graph.countParallelEdges();

    cout << parallelEdges << endl;

    return 0;
}
