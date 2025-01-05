//We have to find all the unique combinations of the elements in the array that sum up to the target.
//We will use backtracking to solve this problem.
//We will sort the array and then call the helper function with the target, the initial index, the size of the array, the array itself and the answer vector.
//In the helper function, if the target is 0, we will push the current combination into the answer vector.
//Otherwise, we will include the current element in the combination and call the helper function with the target reduced by the current element, the next index and the same combination.
//Then we will exclude the current element from the combination and call the helper function with the next index and the same target and combination.
//We will call the helper function with the initial index as 0 and an empty combination.
//We will return the answer vector.


#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void solve(vector<int>& candidates, int target,int i,int n,vector<vector<int>>&ans,vector<int>&ds){
            if(target==0){
                ans.push_back(ds);
                return;
            }          
            for(int j=i;j<n;j++){
                if(j!=i && candidates[j]==candidates[j-1])
                continue;
                if(candidates[j]<=target){
                    ds.push_back(candidates[j]);
               solve(candidates,target-candidates[j],j+1,n,ans,ds);
                    ds.pop_back();
                }   
            }     
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int i=0,n=candidates.size();
        vector<vector<int>>ans;
        vector<int>ds;
        solve(candidates,target,i,n,ans,ds);
        return ans;
    }
};