#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

bool isBipartite(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> colors(n, 0);  // 0: Chưa tô màu, 1: Màu 1, -1: Màu 2

    for (int i = 0; i < n; ++i) {
        if (colors[i] == 0) {
            queue<int> q;
            q.push(i);
            colors[i] = 1;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int neighbor : graph[curr]) {
                    if (colors[neighbor] == 0) {
                        colors[neighbor] = -colors[curr];
                        q.push(neighbor);
                    } else if (colors[neighbor] == colors[curr]) {
                        return false;  // Có cạnh nối giữa các đỉnh cùng màu
                    }
                }
            }
        }
    }

    return true;  // Không có cạnh nối giữa các đỉnh cùng màu
}

bool containsOddCycle(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> colors(n, 0);  // 0: Chưa tô màu, 1: Màu 1, -1: Màu 2

    for (int i = 0; i < n; ++i) {
        if (colors[i] == 0) {
            queue<int> q;
            q.push(i);
            colors[i] = 1;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int neighbor : graph[curr]) {
                    if (colors[neighbor] == 0) {
                        colors[neighbor] = -colors[curr];
                        q.push(neighbor);
                    } else if (colors[neighbor] == colors[curr]) {
                        return true;  // Có chu trình độ dài lẻ
                    }
                }
            }
        }
    }

    return false;  // Không có chu trình độ dài lẻ
}

int main() {
    vector<vector<int>> graph = {{1, 3},{0, 2},{1, 3},{0, 2},{3, 4},{4, 3}};

    if (isBipartite(graph)) {
        cout << "bipartite." << endl;
    } else {
        cout << "not bipartite." << endl;
    }

    if (containsOddCycle(graph)) {
        cout << "contains an odd cycle." << endl;
    } else {
        cout << "not contain an odd cycle." << endl;
    }

    return 0;
}
