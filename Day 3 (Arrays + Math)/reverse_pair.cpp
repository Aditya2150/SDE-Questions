// Given an integer array nums, return the number of reverse pairs in the array.
// A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int merge(vector<int>& nums,int temp[],int left,int mid,int right)
    {
        int cnt=0;
        int i=left,j=mid,k=left;
        while(i<mid && j<=right)
        {
            if(nums[i]>(2LL*nums[j]))
                cnt+=mid-i,j++;
            else
                i++;
        }
        i=left,j=mid,k=left;
        while(i<mid && j<=right)
        {
            if(nums[i]<=nums[j])
                temp[k++]=nums[i++];
            else
                temp[k++]=nums[j++];
        }
        while(i<mid)
            temp[k++]=nums[i++];
        while(j<=right)
            temp[k++]=nums[j++];
        for(int i=left;i<=right;i++)
            nums[i]=temp[i];
        return cnt;
    }
    
    int mergesort(vector<int>& nums,int temp[],int left,int right)
    {
        int cnt=0;
        if(left<right)
        {
            int mid=left+(right-left)/2;
            cnt+=mergesort(nums,temp,left,mid);
            cnt+=mergesort(nums,temp,mid+1,right);
            cnt+=merge(nums,temp,left,mid+1,right);
        }
        return cnt;
    }
        
    
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int temp[n];
        return mergesort(nums,temp,0,n-1);
    }
};

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        vector<int>A(N);
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.reversePairs(A) << endl;
    }
    
    return 0;
}
