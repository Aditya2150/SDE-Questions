
#include<bits/stdc++.h>
using namespace std;

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a 
// different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.


// PART-1 (EASIEST)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int m=0;
        int start=prices[0];
        for(int i=1;i<n;i++)
        {
            if(start<=prices[i])
                m=max(m,prices[i]-start);
            else
               start=prices[i]; 
        }
        return m;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin >> v[i];
    Solution ob;
    cout << ob.maxProfit(v) << endl;
    return 0;
}