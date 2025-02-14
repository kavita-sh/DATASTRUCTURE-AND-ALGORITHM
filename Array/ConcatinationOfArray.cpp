//We are given an integer array nums of length n. We need to return a new array result of length 2n where result[i] == nums[i] and result[i + n] == nums[i] for 0 <= i < n.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans;
        ans=nums;
        ans.insert(ans.end(),nums.begin(),nums.end());
        return ans;
    }
};