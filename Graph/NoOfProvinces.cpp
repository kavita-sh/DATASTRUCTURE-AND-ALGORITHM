#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[], int vis[],int node){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(adj,vis,i);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int vis[V+1]={0};
        int ans=0;
        vector<int> adja[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(i!=j && adj[i][j]==1){
                    adja[i].push_back(j);
                    adja[j].push_back(i);
                }
            }
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                ans++;
                dfs(adja,vis,i);
            }
        }
        return ans;
    }

    // space Complexity: O(V) +O(V)
    // Time Complexity: O(V)(for loop)+ O(V+2E)