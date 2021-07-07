#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
}

class Solution
{
    public:
    int maxMeetings(int start[], int end[], int n)
    {
       vector<pair<int,int>>v;
       for(int i=0;i<n;i++)
       v.push_back({start[i],end[i]});
       sort(v.begin(),v.end(),comp);
       int cnt=1;
       int e=v[0].second;
       for(int i=1;i<n;i++)
       {
           if(e<v[i].first)
          cnt++,e=v[i].second;
       }
       return cnt;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];
        for (int i = 0; i < n; i++) cin >> end[i];
        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}