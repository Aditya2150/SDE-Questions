// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.


// Recursive (BAD Complexity)
class Solution {
public:
    
    void solve(int index,int n,int& k,string s, string& ans,int p[])
    {
        if(k==0)
            return;
        if(index==n)
        {
            ans=s;
            k--;
            return;
        }
        for(int i=1;i<=n;i++)
        {
            if(p[i])continue;
            p[i]=1;
            s+='0'+i;
            solve(index+1,n,k,s,ans,p);
            s.pop_back();
            p[i]=0;
        }   
    }
    
    string getPermutation(int n, int k) {
        string ans;
        int p[n+1];
        memset(p,0,sizeof(p));
        solve(0,n,k,"",ans,p);
        return ans;
    }
};