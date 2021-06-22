// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n/2;i++)
        {
            
            for(int j=i;j<n-i-1;j++)
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[n-j-1][i];
                matrix[n-j-1][i]=matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1]=matrix[j][n-i-1];
                matrix[j][n-i-1]=temp;
            }
        }
        return;
    }
};

// The most elegant solution for rotating the matrix is to firstly reverse the matrix around the main diagonal,
//  and then reverse it from left to right. These operations are called transpose and reflect in linear algebra.



int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix;
    for(int i=0;i<n;i++)
    {
        vector<int>v(n);
        for(int j=0;j<n;j++)
        cin >> v[j];
        matrix.push_back(v);
    }
    Solution ob;
    ob.rotate(matrix);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}