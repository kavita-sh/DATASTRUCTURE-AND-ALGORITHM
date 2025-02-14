//We have to find the indices of the two numbers such that they add up to a specific target. We can use a hash map to store the indices of the elements. We can iterate through the array and check if the difference between the target and the current element is present in the hash map. If it is present, we can return the indices of the two elements. Otherwise, we can insert the current element and its index into the hash map. The code snippet for the same is given below:

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                return {mp[target-nums[i]],i};
            }else{
                mp.insert({nums[i],i});
            }
        }
    }
};
