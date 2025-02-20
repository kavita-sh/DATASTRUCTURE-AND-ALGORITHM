//We have to find the majority element in the given array. The majority element is the element that appears more than n/2 times where n is the size of the array
//We can solve this problem using the Boyer-Moore Voting Algorithm. The algorithm is as follows:
//1. We maintain a count variable to keep track of the count of the majority element.
//2. We iterate through the array and if the count becomes zero, we update the majority element to the current element.
//3. If the current element is equal to the majority element, we increment the count, else we decrement the count.
//4. The majority element will be the element that remains after iterating through the array.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele= nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(ele==nums[i]){
                count++;
            }else{
                count--;
            }
            if(count==0){
                ele=nums[i];
                count=1;
            }
        }
        return ele;
    }
};