// Given a collection of candidate numbers (candidates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

class Solution {
public:
    void solve(int index,vector<int>& candidates, int target,vector<int>v,vector<vector<int>>& ans)
    {
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        if(target<0)
            return;
        for(int i=index;i<candidates.size();i++)
        {
            if(i!=index && candidates[i]==candidates[i-1])continue;
            v.push_back(candidates[i]);
            solve(i+1,candidates,target-candidates[i],v,ans);
            v.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,v,ans);
        return ans;
    }
};