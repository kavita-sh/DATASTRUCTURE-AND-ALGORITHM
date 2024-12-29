#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    void dfs(vector<vector<char>>& grid,vector<vector<int> > &vis, int r,int c, int n,int m){
        vis[r][c]=1;
        int dir[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};
        //To check all the horizontal & vertical directions
        for(int i=0;i<4;i++){
             
                int nr= r +dir[i][0];
                int nc=c +dir[i][1];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]=='1' ){
                    dfs(grid,vis,nr,nc,n,m);
                }
            
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int> >vis(n,vector<int>(m,0));
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    ans++;
                    dfs(grid,vis,i,j,n,m);
                }
            }
        }
        return ans;
    }
//     void dfs(vector<vector<char>>& grid,vector<vector<int> > &vis, int r,int c, int n,int m){
//         vis[r][c]=1;
//         //To check all the 8 diagnols
//         for(int i=-1;i<=1;i++){
//             for(int j=-1;j<=1;j++){
//                 if(i==0 && j==0)
//                 continue;
//                 int nr= r +i;
//                 int nc=c +j;
//                 if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]=='1' ){
//                     dfs(grid,vis,nr,nc,n,m);
//                 }
//             }
//         }
//     }
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int n= grid.size();
//         int m= grid[0].size();
//         vector<vector<int> >vis(n,vector<int>(m,0));
//         int ans=0;

//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(!vis[i][j] && grid[i][j]=='1'){
//                     ans++;
//                     dfs(grid,vis,i,j,n,m);
//                 }
//             }
//         }
//         return ans;
//     }
};