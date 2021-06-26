#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// Although the time complexity appears to be quadratic due to the while loop nested within
// the for loop, closer inspection reveals it to be linear. Because the while loop is reached
// only when currentNum marks the beginning of a sequence (i.e. currentNum-1 is not present in nums),
// the while loop can only run for nn iterations throughout the entire runtime of the algorithm.
// This means that despite looking like O(n \cdot n)O(n⋅n) complexity, the nested loops actually
// run in O(n + n) = O(n)O(n+n)=O(n) time. All other computations occur in constant time, so the
// overall runtime is linear.


// Time-O(n+n)=O(n)
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i:nums)
            m[i]++;
        int max_cnt=0;
        for(auto i:nums)
        {
            if(m.find(i-1)==m.end())
            {
                int cnt=1;
                int num=i;
                while(m.find(num+1)!=m.end())
                    num++,cnt++;
                max_cnt=max(max_cnt,cnt);
            }
        }
        return max_cnt;
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
    cout << ob.twoSum(v) << endl;
    return 0;
}