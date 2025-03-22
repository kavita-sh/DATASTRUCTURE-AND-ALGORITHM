//You are given a 2D integer array intervals, where intervals[i] = [left_i, right_i] represents the ith interval starting at left_i and ending at right_i (inclusive).

// You are also given an integer array of query points queries. The result of query[j] is the length of the shortest interval i such that left_i <= queries[j] <= right_i. If no such interval exists, the result of this query is -1.

// Return an array output where output[j] is the result of query[j].

// Note: The length of an interval is calculated as right_i - left_i + 1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
            sort(intervals.begin(),intervals.end());
            vector<pair<int,int>>sortQ;
            for(int i=0;i<queries.size();i++){
                sortQ.push_back({queries[i],i});
            }
            sort(sortQ.begin(),sortQ.end());
            vector<int>res(queries.size());
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            int i=0;
            for(pair<int,int>a : sortQ){
                while(i<intervals.size() && intervals[i][0]<=a.first){
                 pq.push({intervals[i][1]-intervals[i][0]+1,intervals[i][1]});
                 i++;
                }
                while(!pq.empty() && pq.top().second<a.first){
                    pq.pop();
                }
                res[a.second]=pq.empty()?-1:pq.top().first;
            }
            return res;
        }
    };
    