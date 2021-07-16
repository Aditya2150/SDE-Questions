//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        if(n==0)
        return false;
        return ceil(log2(n))==floor(log2(n));      
    }
};
int main()
{

    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        long long n;
        cin>>n;

        Solution ob;
         if(ob.isPowerofTwo(n))
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;
    }
    return 0;
}