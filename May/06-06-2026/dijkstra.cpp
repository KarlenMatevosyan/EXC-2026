#include <iostream>
#include <climits>
using namespace std;

const int V = 5;

int minDistance(int minDist[], bool shortPath[], int V){
    int min = INT_MAX;
    int min_index;
    for (int i = 0; i < V; i++){
        if (shortPath[i] == false && minDist[i] <= min){
            min = minDist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src){
    int minDist[V];
    bool shortPath[V];
    for (int i = 0; i < V; i++){
        minDist[i] = INT_MAX;    // Initialize
        shortPath[i] = false;
    }

    minDist[src] = 0;            // Distance from source to itself is always 0

    for (int k = 0; k < V; k++){
        int j = minDistance(minDist, shortPath, V);
        shortPath[j] = true;
        for (int i = 0; i < V; i++){
            if (!shortPath[i] && graph[j][i] && minDist[j] != INT_MAX && minDist[j] + graph[j][i] < minDist[i]){
                minDist[i] = minDist[j] + graph[j][i];
            }
        }
    }

    for (int i = 0; i < V; i++){
        cout << "Vertex: " << i << " | Distance from Source: " << minDist[i] << endl;
    }

}

int main() {
    int minDist[V];
    int graph[V][V] = {
        {0, 10, 0, 30, 100},   // i = from vertex 'i' to others
        {10, 0, 50, 0, 0},     // j = to vertex 'j' from others
        {0, 50, 0, 20, 10},    // 0 means no direct path between vertices
        {30, 0, 20, 0, 60},    // graph[i][j] = weight of edge from vertex 'i' to vertex 'j'
        {100, 0, 10, 60, 0}
    };
    int src = 0;
    dijkstra(graph, src);

    return 0;
}