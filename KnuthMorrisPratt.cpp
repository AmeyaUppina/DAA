#include <bits/stdc++.h>
using namespace std;

void computeLPS(char* pat, int M, int* lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            lps[i] = len+1;
            len++;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* pat, char* txt)
{
    int M = (int)strlen(pat);
    int N = (int)strlen(txt);
    int lps[M];
    computeLPS(pat, M, lps);

    int i = 0;
    int j = 0;
    int found = 0;
    while(i<N)
    {
        if(txt[i] == pat[j])
        {
            i++;
            j++;
            if(j==M)
            {
                found=1;
                break;
            }
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
                i++;
        }
    }
    if(found == 1)
    {
        cout<<"Substring match found."<<endl;
    }
    else
    {
        cout<<"Substring match not found."<<endl;
    }
}

int main()
{
    char txt[] = "ABCDABCDABCY";
    char pat[] = "ABCY";
    KMPSearch(pat, txt);
    return 0;
}
