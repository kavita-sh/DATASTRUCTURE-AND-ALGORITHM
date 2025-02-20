// We have to remove the given element from the array. We can use two pointers to solve this problem. We can iterate through the array and if we find the element to be removed, we can skip that element. Otherwise, we can copy the element to the next position. The code snippet for the same is given below:

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[j++]=nums[i];
            }
        }
        return j;
    }
};