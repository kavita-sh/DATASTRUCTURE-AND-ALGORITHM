#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int>adj[numCourses];
       vector<int>ans;
       queue<int>q;
       for(int i=0;i<prerequisites.size();i++){
        int u= prerequisites[i][0];
        int v= prerequisites[i][1];
        adj[v].push_back(u);
       }
        vector<int>in(numCourses);
        for(int i=0;i<numCourses;i++){
            for(auto j: adj[i]){
                in[j]++;
            }
        }
        for(int i=0;i<in.size();i++){
            if(in[i]==0)
            q.push(i);
        }
         while(!q.empty()){
            int n= q.front();
            q.pop();
            ans.push_back(n);
            for(auto i: adj[n]){
              in[i]--;
              if(in[i]==0)
              q.push(i);
            }
         }
         if(ans.size()==numCourses)
         return ans;
         else{
            vector<int>ans;
            return ans;
         }
         
       } 
    
};