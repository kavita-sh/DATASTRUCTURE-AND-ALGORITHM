#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<int>>& heights,int n,int m ){
        vis[r][c]=1;
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<4;i++){
            int nr= r+ dir[i][0];
            int nc= c+ dir[i][1];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && heights[nr][nc]>=heights[r][c]){
                dfs(nr,nc,vis,heights,n,m);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n= heights.size();
        int m= heights[0].size();

        vector<vector<int>>pac(n,vector<int>(m,0));
        vector<vector<int>>at(n,vector<int>(m,0));
        
        for(int i=0;i<m;i++){
         dfs(0,i,pac,heights,n,m);
         dfs(n-1,i,at,heights,n,m);
        }
        
        for(int i=0;i<n;i++){
            dfs(i,0,pac,heights,n,m);
            dfs(i,m-1,at,heights,n,m);
        }
        vector<vector<int >> res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && at[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};