//we have to find all the subsets of the given array with duplicates
//We will use backtracking to solve this problem.
//We will sort the array and then call the helper function with the initial index, the array itself and the answer vector.
//In the helper function, we will push the current subset into the answer vector.
//Then we will include the current element in the subset and call the helper function with the next index.
//Then we will exclude the current element from the subset and call the helper function with the next index.
//We will call the helper function with the initial index as 0 and an empty subset.
//We will return the answer vector.


#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void solve(vector<int>&nums,vector<int>&res,int i,vector<vector<int>>&ans){
        
        ans.push_back(res);
        
    
     for(int j=i;j<nums.size();j++){
        if(j!=i && nums[j]==nums[j-1])
        continue;

        res.push_back(nums[j]);
        solve(nums,res,j+1,ans);
        res.pop_back();
       
     }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        int i=0;
        sort(nums.begin(),nums.end());
        solve(nums,res,i,ans);

        return ans;
    }
};