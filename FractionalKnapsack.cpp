#include <iostream>
using namespace std;

void sort(float a[], float b[], float c[], int n)
{
    for(int i=1; i<n; i++)
    {
        int j = i-1;
        float x = a[i];
        float y = b[i];
        float z = c[i];
        while(j>=0 && a[j]<x)
        {
            a[j+1] = a[j];
            b[j+1] = b[j];
            c[j+1] = c[j];
            j--;
        }
        a[j+1] = x;
        b[j+1] = y;
        c[j+1] = z;
    }
}

int main() {

    int n = 7;
    float m = 15;
    float pr = 0;
    float w[7] = {2, 3, 5, 7,1, 4, 1};
    float p[7] = {10, 5, 15, 7, 6, 18, 3};
    float pw[7];
    for(int i = 0; i<n; i++)
    {
        pw[i] = p[i]/w[i];
    }
    sort(pw, p, w, 7);
    for(int i=0; i<n; i++)
    {
        if(m>0 && w[i]<m)
        {
            m -= w[i];
            pr += p[i];
        }
        else if(m>0)
        {
            pr += (m/w[i])*p[i];
            m=0;
        }
        else
        {
            break;
        }
    }
    cout<<"Max Profit: "<<pr<<endl;
    return 0;
}
