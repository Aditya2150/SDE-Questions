// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            continue;
            int low=i+1,high=n-1;
            while(low<high)
            {
                if(nums[i]+nums[low]+nums[high]==0)
                {
                    v.push_back(vector<int>{nums[i],nums[low],nums[high]});
                    while(low<n-1 && nums[low]==nums[low+1])low++;
                    while(high>0 && nums[high]==nums[high-1])high--;
                    low++,high--;
                }
                else if(nums[low]+nums[high]+nums[i]>0)
                    high--;
                else
                    low++;
            }
        }
        return v;
    }
};

