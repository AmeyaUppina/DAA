#include <iostream>
using namespace std;

#define INF 999999

int main() {
    int v = 7;    //total no. of nodes
    int cost[7][7] = {
            {0, 6, 5, 5, 0, 0, 0},
            {0, 0, 0, 0, -1, 0, 0},
            {0, -2, 0, 0, 1, 0, 0},
            {0, 0, -2, 0, 0, -1, 0},
            {0, 0, 0, 0, 0, 0, 3},
            {0, 0, 0, 0, 0, 0, 3},
            {0, 0, 0, 0, 0, 0, 0}
    };             //cost matrix initialization.

    int d[7] = {0, INF, INF, INF, INF, INF, INF}; //Source node distance is marked as 0, in this case node 0.

    for(int k=0; k<v; k++)
    {
        for(int i=0; i<v; i++)
        {
            for(int j=0; j<v; j++)
            {
                if(cost[i][j] != 0)
                {
                    if(d[i]+cost[i][j]<d[j])
                    {
                        d[j] = d[i]+cost[i][j];
                    }
                }
            }
        }
    }

    for(int i=0; i<v; i++)
    {
        cout<<d[i]<<" ";
    }

    return 0;
}

