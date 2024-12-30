// Problem: Redundant Connection
// Given an undirected graph, the problem is to find the redundant connection which is causing the cycle in the graph.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        vector<int>adj[n+1];
        vector<int>in(n+1,0);
        for(int i=0;i<n;i++){
            int u= edges[i][0];
            int v= edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            in[u]++;
            in[v]++;
        }
        queue<int>q;
       for(int i=1;i<=n;i++){
          if(in[i]==1){
            q.push(i);
          }
       }
       while(!q.empty()){
         int n= q.front();
         q.pop();
         in[n]--;
         for(auto i:adj[n]){
            in[i]--;
            if(in[i]==1){
                q.push(i);
            }
         }
       }
       for(int j=n-1;j>=0;j--){
        int u= edges[j][0];
        int v= edges[j][1];
        if(in[u]>0 && in[v]>0){
            return {u,v};
        }
       }
       return {};
    }
};