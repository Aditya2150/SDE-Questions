// Given a string s, find the length of the longest substring without repeating characters.

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int j=0,cnt=0,maxi=0;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])!=m.end() && m[s[i]]>0)
            {
                maxi=max(maxi,cnt);
                while(m[s[i]]!=0)
                {
                    m[s[j++]]--;
                    cnt--;
                }
            }
            m[s[i]]++;
            cnt++;
        }
        maxi=max(maxi,cnt);
        return maxi;
    }
};

int main()
{
    string s;
    cin >>s;
    Solution ob;
    cout << ob.lengthOfLongestSubstring(s) << endl;
    return 0;
}