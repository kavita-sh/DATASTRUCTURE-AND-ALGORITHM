// Problem: Trapping Rain Water
// Problem Link: https://leetcode.com/problems/trapping-rain-water/
// The problem is to find the amount of water that can be trapped between the bars.
// The solution is to use two pointers and keep track of the maximum height of the bars on the left and right side.
// The amount of water that can be trapped at a particular index is the minimum of the maximum height of the bars on the left and right side minus the height of the bar at that index.
// The total amount of water that can be trapped is the sum of the amount of water that can be trapped at each index.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int leftmax=0,rightmax=0;
        int ans=0;
        while(l<r){
            if(height[l]<=height[r]){
              if(height[l]>=leftmax){
               leftmax=height[l];
              }else{
                ans+=leftmax-height[l];
              }
              l++;
            }else{
              if(height[r]>=rightmax){
               rightmax=height[r];
              }else{
                ans+=rightmax-height[r];
              }
              r--;
            }
        }
        return ans;
    }
};