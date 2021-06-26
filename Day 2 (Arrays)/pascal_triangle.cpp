// Pascal's triangle is a triangular array constructed by summing adjacent elements in preceding rows.
// Pascal's triangle contains the values of the binomial coefficient.

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if(numRows>0)
        v.push_back(vector<int>{1});
        if(numRows>1)
        v.push_back(vector<int>{1,1});
        for(int i=3;i<=numRows;i++)
        {
            vector<int>prev=v[i-2];
            vector<int>x;
            x.push_back(1);
            for(int j=0;j<prev.size()-1;j++)
                x.push_back(prev[j]+prev[j+1]);
            x.push_back(1);
            v.push_back(x);
        }
        return v;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution ob;
    vector<vector<int>> v= ob.generate(n);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}