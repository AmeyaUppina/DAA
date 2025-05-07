#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int num_nodes = 4;
    int start_node = 0;

    // Cost matrix representing the graph
    vector<vector<int>> cost_matrix = {
        {0, 2, 4, INF},
        {INF, 0, 1, 4},
        {INF, INF, 0, 2},
        {INF, INF, INF, 0}
    };

    vector<int> distance(num_nodes, INF);
    distance[start_node] = 0;

    vector<bool> visited(num_nodes, false);

    for (int count = 0; count < num_nodes - 1; ++count) {
        // Find the unvisited node with the smallest distance
        int min_distance = INF;
        int current_node = -1;

        for (int i = 0; i < num_nodes; ++i) {
            if (!visited[i] && distance[i] < min_distance) {
                min_distance = distance[i];
                current_node = i;
            }
        }

        // If no unvisited node with a finite distance is found, break
        if (current_node == -1) {
            break;
        }

        // Mark the current node as visited
        visited[current_node] = true;

        // Relax the neighbors of the current node
        for (int neighbor_node = 0; neighbor_node < num_nodes; ++neighbor_node) {
            if (!visited[neighbor_node] && cost_matrix[current_node][neighbor_node] > 0 && cost_matrix[current_node][neighbor_node] < INF) {
                int weight = cost_matrix[current_node][neighbor_node];
                if (distance[current_node] + weight < distance[neighbor_node]) {
                    distance[neighbor_node] = distance[current_node] + weight;
                }
            }
        }
    }

    cout << "Shortest distances from node " << start_node << ":" << endl;
    for (int i = 0; i < num_nodes; ++i) {
        cout << "To node " << i << ": ";
        if (distance[i] == INF) {
            cout << "Infinity" << endl;
        } else {
            cout << distance[i] << endl;
        }
    }

    return 0;
}
