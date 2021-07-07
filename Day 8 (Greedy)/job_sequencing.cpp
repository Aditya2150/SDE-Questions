// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 


// TIME- O(NlogN) 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

bool comp(Job a,Job b)
{
    return a.profit>b.profit;
}

class Solution 
{
    public:
    int parent[101];
    
    void initalize(int n)
    {
        for(int i=0;i<n;i++)
        parent[i]=i;
    }
    int par(int node)
    {
        if(parent[node]==node)
        return node;
        return parent[node]=par(parent[node]);
    }
    
    void ranks(int x,int y)
    {
        parent[x]=y;
        return;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        maxi=max(maxi,arr[i].dead);
        initalize(maxi+1);
        sort(arr,arr+n,comp);
        vector<int>v(2,0);
        for(int i=0;i<n;i++)
        {
            int x=par(arr[i].dead);
            if(x>0)
            {
                ranks(x,par(x-1));
                v[0]+=1;
                v[1]+=arr[i].profit;
            }
        }
        return v;
    } 
};

int main() 
{ 
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}