//We have to insert the given interval into the list of intervals and merge the overlapping intervals. Then we will iterate through the intervals and check if the current interval's start time is less than the new interval's end time. If it is then we will merge the intervals. Otherwise, we will add the interval to the result.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            vector<vector<int>>res;
            int i=0,n=intervals.size();
            while(i<n && intervals[i][1]<newInterval[0]){
                res.push_back(intervals[i]);
                i++;
            }
            while(i<n && intervals[i][0]<=newInterval[1]){
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]= max(newInterval[1],intervals[i][1]);
                i++;
            }
            res.push_back(newInterval);
            while(i<n){
                res.push_back(intervals[i]);
                i++;
            }
            return res;
        }
    };
    