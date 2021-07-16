// You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).
#include<bits/stdc++.h>
using namespace std;

// Time-O(logn) Space-O(1)

class Solution{
    public:
    int countSetBits(int n)
    {
        n++;
        int x=log2(n)+1;
        int ans=0,t=2,m=1;
        for(int i=0;i<x;i++)
        {
            ans+=m*(n/t);
            if(n%t>m)
            ans+=(n%t-m);
            t*=2;
            m*=2;
        }
        return ans;
    }
};

// PATTERN->
// 0000
// 0001
// 0010
// 0011
// 0100
// 0101
// 0110
// 0111
// 1000
// 1001
// 1010
// 1011
// 1100
// 1101
// 1110
// 1111

int main()
{
	 int t;
	 cin>>t;
	 while(t--) 
	 {
	       int n;
	       cin>>n; 
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;
	  }
	  return 0;
}