#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int dfs(vector<vector<int>>& grid,vector<vector<int>> &vis,int n,int m, int r,int c, int &ans ){
    int dir[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};
    ans++;
    vis[r][c]=1;
    for(int i=0;i<4;i++){
        int nr= r+ dir[i][0];
        int nc= c+ dir[i][1];
        if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
            dfs(grid,vis,n,m,nr,nc,ans);
        }
    }
    return ans;
}
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    dfs(grid,vis,n,m,i,j,ans);
                    cnt = max(cnt,ans);
                    ans=0;
                }
            }
        }
       return cnt;
    }
};