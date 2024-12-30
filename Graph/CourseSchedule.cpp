// we will do this by using topological sort and at the end if the number of nodes in toposort is not equal to the number of nodes then there is a cycle.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>ans;
        for(int i=0;i<prerequisites.size();i++){
            int u= prerequisites[i][0];
            int v= prerequisites[i][1];

            adj[v].push_back(u);
        }
        queue<int>q;
      vector<int > in(numCourses);
        for(int i=0;i<numCourses;i++){
            for(auto j:adj[i] ){
           in[j]++;
            }
        }
       for(int i=0;i<in.size();i++){
        if(in[i]==0)
        q.push(i);
       }
       while(!q.empty()){
        int n= q.front();
        ans.push_back(n);
        q.pop();
        for(auto i:adj[n]){
            in[i]--;
            if(in[i]==0)
            q.push(i);
        }
       }
       if(ans.size()==numCourses)
       return true;
       else 
       return false;
    }
};
