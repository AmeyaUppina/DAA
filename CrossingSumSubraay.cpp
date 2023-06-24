#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

#define INT_MIN -999999

int csa(vector<int> &a, int low, int mid, int high)
{
    int ls = INT_MIN;
    int rs = INT_MIN;
    int sum1 = 0, sum2=0;
    for(int i=mid; i>=low; i--)
    {
        sum1 += a[i];
        if(sum1 > ls)
            ls = sum1;
    }
    for(int j=mid+1; j<=high; j++)
    {
        sum2 += a[j];
        if(sum2 > rs)
            rs = sum2;
    }
    int ret = ls+rs;
    return ret;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int low = 0;
    int high = nums.size()-1;
    int mid = (low+high)/2;
    cout<<csa(nums, low, mid, high);
    return 0;
}
