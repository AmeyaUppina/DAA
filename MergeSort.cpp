#include <iostream>
using namespace std;

void merge(int a[], int low, int high, int mid)
{
    int i=low;
    int j = mid+1;
    int k=low;
    int b[high+1];
    while(i<=mid && j<=high)
    {
        if(a[i] < a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    if(i>mid)
    {
        while(j <= high)
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    else if(j>high)
    {
        while(i <= mid)
        {
            b[k] = a[i];
            k++;
            i++;
        }
    }

    for(int n = low; n <= high; n++)
    {
        a[n] = b[n];
    }
}

void mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low+high)/2;
        mergesort(a, low, mid);
        mergesort(a, mid+1, high);
        merge(a, low, high, mid);
    }
}

int main() {
    int arr[10] = {12, 17,8,25, 20,7,22,15,19,2};
    mergesort(arr, 0, 9);
    for(int i=0; i<10; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

