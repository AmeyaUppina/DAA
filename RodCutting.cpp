#include <iostream>
#include <algorithm>
using namespace std;

int cutRod(int price[], int n, int m)
{
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (i <= j)
                dp[i][j] = max(price[i - 1] + dp[i][j - i], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][m];
}

int main()
{
    int price[] = {2, 5, 7, 8};
    int size = sizeof(price) / sizeof(price[0]);
    int rodLength = 5; // Total length of rod

    cout << "Maximum Obtainable Value is " << cutRod(price, size, rodLength) << endl;
    return 0;
}
