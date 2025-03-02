#include <cstring>
#include <iostream>
using namespace std;

#define INF 9999999

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    int G[V][V];
    cout << "Enter the number of edges: ";
    cin >> E;
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            G[i][j] = 0;
        }
    }

    cout << "Enter the edges (u, v, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u][v] = w;
        G[v][u] = w; // since it's an undirected graph
    }

    int no_edge = 0;  // number of edges in MST
    int selected[V];  // to track selected vertices
    memset(selected, false, sizeof(selected));  // initially, no vertices are selected
    selected[0] = true;  // start with vertex 0

    int x, y;  // edge variables for row and column

    // print for edge and weight
    cout << "Edge   : Weight" << endl;

    while (no_edge < V - 1)
    {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++)
        {
            if (selected[i])  // vertex i is in the MST
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && G[i][j] != 0)  // vertex j is not in the MST, and there is an edge
                    {
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        // print the selected edge and its weight
        cout << x << " -> " << y << " : " << G[x][y] << endl;
        selected[y] = true;  // mark vertex y as selected
        no_edge++;  // increment the edge count
    }

    return 0;
}

