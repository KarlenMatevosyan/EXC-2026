#include <iostream>
using namespace std;

const int V = 5;

void DFS(int graph[5][5], int current) {
    static bool visited[5] = {false};
    visited[current] = true;
    cout << "Visited vertex: " << current << endl;

    for (int i = 0; i < 5; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            DFS(graph, i);
        }
    }
}

int main () {
    int graph[V][V] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    DFS(graph, 0);
    return 0;
}