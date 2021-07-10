// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.
// A palindrome string is a string that reads the same backward as forward.

class Solution {
public:
    
    void solve(int index,string s,vector<string>v,vector<vector<string>>& ans)
    {
        if(index==s.size())
        {
            ans.push_back(v);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(check(index,i,s))
            {
                v.push_back(s.substr(index,i-index+1));
                solve(i+1,s,v,ans);
                v.pop_back();
            }
        }
    }
    
    bool check(int s,int e,string str)
    {
        while(s<e)
        {
            if(str[s++]!=str[e--])
                return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        solve(0,s,v,ans);
        return ans;
    }
};