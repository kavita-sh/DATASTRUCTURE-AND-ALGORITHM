// We have to find all the subsets of a given array.
// We will use backtracking to solve this problem.
// We will have a helper function which will take the current index, the size of the array, the array itself and the answer vector.
// If the current index is equal to the size of the array, we will push the current subset into the answer vector.
// Otherwise, we will include the current element in the subset and call the helper function with the next index.
// Then we will exclude the current element from the subset and call the helper function with the next index.
// We will call the helper function with the initial index as 0 and an empty subset.
// We will return the answer vector.
// The time complexity of this approach is O(2^n) where n is the size of the array.
// The space complexity of this approach is O(2^n) where n is the size of the array.    


#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void solve(vector<int>& nums,int i,int n,vector<vector<int>>&ans,vector<int>&res){
        if(i==n){
            ans.push_back(res);
            return;
        }
        res.push_back(nums[i]);
        solve(nums,i+1,n,ans,res);
        res.pop_back();
        solve(nums,i+1,n,ans,res);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> res;
        int n= nums.size();
        solve(nums,0,n,ans,res);
        return ans;
    }
};
