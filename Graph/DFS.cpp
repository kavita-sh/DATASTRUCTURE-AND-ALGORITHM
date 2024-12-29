#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int vis[], vector<int> &ans,int node){
        vis[node]=1;
        ans.push_back(node);
    for(auto i:adj[node]){
        if(!vis[i]){
            dfs(adj,vis,ans,i);
        }
    }
    }

    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int N= adj.size();
        int vis[N]={0};
        vector<int>ans;
        int node=0;
        dfs(adj,vis,ans,node);
        return ans;
    }