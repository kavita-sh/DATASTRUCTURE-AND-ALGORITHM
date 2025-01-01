// Problem Link: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
// Approach: We will use a priority queue to solve this problem. We will push the sum of the first element of the first array and the first element of the second array in the priority queue. We will also store the index of the first element of the first array and the first element of the second array in the priority queue. We will then pop the top element from the priority queue and push the sum of the first element of the first array and the second element of the second array in the priority queue. We will also store the index of the first element of the first array and the second element of the second array in the priority queue. We will repeat this process until we have found k pairs or the priority queue is empty. We will then return the pairs we have found.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq;
      vector<vector<int>>ans;
      for(int i=0;i<nums1.size() && i<k;i++){
       pq.push({nums1[i]+nums2[0],{i,0}});
      }
      while(k-- && !pq.empty()){
        int s= pq.top().first;
        auto v= pq.top().second;
        ans.push_back({nums1[v[0]],nums2[v[1]]});
        pq.pop();
        if(v[1]+1<nums2.size())
        pq.push({nums1[v[0]]+nums2[v[1]+1],{v[0],v[1]+1}});
      }
      return ans;
    }
};