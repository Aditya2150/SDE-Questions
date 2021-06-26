// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// Time- O(n+m)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0,j=m-1;
        while(i<n && j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            else if(target>matrix[i][j])
                i++;
            else
                j--;
        }
        return false;
    }

// Optimised Time-O(log(n*m))
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0,high=n*m-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(matrix[mid/m][mid%m]==target)
                return true;
            else if(matrix[mid/m][mid%m]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
};


int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>>matrix;
    for(int i=0;i<n;i++)
    {
        vector<int>v(m);
        for(int j=0;j<m;j++)
        cin >> v[j];
        matrix.push_back(v);
    }
    int target;
    cin >> target;
    Solution ob;
    cout << (ob.searchMatrix(matrix,target)?"True":"False") << endl;
    return 0;
}