// Given a word, find the lexicographically greater permutation of it.
// For example, lexicographically next permutation of “gfg” is “ggf” and next permutation of “acb” is “bac”.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

//  Time-O(n) and Space-O(1)
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while(i>=0 && nums[i+1]<=nums[i])
            i--;
        if(i>=0)
        {
            int j=nums.size()-1;
            while(nums[j]<=nums[i])
                j--;
            swap(nums[j],nums[i]);
        }
        reverse(nums.begin()+i+1,nums.end());
        return;
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
    ob.nextPermutation(v);
    for(int i=0;i<v.size();i++)
    cout << v[i] << " ";
    cout << endl;
    return 0;
}