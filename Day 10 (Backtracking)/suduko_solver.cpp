// Write a program to solve a Sudoku puzzle by filling the empty cells.
// A sudoku solution must satisfy all of the following rules:
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.


class Solution {
public:
    
    bool check(int r,int c,vector<vector<char>>& board,char num)
    {
        for(int i=0;i<9;i++)
        {
            if(board[r][i]==num)
                return true;
            if(board[i][c]==num)
                return true;
        }
        int row=r/3*3,col=c/3*3;
        for(int i=row;i<row+3;i++)
        {
            for(int j=col;j<col+3;j++)
            {
                if(board[i][j]==num)
                    return true;
            }
        }
        return false;
    }
    
    bool solve(int r,int c,vector<vector<char>>& board)
    {
        if(r==9)
            return true;
        if(c==9)
            return solve(r+1,0,board);
        if(board[r][c]!='.')    
            return solve(r,c+1,board);
        
        for(char i='1';i<='9';i++)
        {
            if(!check(r,c,board,i))
            {
                board[r][c]=i;
                if(solve(r,c+1,board))return true;
                board[r][c]='.';
            } 
        }  
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);
        return;
    }
};