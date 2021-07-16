#include<bits/stdc++.h>
using namespace std;

//METHOD-1
class Solution
{
public:
	
	void solve(string s,int index,string x,vector<string>& ans,int p[])
	{
	    if(s.size()==x.size())
	    {
	        ans.push_back(x);
	        return;
	    }
	    for(int i=0;i<s.size();i++)
	    {
	        if(p[i])continue;
	        x+=s[i];
	        p[i]=1;
	        solve(s,i,x,ans,p);
	        p[i]=0;
	        x.pop_back();
	    }
	}
	
	
	vector<string>find_permutation(string S)
	{
	    vector<string> ans;
	    int p[S.size()];
	    memset(p,0,sizeof(p));
	    solve(S,0,"",ans,p);
	    sort(ans.begin(),ans.end());
	    return ans;
	}
};


// METHOD -2
class Solution
{
public:
	
	void solve(string s,int index,vector<string>& ans)
	{
	    if(index==s.size())
	    {
	        ans.push_back(s);
	        return;
	    }
	    for(int i=index;i<s.size();i++)
	    {
	        swap(s[index],s[i]);
	        solve(s,index+1,ans);
	        swap(s[index],s[i]);
	    }
	}
	
	
	vector<string>find_permutation(string S)
	{
	    vector<string> ans;
	    solve(S,0,ans);
	    sort(ans.begin(),ans.end());
	    return ans;
	}
};

int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}