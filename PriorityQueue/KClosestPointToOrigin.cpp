#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> pq;
        for(auto i:points){
           int d= i[0]*i[0] + i[1]*i[1];
           pq.push({d,{i[0],i[1]}});
        }
        while(k-- && !pq.empty()){
            auto v= pq.top();
            pq.pop();
            auto res= v.second;
            ans.push_back(res);
        }
        return ans;
    }
};