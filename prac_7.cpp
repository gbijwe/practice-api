// #import <iostream>
// #include <vector>

// using namespace std;

// class Solution {
//     vector<int> shortestPath(int n, vector<vector<int> >& edges, int src) {

//     }
// };

// int main () {
//     // Aim of this practical is to implement Dijkstra's algorithm
//     // Dijkstra's algorithm is used to find the shortest path between two nodes in a graph
//     // given weighted graph and a source node


// 	cout << "PRACTICAL 7";
// 	return 0;
// }
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> shortestPath(int n, vector<vector<int> >& edges, int src) {
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);
        dist[src] = 0;

        for (int i = 0; i < n; i++) {
            int u = -1;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }

            if (u == -1) break; // All reachable nodes are visited

            visited[u] = true;
            for (int j = 0; j < n; j++) {
                if (edges[u][j] != 0 && dist[u] != INT_MAX) {
                    dist[j] = min(dist[j], dist[u] + edges[u][j]);
                }
            }
        }
        return dist;
    }
};

int main() {
    Solution solution;

    int n = 5; // number of nodes
    vector<vector<int> > edges = {
        {0, 10, 0, 30, 100},
        {0, 0, 50, 0, 0},
        {0, 0, 0, 20, 10},
        {0, 0, 0, 0, 60},
        {0, 0, 0, 0, 0}
    };
    int src = 0; // starting node

    vector<int> distances = solution.shortestPath(n, edges, src);

    cout << "Shortest distances from node " << src << ": " << endl;
    for (int dist : distances) {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}
