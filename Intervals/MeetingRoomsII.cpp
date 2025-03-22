//Given an array of meeting time interval objects consisting of start and end times [[start_1,end_1],[start_2,end_2],...] (start_i < end_i), find the minimum number of days required to schedule all meetings without any conflicts.


#include <bits/stdc++.h>
using namespace std;

class Interval {
     public:
        int start, end;
        Interval(int start, int end) {
            this->start = start;
            this->end = end;
        }
    };

class Solution {
    public:
        int minMeetingRooms(vector<Interval>& intervals) {
            if(intervals.size()==0)
            return 0;
            sort(intervals.begin(),intervals.end(),[](auto &a, auto &b){
                return a.start<b.start;
            });
            priority_queue<int,vector<int>,greater<int>>pq;
            pq.push(intervals[0].end);
            for(int i=1;i<intervals.size();i++){
                if(intervals[i].start>=pq.top()){
                    pq.pop();
                }
                pq.push(intervals[i].end);
            }
            return pq.size();
        }
    };