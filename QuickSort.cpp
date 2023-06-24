#include <iostream>
#include<vector>

using namespace std;

int partition(int a[], int low, int high)
{
    int pivot = low;
    int i = low;
    int j = high + 1;
     do {
        do {
            i++;
        } while (a[i] < a[pivot] && i<= high);
        do {
            j--;
        } while (a[j] > a[pivot] && j >= low);
        if (i < j) {
            swap(a[i], a[j]);
        }
    } while (i<j);
    swap(a[pivot], a[j]);
    cout<<j<<endl;
    return j;
}

void quicksort(int a[], int low, int high)
{
    if (low < high) {
        int j = partition(a, low, high);
        quicksort(a, low, j);
        quicksort(a, j + 1, high);
    }
}

int main() {
    int arr[] = {7,2,3,8,9,1};
    quicksort(arr, 0, 5);
    for(int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
        }
    return 0;
}
