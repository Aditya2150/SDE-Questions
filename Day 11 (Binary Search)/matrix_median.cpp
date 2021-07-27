int rowCnt(vector<int>&v,int& val)
{
    int low=0,high=v.size()-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(v[mid]<=val)
        low=mid+1;
        else
        high=mid-1;
    }
    return low;
}


int Solution::findMedian(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    int low=1;
    int high=1e9;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int cnt=0;
        for(auto i:A)
        cnt+=rowCnt(i,mid);
        if(cnt<=(n*m)/2)
        low=mid+1;
        else
        high=mid-1;
    }
    return low;
}
