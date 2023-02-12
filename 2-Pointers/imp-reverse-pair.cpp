/**
 * Given an array nums of integers, return the the number of pairs of indices (i, j)
 * such that i<j and nums[i]>2*nums[j]
**/

#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> &nums, int low, int mid, int high)
{
    //Calculating the number of such pairs
    int currCount = 0;
    int j = mid+1;
    for(int i=low; i<=mid; i++)
    {
        while(j<=high && nums[i]>2*nums[j])
            j++;
        currCount += j-(mid+1);
    }

    //sorting the left and right halves
    vector<int> temp;
    int leftStart = low, rightStart = mid+1;
    while(leftStart<=mid && rightStart<=high)
    {
        if(nums[rightStart] < nums[leftStart])
            temp.push_back(nums[rightStart++]);
        else
            temp.push_back(nums[leftStart++]);
    }
    while(leftStart<=mid)
        temp.push_back(nums[leftStart++]);
    while(rightStart<=high)
        temp.push_back(nums[rightStart++]);

    //merging
    for(int i=low; i<=high; i++)
        nums[i] = temp[i-low];

    return currCount;
}

int mergeSort(vector<int> &nums, int low, int high)
{
    if(low>=high)
        return 0;
    int ans = 0;
    int mid = (low+high)/2;
    ans += mergeSort(nums, low, mid);
    ans += mergeSort(nums, mid+1, high);
    ans += merge(nums, low, mid, high);
    return ans;
}

int main()
{
    vector<int> nums = {1,3,2,3,1};
    cout<<mergeSort(nums, 0, nums.size()-1)<<endl;
    return 0;
}