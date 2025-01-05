//we have to find the word in the board if it is present in the board then return true otherwise false
//We will use backtracking to solve this problem.
//We will have a helper function which will take the board, the visited array, the current row, the current column, the word and the index.
//If the index is equal to the size of the word, we will return true.
//Otherwise, we will mark the current cell as visited and check in all four directions if the next character of the word is present.
//If it is, we will call the helper function with the next row, the next column and the next index.
//If the helper function returns true, we will return true.
//Otherwise, we will mark the current cell as unvisited and return false.
//We will call the helper function with the initial row, the initial column, the word and the index as 0.
//We will return false.
//The time complexity of this approach is O(n*m*4^l) where n is the number of rows, m is the number of columns and l is the length of the word.

#include<bits/stdc++.h>
using namespace std;

class Solution {

    bool dfs(vector<vector<char>>& board,vector<vector<int>>&vis,int r,int c,string word,int ind){
        int n= board.size();
        int m= board[0].size();
        if(ind == word.size())
        return true;
        
        vis[r][c]=1;
        int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};
        for(int i=0;i<4;i++){
           int nr= r+dir[i][0];
           int nc= c+ dir[i][1];

           if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && board[nr][nc]==word[ind]){
               vis[nr][nc]=1;
               if(dfs(board,vis,nr,nc,word,ind+1))
               return true;
          }
        }
        vis[r][c]=0;
        return false;  
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n= board.size();
        int m= board[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,vis,i,j,word,1))
                    {
                        return true;
                    }
                }
            }
        }
    
        return false;
    }
};