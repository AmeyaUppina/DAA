#include <iostream>
using namespace std;

int merge(int a[], int low, int high, int mid)
{
    int inv_count = 0;
    int i = low;
    int j = mid + 1;
    int k = low;
    int b[high + 1];

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
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
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }

    for (int n = low; n <= high; n++)
    {
        a[n] = b[n];
    }

    return inv_count;
}

int mergesort(int a[], int low, int high)
{
    int inv_count = 0;

    if (low < high)
    {
        int mid = (low + high) / 2;
        inv_count += mergesort(a, low, mid);
        inv_count += mergesort(a, mid + 1, high);
        inv_count += merge(a, low, high, mid);
    }

    return inv_count;
}

int main()
{
    int arr[] = {1,20,6,4,5};
    int ans = mergesort(arr, 0, 4);
    cout << "Inversion count: " << ans << endl;

    return 0;
}
