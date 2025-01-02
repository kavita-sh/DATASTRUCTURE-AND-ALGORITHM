// Problem Link: https://leetcode.com/problems/3sum/
// The problem is to find all unique triplets in the array which gives the sum of zero.
// The solution is to sort the array and then iterate through the array and for each element we will find the other two elements using two pointers.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]>0)
             break;
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int m= i+1;
            int j= nums.size()-1;
            while(m<j){
                
                if(nums[i]+nums[m]+nums[j]==0){
                    ans.push_back({nums[i],nums[m],nums[j]});
                    m++;
                    j--;
                     while(m<j && nums[m]==nums[m-1])
                     m++;
                }else if(nums[i]+nums[m]+nums[j]>0){
                    j--;
                }else{
                    m++;
                }
               
            }
        }
        return ans;
    }
};