// // Minimum cost spanning tree using Kruskal's algorithm

// #include <iostream>
// #include <vector>

// using namespace std;
// // class Graph {
//     // public:
//     // Graph(int n) {
//     //     adjMatrix = vector<pair<int, int> >(n, make_pair(n, INT_MAX));
//     // }

//     void addEdge(vector<pair<int, int> > adjMatrix[], int source, int sink, int wt) {
//         adjMatrix[source].push_back(make_pair(sink, wt));
//         adjMatrix[sink].push_back(make_pair(source, wt));
//     } 

//     void printGraph(vector<pair<int, int> > adjMatrix[]) {
//         cout << "Adjacency matrix of undirected graph:" << endl;
//         int n = sizeof(adjMatrix)/sizeof(adjMatrix[0]) - 1;
//         for (int i = 0; i < n; i++ ){
//             for (int j = 0; j < n; j++) {
//                     cout << adjMatrix[i] << " ";
//             }
//             cout << endl;
//         }
//     }
// // };

// int main () {
//     int n = 5;
//     // Graph g(n);
//     vector<pair<int, int> > adjMatrix[n];

//     addEdge(adjMatrix, 0, 1, 10);
//     addEdge(adjMatrix, 0, 4, 20);
//     addEdge(adjMatrix, 1, 2, 30);
//     addEdge(adjMatrix, 1, 3, 40);
//     addEdge(adjMatrix, 1, 4, 50);
//     addEdge(adjMatrix, 2, 3, 60);
//     addEdge(adjMatrix, 3, 4, 70);

//     printGraph(adjMatrix);
// }


// // Kruskal's Algo: 
// // 1. sort all edges by increasing weight
// // 2. add the smallest edge everytime, 
// // 3. check for cycle formation, if false, go ahead
// // 4. repeate until n-1 edges added

// #include <iostream>
// #include <vector>
// #include <map>
// #include <algorithm>

// using namespace std;

// struct Edge {
//     char source, sink; 
//     int weight;
// };

// class Graph {
//     vector<Edge > edges;
//     vector<char > vertices;

//     static bool compare(Edge a, Edge b) {
//         return a.weight < b.weight;
//     }

//     static map<char, vector<char> > makeAdjList(vector<Edge > edges) {
//         map<char, vector<char> > adjList;
//         for (Edge e : edges) {
//             adjList[e.source].push_back(e.sink);
//             adjList[e.sink].push_back(e.source);
//         }
//         return adjList;
//     }

//     bool checkIsCyclic(vector<Edge > mstEdges) {
//         map<char, vector<char> > adjList = makeAdjList(mstEdges);
//         map<char, bool> visited;
//         for (char v : vertices) {
//             visited[v] = false;
//         }
        
//         return false;
//     }
    
// };

// int main() {
//     int V = 5;
//     Graph g(V);
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm> // For sort
#include <map>

using namespace std;

struct Edge {
    char source, sink;
    int weight;
};

class Graph {
    int V; // Number of vertices
    vector<Edge> edges; // List of all edges
    vector<char> vertices; // List of all vertices

    static bool compare(Edge a, Edge b) {
        return a.weight < b.weight;
    }

    static map<char, vector<char> > makeAdjList(vector<Edge> edges) {
        map<char, vector<char> > adjList;
        for (Edge e : edges) {
            adjList[e.source].push_back(e.sink);
            adjList[e.sink].push_back(e.source);
        }
        return adjList;
    }

    bool isCyclicUtil(char v, map<char, bool>& visited, char parent, map<char, vector<char>>& adjList) {
        visited[v] = true;

        for (char neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                if (isCyclicUtil(neighbor, visited, v, adjList))
                    return true;
            } else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(char source, char sink, int weight) {
        edges.push_back({source, sink, weight});
        if (find(vertices.begin(), vertices.end(), source) == vertices.end()) {
            vertices.push_back(source);
        }
        if (find(vertices.begin(), vertices.end(), sink) == vertices.end()) {
            vertices.push_back(sink);
        }
    }

    bool checkIsCyclic(vector<Edge> mstEdges) {
        map<char, vector<char> > adjList = makeAdjList(mstEdges);
        map<char, bool> visited;
        for (char v : vertices) {
            visited[v] = false;
        }

        for (char v : vertices) {
            if (!visited[v]) {
                if (isCyclicUtil(v, visited, -1, adjList))
                    return true;
            }
        }
        return false;
    }

    void kruskalMST() {
        vector<Edge> result; // Store the resultant MST
        int e = 0; // Index for result[]
        int i = 0; // Index for sorted edges

        // Step 1: Sort all the edges in non-decreasing order of their weight
        sort(edges.begin(), edges.end(), compare);

        // Allocate memory for creating V subsets
        vector<int> parent(V);
        vector<int> rank(V, 0);

        // Create V subsets with single elements
        for (int v = 0; v < V; ++v)
            parent[v] = v;

        // Number of edges to be taken is equal to V-1
        while (e < V - 1 && i < edges.size()) {
            // Step 2: Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far.
            Edge next_edge = edges[i++];

            int x = find(parent, next_edge.source - 'A');
            int y = find(parent, next_edge.sink - 'A');

            // If including this edge does not cause a cycle, include it in the result
            // and increment the index of the result for the next edge
            if (x != y) {
                result.push_back(next_edge);
                unionSets(parent, rank, x, y);
                e++;
            }
        }

        // Print the contents of the resultant MST
        cout << "Following are the edges in the constructed MST\n";
        for (auto& edge : result)
            cout << edge.source << " -- " << edge.sink << " == " << edge.weight << endl;
    }

    // Find function for DSU
    int find(vector<int>& parent, int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]);
    }

    // Union function for DSU
    void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);

        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

int main() {
    int V = 5; // Number of vertices in graph
    Graph g(V);

    g.addEdge('A', 'B', 10);
    g.addEdge('A', 'C', 6);
    g.addEdge('A', 'D', 5);
    g.addEdge('B', 'D', 15);
    g.addEdge('C', 'D', 4);

    g.kruskalMST();

    return 0;
}