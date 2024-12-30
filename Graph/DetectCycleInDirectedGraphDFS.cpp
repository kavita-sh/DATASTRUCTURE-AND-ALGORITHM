// we will take visited and path array to keep track of visited nodes and path of nodes
// if we find a node which is already in path array then we have a cycle
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool dfs(int node,vector<vector<int>> &adj, vector<int> &vis,vector<int> &path){
        vis[node]=1;
        path[node]=1;
        for(auto i : adj[node]){
            if(!vis[i]){
                if(dfs(i,adj,vis,path))
                return true;
            }
            else if(vis[i] && path[i]){
                return true;
            }
        }
        path[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<int> vis(V,0);
        vector<int> path(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path))
                return true;
            }
        }
        return false;
    }
};