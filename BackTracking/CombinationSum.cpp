//We have to find all the combinations of a given array that sum up to a given target.
//We will use backtracking to solve this problem.
//We will have a helper function which will take the current index, the target, the array itself and the answer vector.
//If the current index is equal to the size of the array, we will check if the target is 0. If it is, we will push the current combination into the answer vector.
//Otherwise, we will include the current element in the combination and call the helper function with the same index and the target reduced by the current element.
//Then we will exclude the current element from the combination and call the helper function with the next index and the same target.
//We will call the helper function with the initial index as 0 and an empty combination.
//We will return the answer vector.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void solve(vector<int>& nums, int target,int i,vector<vector<int>>&ans,vector<int>&res){
        if(i==nums.size()){
        if(target==0){
            ans.push_back(res);
        }
        return;
    }  
      if(nums[i]<=target){
        res.push_back(nums[i]);
       solve(nums,target-nums[i],i,ans,res);
       res.pop_back();
       
    }
    solve(nums,target,i+1,ans,res);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>res;
        int i=0;
        solve(nums,target,i,ans,res);
        return ans;
    }
};
