#include <iostream>
using namespace std;

//int count = 0;

void subsetsum(int list[], int sum, int start, int target, int size, int subset[], int subsetSize, int *count)
{
    if (sum == target)
    {
        (*count)++;
        for (int i = 0; i < subsetSize; i++) 
        {
            cout << subset[i] << " ";
        }
        cout << endl;
    }

    if (start >= size)
    {
        return;
    }

    for (int i = start; i < size; i++)
    {
        if (sum + list[i] <= target)
        {
            subset[subsetSize] = list[i];
            subsetsum(list, sum + list[i], i + 1, target, size, subset, subsetSize + 1, count);
        }
    }
}

int main()
{
    int nums[] = {5, 10, 12, 13, 15, 18};
    int target = 30;
    int size = sizeof(nums) / sizeof(nums[0]);
    int subset[size];
    int count = 0;
    subsetsum(nums, 0, 0, target, size, subset, 0, &count);
    cout<<"Total possible subsets: "<<count<<"\n";
    return 0;
}
