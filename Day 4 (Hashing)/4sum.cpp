// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.


// Sorting the Array
// NAIVE APPROACH using 3 pointers and Binary search and hashset for unique quadraplets. 
// Time-(N*N*N*(N*logN) + NLogN + NLogN)  Space-O(N) 


// 2 POINTER APPROACH Time-O((N*N*N) + NlogN) Space-O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int low=j+1,high=n-1;
                while(low<high)
                {
                    int sum=nums[i]+nums[j]+nums[low]+nums[high];
                    if(sum<target)
                        low++;
                    else if(sum>target)
                        high--;
                    else
                    {
                        v.push_back(vector<int>{nums[i],nums[j],nums[low],nums[high]});
                        while(low<n-1 && nums[low]==nums[low+1])low++;
                        while(high>0 && nums[high]==nums[high-1])high--;
                        low++,high--;
                    }
                }
                while(j<n-2 && nums[j]==nums[j+1])j++;
            }
            while(i<n-3 && nums[i]==nums[i+1])i++;
        }
        return v;
    }
};