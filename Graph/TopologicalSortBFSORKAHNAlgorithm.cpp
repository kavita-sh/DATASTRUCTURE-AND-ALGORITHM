//for this we will use queue and indegree array to find the topological sort of a graph.
// we will first calculate the indegree of all the nodes and then we will push the nodes with indegree 0 in the queue.
// then we will pop the node from the queue and reduce the indegree of all the nodes connected to it by 1.
// if the indegree of any node becomes 0 then we will push that node in the queue.
// we will keep a count of the nodes visited and if the count is not equal to the number of nodes then we will return an empty array.
// otherwise, we will return the topological sort of the graph.
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        
        // Your code here
        vector<int>ans;
        int n= adj.size();
        queue<int> q;
        vector<int> in(n,0);
        for(int i=0;i<n;i++){
            for(auto j: adj[i]){
                in[j]++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(in[i]==0)
            q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto i: adj[node]){
                in[i]--;
                if(in[i]==0)
                q.push(i);
                
            }
        }
        return ans;
    }
};