// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

// Space Complexity- O(n+m) 
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>row_flag(n,0);
        vector<int>col_flag(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                if(matrix[i][j]==0)
                    row_flag[i]=1,col_flag[j]=1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                if(row_flag[i]==1 || col_flag[j]==1)
                    matrix[i][j]=0;
        }
        return;
    }

// Space Complexity- O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool col=false;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]==0)
                col=true;
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==0)
                    matrix[i][0]=0,matrix[0][j]=0;
            }
        }
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
        if(matrix[0][0]==0)
        {
            for(int i=0;i<m;i++)
                matrix[0][i]=0;
        }
        if(col)
        {
            for(int i=0;i<n;i++)
                matrix[i][0]=0;
        }
        return;
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
    Solution ob;
    ob.setZeroes(matrix);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}