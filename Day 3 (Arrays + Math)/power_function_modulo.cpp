//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

#define mod 1000000007

class Solution{   
public:
// Recursive Solution Time- O(logn)
    double solve(double x,long long n)
    {
        if(n==0)
            return 1;
        if(n%2)
            return x*solve(x,n-1);
        else
            return solve(x*x,n/2);
    }
    double myPow(double x, int n) {
        long long nn=abs(n);
        double ans=solve(x,nn);
        return (n<0?1.0/ans:ans);
    }

// Iterative using bit_manipulation Time-O(logn)
    double power(double a,int n) { 
        long long b=abs(n);
        double res=1;
        while(b)
        {
            if(b&1)
            res=res*a; //res=(res*a)%mod;
            b>>=1;
            a=a*a; //a=(a*a)%mod;
        }
        return (n<0?1.0/res:res);
    }
};


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        double a;
        long long b;
        cin >> a >> b;
        Solution ob;
        cout << ob.power(a, b) << endl;
        cout << ob.myPow(a, b) << endl;
    
    }
    return 0; 
} 