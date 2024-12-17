#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

void bellmanFord(int graph[5][5], int source) {
    int V = 5; 
    vector<int> distance(V, INT_MAX); 
    distance[source] = 0; 

    // Relax edges V-1 times
    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                if (graph[u][v] != 0) {
                    if (distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v]) {
                        distance[v] = distance[u] + graph[u][v]; 
                    }
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] != 0) {
                if (distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v]) {
                    cout << "Graph contains negative weight cycle" << endl;
                    return;
                }
            }
        }
    }

    cout << "Vertex Distance from Source (" << source << "):" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": " << (distance[i] == INT_MAX ? "INF" : to_string(distance[i])) << endl;
    }
}

int main() {
    // Graph represented as an adjacency matrix
    int graph[5][5] = {
        {0, 6, 0, 7, 0},  
        {0, 0, 5, 8, -4}, 
        {0, -2, 0, 0, 0}, 
        {0, 0, -3, 0, 9}, 
        {2, 0, 7, 0, 0}   
    };

    int source = 0;
    bellmanFord(graph, source);

    return 0;
}
