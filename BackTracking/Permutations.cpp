// We have to find all the permutations of the given array.
// We will use backtracking to solve this problem.
// We will have a helper function which will take the current index, the array itself and the answer vector.
// If the current index is equal to the size of the array, we will push the current permutation into the answer vector.
// Otherwise, we will swap the current element with every element after it and call the helper function with the next index.
// We will call the helper function with the initial index as 0 and the array itself.
// We will return the answer vector.


#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void solve(vector<int>&nums,int i,vector<vector<int>>&ans,vector<int>&res){
       if(i==nums.size()){
        ans.push_back(nums);
        return;
       }
       for(int j=i;j<nums.size();j++){
        swap(nums[j],nums[i]);
        solve(nums,i+1,ans,res);
        swap(nums[j],nums[i]);
        }
       
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        int i=0,n= nums.size();
        solve(nums,i,ans,res);
        return ans;
    }
};
