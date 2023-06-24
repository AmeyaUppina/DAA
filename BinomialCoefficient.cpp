#include <iostream>
using namespace std;

int coeff(int n, int k)     //Memoization method. i.e.recursion
{
    if(k == 0 || n == k)
    {
        return 1;
    }
    else
    {
        return (coeff(n-1,k-1)+coeff(n-1,k));
    }
}

int main() {
    int n = 25, k=14;         //nCk
    int arr[n+1][k+1];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j==0 || i==j)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
    }
    cout<<arr[n-1][k-1]<<endl;
    int ans = coeff(n,k);
    cout<<ans<<endl;
    return 0;
}
