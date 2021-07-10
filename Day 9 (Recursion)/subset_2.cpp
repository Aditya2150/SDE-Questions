// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<pow(2,n);i++)
        {
            vector<int>v;
            for(int j=0;j<n;j++)
            {
                if(i>>j&1)
                    v.push_back(nums[j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};


// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        int total=pow(2,n);
        sort(nums.begin(),nums.end());
        unordered_set<string>visited;
        for(int i=0;i<total;i++)
        {
            string s="";
            vector<int>v;
            for(int j=0;j<n;j++)
            {
                int mask=i>>j;
                if(mask&1)
                {
                    s+=to_string(nums[j])+",";
                    v.push_back(nums[j]);
                }
            }
            if(visited.find(s)==visited.end())
                ans.push_back(v);
            visited.insert(s);
        }
        return ans;
    }
};


// RECURSION
class Solution {
public:
    void solve(vector<int>&nums,int index,vector<int>v,vector<vector<int>>& ans)
    {
        ans.push_back(v);
        for(int i=index;i<nums.size();i++)
        {
            if(index!=i && nums[i]==nums[i-1])continue;
            v.push_back(nums[i]);
            solve(nums,i+1,v,ans);
            v.pop_back();   
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(nums.begin(),nums.end());
        solve(nums,0,v,ans);
        return ans; 
    }
};