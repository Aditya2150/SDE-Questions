#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string>v;
		    int n=s.size();
		    string x;
		    for(int i=1;i<(1<<n);i++)
		    {
		        x="";
		        for(int j=0;j<n;j++)
		        {
		            if((i>>j)&1)
		            x+=s[j];
		        }
		        v.push_back(x);
		    }
		    sort(v.begin(),v.end());
		    return v;
		}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}