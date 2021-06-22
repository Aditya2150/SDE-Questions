#include <bits/stdc++.h> 
using namespace std; 

class Solution {    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0],end=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(start==intervals[i][0] || end>=intervals[i][0])
                end=max(intervals[i][1],end);
            else if(intervals[i][0]>end)
            {
                v.push_back(vector<int>{start,end});
                start=intervals[i][0],end=intervals[i][1];
            }   
        }
        v.push_back(vector<int>{start,end});
        return v;
    }
};

int main()
{
    int n;
    cin >> n;
    int x,y;
    vector<vector<int>>intervals;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        intervals.push_back(vector<int>{x,y});
    }
    Solution ob;
    vector<vector<int>>v=ob.merge(intervals);
    cout << "[";
    for(auto i:v)
    cout << "[" << i[0] << "," << i[1] << "],";
    cout << "]\n";
}
