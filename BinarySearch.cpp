#include<iostream>
using namespace std;

void bin(int a[], int low, int high, int key)
{
    if(low == high)
    {
        if(key == a[low])
        {
            cout<<"Element Found!";
            cout<<low;
        }
        else {
            cout<<"Element Not Found :(";
        }
    }
    else
    {
        int mid  = (low+high)/2;
        if(key == a[mid])
        {
            cout<<"Element Found!";
            cout<<mid;
        }
        else if(key < a[mid])
        {
            bin(a, low, mid-1, key);
        }
        else if(key > a[mid])
        {
            bin(a, mid+1, high, key);
        }
    }
}

int main()
{
    int arr[10] = {-1, 0,3,5, 9,12,};
    bin(arr, 0, 6, 9);
    return 0;
}
