//We have to merge the overlapping intervals. We can do this by sorting the intervals based on the start time. Then we will iterate through the intervals and check if the current interval's start time is less than the previous interval's end time. If it is then we will merge the intervals. Otherwise, we will add the interval to the result.
//The time complexity of this approach is O(nlogn) where n is the number of intervals.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            vector<vector<int>>res;
            sort(intervals.begin(),intervals.end());
            res.push_back(intervals[0]);
            int j=0;
            for(int i=1;i<intervals.size();i++){
                if(res[j][1]>=intervals[i][0]){
                    res[j][0]= min(res[j][0],intervals[i][0]);
                    res[j][1]= max(res[j][1],intervals[i][1]);    
                }else{
                    j++;
                    res.push_back(intervals[i]);
                }
            }
            return res;
        }
    };
    