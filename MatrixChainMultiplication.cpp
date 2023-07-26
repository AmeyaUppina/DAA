#include <bits/stdc++.h>
using namespace std;

int MCM(int p[], int n)
{
    int m[n][n];

    int i, j, k, d, q;
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (d = 1; d <= n-1; d++)
    {
        for (i = 1; i <= n - d; i++)
        {
            j = i + d;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j]
                    + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}

int main()
{
    int arr[] = { 5, 4, 6, 2, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of multiplications is " << MCM(arr, size);
    return 0;
}

