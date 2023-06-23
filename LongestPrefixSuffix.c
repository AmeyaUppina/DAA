#include <bits/stdc++.h>
using namespace std;

void largest_prefix_suffix(char c[], int n)
{
    int len=0, i=1;
    int lps[n];
    while(i<n)
    {
        if(c[i] == c[len])
        {
            lps[i] = len+1;
            len++;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    int max = INT_MIN;
    for(i=0; i<n; i++)
    {
        if(max < lps[i])
            max = lps[i];
    }
    cout<<max;
}

int main()
{
    char p[] = {'a','a','b','a','a','a','c'};
    int n = sizeof(p)/sizeof(p[0]);
    largest_prefix_suffix(p, n);
    return 0;
}
