#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Infinity value for unreachable paths

// Function to perform Floyd-Warshall algorithm for all-pairs shortest paths
void floydWarshall(vector<vector<int>>& dist, int V) {
    // Initialize distance matrix with given distances or INF for unreachable paths
    // dist[i][j] will represent the shortest distance from vertex i to vertex j
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (i == j) {
                dist[i][j] = 0; // Distance from a vertex to itself is 0
            } else {
                dist[i][j] = INF; // Initialize other distances to INF
            }
        }
    }

    // Update distance matrix based on direct edges
    // Assume direct edges are given as inputs
    // For example, dist[u][v] = weight if there is a direct edge from u to v with weight 'weight'
    // Adjust the input based on your actual use case or graph representation

    // Perform Floyd-Warshall algorithm to find shortest paths
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                // If vertex k is an intermediate vertex that improves the path from i to j
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    const int V = 5; // Number of vertices in the graph
    vector<vector<int>> dist(V, vector<int>(V)); // Distance matrix

    // Initialize the input graph with direct edge distances
    // For simplicity, assume direct edge weights are given
    // Adjust based on your actual use case or graph representation
    dist[0][1] = 3;
    dist[0][2] = 8;
    dist[1][2] = 1;
    dist[1][3] = 4;
    dist[2][4] = 5;
    dist[3][2] = 2;
    dist[3][4] = 7;
    dist[4][3] = 9;

    // Perform Floyd-Warshall algorithm to find all-pairs shortest paths
    floydWarshall(dist, V);

    // Output the shortest path distances between all pairs of vertices
    cout << "All-pairs shortest path distances:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
