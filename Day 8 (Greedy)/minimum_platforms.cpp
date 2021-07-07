// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=0,j=0;
    	int maxi=0,cnt=0;
    	while(i<n && j<n)
    	{
    	    if(arr[i]<=dep[j])
    	    cnt++,i++;
    	    else
    	    cnt--,j++;
    	    maxi=max(maxi,cnt);
    	}
    	return maxi;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}