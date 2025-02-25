// We have to find the missing number in the array. We can use the XOR operation to find the missing number. The XOR operation is commutative and associative. We can iterate through the array and perform the XOR operation on all the elements. The XOR operation of a number with itself is 0. The XOR operation of a number with 0 is the number itself. The XOR operation of all the elements in the array will give the missing number. The code snippet for the same is given below:

#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int val=0;
            for(int i=0;i<nums.size();i++){
                val=val^nums[i];
                val=val^i;
            }
            val=val^nums.size();
            return val;
        }
    };