// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2.
// If there is no next greater element, then the answer for this query is -1.
// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>m;
        int n=nums2.size();
        stack<int>s;
        s.push(nums2[0]);
        int j=0;
        for(auto n:nums2)
        {
            while(!s.empty() && s.top()<n)
            {
                m[s.top()]=n;
                s.pop();
            }
            s.push(n);
        }
        for(auto x:nums1)
            ans.push_back(m[x]?m[x]:-1);
        return ans;
    }
};
