//Given an array of intervals intervals where intervals[i] = [start_i, end_i], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            sort(intervals.begin(),intervals.end(),[](vector<int>&a, vector<int>&b){
                return a[1]<b[1];
            });
            int count=0;
            int l = intervals[0][1];
            for(int i=1;i<intervals.size();i++){
                if(intervals[i][0]<l){
                   count++;
                }else{
                    l= intervals[i][1];
                }
            }
            return count;
        }
    };
    