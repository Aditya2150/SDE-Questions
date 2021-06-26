// Inversion Count for an array indicates – how far (or close) the array is from being sorted.
// If the array is already sorted, then the inversion count is 0, but if the array is sorted 
// in the reverse order, the inversion count is the maximum. 

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    
  public:

    // Brute Force Time-O(n2)
    long long int inversionCount(long long arr[], long long N)
    {
        long long int cnt=0;
        for(long long int i=0;i<N;i++)
        {
            for(long long int j=i+1;j<N;j++)
            {
                if(arr[i]>arr[j])
                cnt++;
            }
        }
        return cnt;
    }


    // Using Merge sort Time- O(nlogn)
    long long merge(long long arr[],long long temp[],long long left,long long mid,long long right)
    {
        long long cnt=0;
        long long i=left,j=mid,k=left;
        while(i<mid && j<=right)
        {
            if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
            else
            {
                temp[k++]=arr[j++];
                cnt+=(mid-i);
            }
        }
        while(i<mid)
        temp[k++]=arr[i++];
        while(j<=right)
        temp[k++]=arr[j++];
        for(int i=left;i<=right;i++)
        arr[i]=temp[i];
        return cnt;
    }
    long long mergesort(long long arr[],long long temp[],long long int left,long long int right)
    {
        long long cnt=0;
        if(right>left)
        {
            long long mid=(left+right)/2;
            cnt+=mergesort(arr,temp,left,mid);
            cnt+=mergesort(arr,temp,mid+1,right);
            cnt+=merge(arr,temp,left,mid+1,right);
        }
        return cnt;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long int temp[N];
        long long int cnt=mergesort(arr,temp,0,N-1);
        return cnt;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends