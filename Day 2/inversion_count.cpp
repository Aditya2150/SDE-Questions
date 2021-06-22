// Inversion Count for an array indicates – how far (or close) the array is from being sorted.
// If the array is already sorted, then the inversion count is 0, but if the array is sorted 
// in the reverse order, the inversion count is the maximum. 

#include<bits/stdc++.h>
using namespace std;

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


int main()
{
    return 0;
}