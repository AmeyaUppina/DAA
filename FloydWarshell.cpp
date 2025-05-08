#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int num_vertices = 4;

    // Cost matrix representing the directed graph
    vector<vector<int>> cost_matrix = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    // Initialize the shortest path matrix with the cost matrix
    vector<vector<int>> shortest_path = cost_matrix;

    // Floyd-Warshall algorithm
    for (int k = 0; k < num_vertices; ++k) {
        for (int i = 0; i < num_vertices; ++i) {
            for (int j = 0; j < num_vertices; ++j) {
                if (shortest_path[i][k] != INF && shortest_path[k][j] != INF) {
                    shortest_path[i][j] = min(shortest_path[i][j], shortest_path[i][k] + shortest_path[k][j]);
                }
            }
        }
    }

    // Print the all-pairs shortest paths
    cout << "All-Pairs Shortest Paths:" << endl;
    for (int i = 0; i < num_vertices; ++i) {
        cout << "From vertex " << i << ":" << endl;
        for (int j = 0; j < num_vertices; ++j) {
            if (shortest_path[i][j] == INF) {
                cout << "  To vertex " << j << ": Infinity" << endl;
            } else {
                cout << "  To vertex " << j << ": " << shortest_path[i][j] << endl;
            }
        }
        cout << endl;
    }

    // Check for negative cycles
    cout << "Negative Cycles:" << endl;
    for (int i = 0; i < num_vertices; ++i) {
        if (shortest_path[i][i] < 0) {
            cout << "Negative cycle detected involving vertex " << i << endl;
        }
    }

    return 0;
}
