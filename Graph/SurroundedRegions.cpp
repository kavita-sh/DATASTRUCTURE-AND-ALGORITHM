#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void dfs(int r,int c,vector<vector<char>>& board,int n,int m){
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        board[r][c]='T';

        for(int i=0;i<4;i++){
            int nr= r+ dir[i][0];
            int nc= c+ dir[i][1];

            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='O'){
                dfs(nr,nc,board,n,m);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
            dfs(0,i,board,n,m);
            }
            if(board[n-1][i]=='O'){
                dfs(n-1,i,board,n,m);
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(i,0,board,n,m);
            }
            if(board[i][m-1]=='O'){
                dfs(i,m-1,board,n,m);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='T')
                board[i][j]='O';
                else if(board[i][j]=='O')
                board[i][j]='X';
            }
        }
    }
};