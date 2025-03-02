#include <iostream>
#include <climits>
using namespace std;

class Kruskal {
private:
    int visited[10] = {0};  // Array to keep track of visited vertices

public:
    void kruskal(int w[10][10], int n) {
        int min, sum = 0, ne = 0;
        int u, v, a, b;

        // Keep looping until we add (n-1) edges to the MST
        while (ne < n - 1) {
            min = 999;  // Initialize the minimum value
            // Find the minimum edge
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (w[i][j] < min) {
                        min = w[i][j];
                        u = a = i;
                        v = b = j;
                    }
                }
            }

            // Check if the nodes are already visited
            while (visited[u])
                u = visited[u];
            while (visited[v])
                v = visited[v];

            // If nodes u and v are not in the same set, include the edge in MST
            if (u != v) {
                ne++;
                sum += min;
                cout << "\nEdge (" << a << " , " << b << ") --> " << min;
                visited[v] = u;  // Union the sets
            }

            // Mark the edge as visited (remove it from further consideration)
            w[a][b] = w[b][a] = 999;
        }

        // Output the total weight of the MST
        cout << "\nCost of minimum spanning tree : " << sum << endl;
    }
};

int main() {
    int w[10][10], n;

    // Create Kruskal object to call kruskal function
    Kruskal graph;

    cout << "\nProgram to implement Kruskal's Algorithm : \n";
    cout << "\nEnter no. of vertices : ";
    cin >> n;

    cout << "\nEnter the adjacency matrix : \n";
    // Take the adjacency matrix as input
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> w[i][j];
        }
    }

    // Replace 0s with a large value to signify no edge
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (w[i][j] == 0)
                w[i][j] = 999;
        }
    }

    // Call Kruskal's algorithm to find MST
    graph.kruskal(w, n);

    return 0;
}

