#include <bits/stdc++.h>
using namespace std;

#define V 4
#define INF 99999

void printSolution(int dist[][V]);

void floydWarshall(int dist[][V])
{
    int i, j, k;
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    printSolution(dist);
}

void printSolution(int dist[][V])
{
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

int main()
{
    int graph[V][V] = { { 0, 3, INF, 7 },
                        { 8, 0, 2, INF },
                        { 5, INF, 0, 1 },
                        { 2, INF, INF, 0 } };

    floydWarshall(graph);
    return 0;
}
