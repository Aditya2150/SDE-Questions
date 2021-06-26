#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// one pass solution Time-O(n) Space-O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end() && m[target-nums[i]]!=i)
                return vector<int>{i,m[target-nums[i]]};
            m[nums[i]]=i;
        }
        return v;
    }
};

int main()
{
    int n,t;
    cin >> n >> t;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin >> v[i];
    Solution ob;
    vector<int>x=ob.twoSum(v,t);
    for(auto i:x)
    cout << i << " ";
    cout << endl;
    return 0;
}