#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Graph class using adjacency list representation
class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    // Constructor
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    // Function to add a directed edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Utility function for DFS traversal
    void dfs(int v, vector<bool>& visited, stack<int>& stk) {
        visited[v] = true;

        // Recursively visit all adjacent vertices
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, stk);
            }
        }

        // Push the current vertex to stack after all its neighbors are visited
        stk.push(v);
    }

    // Function to perform topological sorting using DFS
    void topologicalSort() {
        vector<bool> visited(V, false);
        stack<int> stk;

        // Perform DFS from each vertex that hasn't been visited
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, visited, stk);
            }
        }

        // Print the topological order (pop elements from stack)
        cout << "Topological Sort: ";
        while (!stk.empty()) {
            cout << stk.top() << " ";
            stk.pop();
        }
        cout << endl;
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add directed edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(4, 0);

    // Perform topological sorting
    g.topologicalSort();

    return 0;
}

