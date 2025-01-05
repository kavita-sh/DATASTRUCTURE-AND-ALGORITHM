//we have to place n queens in n*n chess board such that no two queens attack each other
//We will use backtracking to solve this problem.
//We will have a helper function which will take the current column, the board, the answer vector, the row vector, the lower diagonal vector and the upper diagonal vector.
//If the current column is equal to n, we will push the current board into the answer vector.
//Otherwise, we will check for every row if it is safe to place the queen.
//If it is, we will place the queen and call the helper function with the next column.
//Then we will remove the queen and backtrack.
//We will call the helper function with the initial column as 0, an empty board, an empty row vector, an empty lower diagonal vector and an empty upper diagonal vector.
//We will return the answer vector.
//The time complexity of this approach is O(n!) where n is the number of queens.
//The space complexity of this approach is O(n^2) where n is the number of queens.


#include<bits/stdc++.h>
using namespace std;

class Solution {

    public:
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,vector<int>&row,vector<int>&lowerdi,vector<int>&upperdi,int n){
      if(col==n){
        ans.push_back(board);
        return;
      }

      for(int i=0;i<n;i++){
        if(row[i]==0 && lowerdi[col+i]==0 && upperdi[(n-1)+(col-i)]==0){
          board[i][col]='Q';
          row[i]=1;
          lowerdi[i+col]=1;
          upperdi[(n-1)+(col-i)]=1;

          solve(col+1,board,ans,row,lowerdi,upperdi,n);
          board[i][col]='.';
          row[i]=0;
          lowerdi[i+col]=0;
          upperdi[(n-1)+(col-i)]=0;
        }
      }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string>board(n);
        vector<vector<string>>ans;
       
        for(int i=0;i<n;i++){
            board[i]= s;
        }
        vector<int>row(n,0),lowerdi((2*n-1),0),upperdi((2*n-1),0);
        solve(0,board,ans,row,lowerdi,upperdi,n);
        return ans;
    }
};
