#include <iostream>
using namespace std;

int main() {
    int n=4, m=8;
    int p[] = {1,2,5,6};
    int w[] = {2,3,4,5};
    int v[n+1][m+1];
    for(int i=0; i<=m; i++)
    {
        v[0][i] = 0;
    }
    for(int i=0; i<=n; i++)
    {
        v[i][0] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(j >= w[i-1])
            {
                v[i][j] = max(v[i-1][j-1], v[i-1][j-w[i-1]]+p[i-1]);
            }
            else
            {
                v[i][j] = v[i-1][j-1];
            }
        }
    }
    cout<<"Max Profit: "<<v[n][m]<<endl;
    return 0;
}
