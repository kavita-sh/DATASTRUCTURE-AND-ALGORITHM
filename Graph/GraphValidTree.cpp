#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
       vector<int>adj[n];
       vector<int> vis(n,0);
       vector<int>ans;
       for(int i=0;i<edges.size();i++){
        int u= edges[i][0];
        int v= edges[i][1];
          adj[u].push_back(v);
          adj[v].push_back(u);
       }
       queue<pair<int,int> >q;
       q.push({0,-1});
       vis[0]=1;
       while(!q.empty()){
        int node= q.front().first;
        int p= q.front().second;
        q.pop();
        ans.push_back(node);
        for(auto i: adj[node]){
            if(!vis[i]){
                q.push({i,node});
                vis[i]=1;
            }else if(vis[i] && i!=p){
                return false;
            }
        }
       }
       if(ans.size()==n)
       return true;
       else
       return false;
    }
};