#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

void search(char pat[], char txt[])
{
    int m = strlen(pat);
    int n = strlen(txt);
    int p = 0, q = 11, t = 0, h, d = 256, flag = 0;
    h = (int)(pow(d, m - 1)) % q;

    for (int i = 0; i < m; i++)
    {
        p = ((p * d) + pat[i]) % q;
        t = ((t * d) + txt[i]) % q;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (p == t) {
            for (int j = 0; j < m; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "Substring match found." << endl;
                return;
            }
        }
        if (i < n - m)
        {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }
    cout << "Substring match not found." << endl;
}

int main()
{
    char txt[] = "ABEABDABF";
    char pat[] = "ABD";
    search(pat, txt);
    return 0;
}
