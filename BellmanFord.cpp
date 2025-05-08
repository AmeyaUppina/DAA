#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int num_vertices = 5;

    // Cost matrix representing the directed graph
    vector<vector<int>> cost_matrix = {
        {0, -1, INF, INF, INF},
        {INF, 0, 3, 2, 2},
        {INF, INF, 0, INF, INF},
        {INF, 1, 5, 0, INF},
        {INF, INF, INF, -3, 0}
    };

    int source_node = 0;
    vector<int> distance(num_vertices, INF);
    distance[source_node] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 1; i <= num_vertices - 1; ++i) {
        for (int u = 0; u < num_vertices; ++u) {
            for (int v = 0; v < num_vertices; ++v) {
                if (cost_matrix[u][v] != INF && distance[u] != INF) {
                    distance[v] = min(distance[u] + cost_matrix[u][v], distance[v]);
                }
            }
        }
    }

    // Check for negative cycles, if after v-1 iterations, the cost can still be reduced, there is a negative cycle.
    for (int u = 0; u < num_vertices; ++u) {
        for (int v = 0; v < num_vertices; ++v) {
            if (cost_matrix[u][v] != INF && distance[u] != INF && distance[u] + cost_matrix[u][v] < distance[v]) {
                cout << "Graph contains a negative cycle" << endl;
                return 1;
            }
        }
    }

    cout << "Shortest distances from source node " << source_node << ":" << endl;
    for (int i = 0; i < num_vertices; ++i) {
        cout << "To node " << i << ": ";
        if (distance[i] == INF) {
            cout << "Infinity" << endl;
        } else {
            cout << distance[i] << endl;
        }
    }

    return 0;
}
