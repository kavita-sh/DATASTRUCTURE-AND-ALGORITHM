//Linear ordering of vertices such that for every directed edge u->v, vertex u comes before v in the ordering.
// It is there only in directed acyclic graphs.
// we will use DFS to find the topological sort of a graph. and we will use stack to store the vertices in topological order.
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>&vis,stack<int> &st ){
        vis[node]=1;
        
        for(auto i: adj[node]){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        st.push(node);
    }
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int n= adj.size();
        vector<int >vis(n,0);
        stack<int>st;
        vector<int >ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};