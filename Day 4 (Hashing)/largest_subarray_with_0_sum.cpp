// Given an array of integers, find the length of the longest sub-array with a sum that equals 0.

#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}

// Time and Space-O(n)
int maxLen(int A[], int n)
{
    unordered_map<int,int>m;
    int sum=0,maxi=0;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        if (sum == 0)
            maxi = i + 1;
        if(m.find(sum)!=m.end())
            maxi=max(maxi,i-m[sum]);
        else
            m[sum]=i;
    }
    return maxi;
}
