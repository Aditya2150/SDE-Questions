// Given a binary array nums, return the maximum number of consecutive 1's in the array.

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0,prev=-1,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {maxi=max(maxi,i-prev-1);prev=i;}
        }
        maxi=max(maxi,n-1-prev);
        return maxi;
    }
};