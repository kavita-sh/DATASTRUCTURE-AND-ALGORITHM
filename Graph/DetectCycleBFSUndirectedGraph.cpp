#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool solve(int node , vector<int> &vis,vector<vector<int>>& adj){
        queue<pair<int,int>> q;
        vis[node]=1;
        q.push({node,-1});
        while(!q.empty()){
            int n= q.front().first;
            int p = q.front().second;
            q.pop();
            for(auto i : adj[n]){
                if(!vis[i]){
                    q.push({i,n});
                    vis[i]=1;
                }else if(i!= p){
                    return true;
                }
                
            }
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int n= adj.size();
        vector<int>vis(n,0);
        // Code here
        for(int i=0;i<n;i++){
            if(!vis[i])
            if(solve(i, vis, adj))
            return true;
        }
        return false;
    }
};