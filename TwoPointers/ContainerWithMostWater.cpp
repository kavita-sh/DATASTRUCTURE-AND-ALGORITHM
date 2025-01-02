// Problem Link: https://leetcode.com/problems/container-with-most-water/
// The problem is to find the maximum area of water that can be trapped between the vertical lines.
// The solution is to use two pointers and keep track of the maximum area.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0,j=heights.size()-1;
        int ans=0;
        while(i<j){
            
            ans= max(ans,min(heights[i],heights[j])*(j-i));
            if(heights[i]<=heights[j]){
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};
