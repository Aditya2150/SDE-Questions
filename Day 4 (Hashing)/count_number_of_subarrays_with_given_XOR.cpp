#include<bits/stdc++.h>
typedef long long ll;

// Another Approcah- NAIVE takes Time-O(N*N) as it tries to each and every subarray to find the subarray whose XOR is equal to X

// HASHMAP Approach Time-O(N) Space- O(N) 
int subarraysXor(vector<int> &arr, int x)
{
    ll n=arr.size();
    ll prefix=0;
    unordered_map<ll,ll> m;
    m[0]=1; 
    ll cnt=0;
    for(int i=0;i<n;i++)
    {
        prefix^=arr[i];
        if(m[prefix^x])
        	cnt+=m[prefix^x];
        m[prefix]++;
    }
    return cnt;
}