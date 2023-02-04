/**
 * Given a nums array of integers and a target. *
 * Find all the unique quadraplets such that a+b+c+d = target. *
**/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findQuads(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i=0; i<n; i++)
    {
        if(i==0 || nums[i]!=nums[i-1])
        {
            for(int j=i+1; j<n; j++)
            {
                if(j==i+1 || nums[j]!=nums[j-1])
                {
                    int left = j+1;
                    int right = n-1;

                    while(left < right)
                    {
                        if( (nums[left]+nums[right]) < (target-nums[i]-nums[j]))
                            left++;
                        else if( (nums[left]+nums[right]) > (target-nums[i]-nums[j]) )
                            right--;
                        else
                        {
                            vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
                            ans.push_back(temp);
                            left++;
                            right--;
                            while(left<right && nums[left]==nums[left-1])
                                left++;
                            while(left<right && nums[right]==nums[right+1])
                                right--;
                        }
                        
                    } 
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-2, -2, -1, -1, -1, 0, 0, 0, 0, 2, 2, 3};
    vector<vector<int>> V = findQuads(nums, 0);;
    
    for(auto i=V.begin(); i!=V.end(); i++)
    {
        for(auto j=(*i).begin(); j!=(*i).end(); j++)
            cout<<*j<<" ";
        cout<<endl;
    }
    return 0;
}