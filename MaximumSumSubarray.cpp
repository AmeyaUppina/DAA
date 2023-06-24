#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

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

int m(vector<int> &a, int low, int high)
{
    if(low == high)
    {
        return a[low];
    }
    else
    {
        int mid = floor((low+high)/2);
        int ls = m(a, low, mid);
        int rs = m(a, mid+1, high);
        int cs = csa(a, low, mid, high);
        int mx = max(cs,max(ls, rs));
        return mx;
    }
}
int maxSubArray(vector<int>& nums) {
    int low = 0;
    int high = nums.size()-1;
    int ans = m(nums, low, high);
    return ans;
}

int main() {
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(arr);
    return 0;
}
