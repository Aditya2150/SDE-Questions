// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times.
// You may assume that the majority element always exists in the array.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// Time- O(n) Space- O(n)
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i:nums)
            m[i]++;
        for(auto i:m)
        {
            if(i.second>(nums.size()/2))
                return i.first;
        }
        return 0;
    }

// Space- O(1) Moore's Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int candidate=0;
        for(auto i:nums)
        {
            if(cnt==0)
            candidate=i;
            if(candidate==i)
                cnt++;
            else
                cnt--;
        }
        return candidate;    
    }
};


int main()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin >>v[i];
    Solution ob;
    cout << ob.majorityElement(v) << endl;
    return 0;
}