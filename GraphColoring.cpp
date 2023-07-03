#include <iostream>
using namespace std;

bool isSafe(int k, int c, int G[][4], int x[], int n)
{
    for(int i=0; i<n; i++)
    {
        if(G[k][i] == 1 && c == x[i])
        {
            return false;
        }
    }
    return true;
}

void GC(int k, int m, int G[][4], int x[], int n, int *count)
{
    for(int c=1; c<=m; c++)
    {
        if(isSafe(k, c, G, x, n))
        {
            x[k] = c;
            if(k == n-1)
            {
                (*count)++;
                for(int i=0; i<n; i++)
                {
                    cout<<x[i]<<" ";
                }
                cout<<endl;
            }
            else
            {
                GC(k+1, m, G, x, n, count);
            }
        }
    }
}

int main()
{
    int G[][4] = {{0,1,0,1},{1,0,1,1},{0,1,0,1},{1,1,1,0}}; // adjacency matrix
    int x[] = {0,0,0,0};
    int n = sizeof(x)/sizeof x[0]; // no. of vertices
    int m = 3; // no. of colors
    int count = 0;
    GC(0, m, G, x, n, &count);
    cout<<"Total possible coloring options: "<<count<<endl;
    return 0;
}
