//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

#define mod 1000000007

class Solution{   
public:
    long long int power(int a, long long int b) { 
        long long int res=1,x=a;
        while(b)
        {
            if(b&1)
            res=(res*x)%mod;
            b>>=1;
            x=(x*x)%mod;
        }
        return res;
    }
};


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        long long b;
        cin >> a >> b;
        Solution ob;
        cout << ob.power(a, b) << endl;
    
    }
    return 0; 
} 