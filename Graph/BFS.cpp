#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        queue<int>q;
        q.push(0);
        vector<int> ans;
        int N= adj.size();
        int vis[N]={0};
        vis[0]=1;
        while(!q.empty()){
            int n= q.front();
            ans.push_back(n);
            q.pop();
            for(auto i:adj[n]){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        return ans;
    }
    