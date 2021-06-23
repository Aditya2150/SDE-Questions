// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

#include<bits/stdc++.h>
using namespace std;

// Space- O(1) Moore's Voting Algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>v;
        int n=nums.size();
        int cnt1=0,cnt2=0;
        int cand1=-1,cand2=-1;
        for(auto i:nums)
        {
            if(i==cand1)
                cnt1++;
            else if(i==cand2)
                cnt2++;
            else if(cnt1==0)
                cand1=i,cnt1++;
            else if(cnt2==0)
                cand2=i,cnt2++;
            else
                cnt1--,cnt2--;
        }
        cnt1=0,cnt2=0;
        for(auto i:nums)
        {
            if(i==cand1)
                cnt1++;
            if(i==cand2)
                cnt2++;
        }
        if(cnt1>n/3)
            v.push_back(cand1);
        if(cnt2>n/3)
            v.push_back(cand2);
        if(v.size()==2 && cand1==cand2)
            v.pop_back();
        return v;
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
    vector<int>x=ob.majorityElement(v);
    for(auto i:x)
    cout << i << " ";
    cout << endl;
    return 0;
}