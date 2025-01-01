#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(auto [i,j] : mp){
            pq.push({j,i});
            if(pq.size()>k)
            pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};