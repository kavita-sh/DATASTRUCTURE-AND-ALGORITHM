// we have to find the minimum size of subarray whose sum is greater than or equal to target
// we will use sliding window technique to solve this problem.
// we will use two pointers i and j to traverse the array.
// we will keep on increasing the window size by moving the pointer j until we get the sum greater than or equal to target.
// once we get the sum greater than or equal to target, we will start decreasing the window size by moving the pointer i until we get the sum greater than or equal to target.
// we will keep on updating the minimum size of the subarray.
// finally, we will return the minimum size of the subarray.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,mini=INT_MAX,n=nums.size();
        int sum=0;
        while(j<n){
           sum+=nums[j];
           while(sum>=target){
            mini =min(mini,j-i+1);
            sum-=nums[i];
            i++;
            // mini =min(mini,j-i+1);
           }
           j++;
        }
        if(mini==INT_MAX)
        return 0;
        return mini;
    }
};