#include <iostream>
using namespace std;

void insort(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        int j = i-1;
        int x = a[i];
        while(j >= 0 && a[j] > x)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}

int main() {
    int arr[10] = {12, 17,8,25, 20,7,22,15,19,2};
    insort(arr, 10);
    for(int i : arr)
    {
        cout<<i<<" ";
    }
    return 0;
}
