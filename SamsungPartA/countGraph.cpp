#include <iostream>
#include <cmath>

using namespace std;

// Hàm tính giai thừa
long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Hàm tính tổ hợp chập k của n (C(n, k))
long long combination(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Hàm tính số đồ thị vô hướng khác nhau
long long countGraphs(int V, int E, bool hasLoops) {
    int p;
    if (hasLoops) {
        p = combination(V + V - 1, V);
    } else {
        p = combination(V, 2);
    }

    if (E > p) {
        return 0;
    }

    long long result = combination(p, E);
    return result;
}

int main() {
    int V, E;
    cin >> V;
    cin >> E;

    long long result = countGraphs(V, E, 0);

    cout << result << endl;

    return 0;
}
