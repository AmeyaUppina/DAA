#include <iostream>
#include <cstring>
using namespace std;

int lcs(char x[], char y[], int n, int m)
{
    int a[n+1][m+1];
    for(int j=0; j<=m; j++)
    {
        a[0][j] = 0;
    }
    for(int i=0; i<=n; i++)
    {
        a[i][0] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(x[i-1] == y[j-1])
            {
                a[i][j] = 1 + a[i-1][j-1];
            }
            else
            {
                a[i][j] = max(a[i][j-1], a[i-1][j]);
            }
        }
    }
    return a[n][m];
}

int lcs(string text1, string text2)     //if input is string instead of array
{
    int n = text1.length();
    int m = text2.length();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else { dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); }
        }
    }
    return dp[n][m];
}

int main() {
    char arr1[] = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
    char arr2[] = {'B', 'D', 'C', 'A', 'B', 'A'};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    int ans = lcs(arr1, arr2, n, m);
    cout<<ans<<endl;
    string s1 = "abcde";
    string s2 = "ace";
    ans = lcs(s1,s2);
    cout<<ans<<endl;
    return 0;
}
