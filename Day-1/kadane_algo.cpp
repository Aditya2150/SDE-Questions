#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int csum=0,osum=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(csum>=0)
                csum+=nums[i];
            else
                csum=nums[i];
            if(osum<csum)
                osum=csum;
        }
        return osum;
    }
};


int main()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin >> v[i];
    Solution ob;
    cout << ob.maxSubArray(v) << endl;
    return 0;
}