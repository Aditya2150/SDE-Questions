#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool comp(Item a,Item b)
{
     return (double)a.value/(double)a.weight > (double)b.value/(double)b.weight;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        double ans=0;
        int i=0;
        while(i<n && W>=arr[i].weight)
        {
            ans+=arr[i].value;
            W-=arr[i].weight;
            i++;
        }
        if(i<n && W>0)
        ans+=(double)arr[i].value/(double)arr[i].weight*W;
        return ans;
    }
        
};

int main()
{
	int t;
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}