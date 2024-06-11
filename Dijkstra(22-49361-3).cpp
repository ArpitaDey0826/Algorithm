#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

// Graph class using adjacency list representation
class Graph {
private:
    int V; // Number of vertices
    vector<vector<Edge>> adj; // Adjacency list

public:
    // Constructor
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    // Function to add a directed edge to the graph
    void addEdge(int u, int v, int weight) {
        adj[u].push_back(Edge(v, weight));
    }

    // Dijkstra's algorithm to find shortest paths from a single source
    void dijkstra(int source) {
        // Min-heap priority queue to store (distance, vertex) pairs
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Vector to store minimum distances from source
        vector<int> dist(V, numeric_limits<int>::max());

        // Initialize distance to source vertex
        dist[source] = 0;
        pq.push({0, source});

        // Process vertices using priority queue
        while (!pq.empty()) {
            int u = pq.top().second;
            int currentDist = pq.top().first;
            pq.pop();

            // Skip processing if we've found a shorter path to u already
            if (currentDist > dist[u]) {
                continue;
            }

            // Explore neighbors of vertex u
            for (const Edge& edge : adj[u]) {
                int v = edge.to;
                int weight = edge.weight;

                // Calculate new distance through u to v
                int newDist = dist[u] + weight;

                // Update distance and push to priority queue if a shorter path is found
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }

        // Print shortest distances from source vertex to all vertices
        cout << "Shortest distances from source " << source << " to all vertices:" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ": " << dist[i] << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add directed weighted edges to the graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);

    // Perform Dijkstra's algorithm from source vertex 0
    g.dijkstra(0);

    return 0;
}
