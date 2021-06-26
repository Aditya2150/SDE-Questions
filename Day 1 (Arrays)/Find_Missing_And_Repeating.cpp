#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
      unordered_map<int,int>m;
      for(int i=0;i<n;i++)
      m[arr[i]]++;
      int *a=new int(2);
      for(int i=1;i<=n;i++)
      {
          if(m[i]==0)
          a[1]=i;
          if(m[i]>1)
          a[0]=i;
      }
       return a;
    }

// Get the sum of all numbers using formula S = N(N+1)/2
// Get the sum of square of all numbers using formula Sum_Sq = N(N+1)(2N+1)/6
// Iterate through a loop from i=1….N
// S -= A[i]
// Sum_Sq -= (A[i]*A[i])
// It will give two equations 
// x-y = S – (1) 
// x^2 – y^2 = Sum_sq 
// x+ y = (Sum_sq/S) – (2) 


    int *findTwoElement(int *arr, int n) {
      long long int s=(n*(n+1))/2;
      long long int sq=(n*(n+1)*(2*n+1))/6;
      for(int i=0;i<n;i++)
      {
          s-=arr[i];
          sq-=arr[i]*arr[i];
      }
      int *a=new int(2);
      a[1]=(s+sq/s)/2;
      a[0]=a[1]-s;  
      return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends