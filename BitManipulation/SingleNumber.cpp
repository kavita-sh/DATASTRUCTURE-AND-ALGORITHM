// We have to find the number that appears only once in the array. We can use the XOR operation to find the number that appears only once. The XOR operation is commutative and associative. We can iterate through the array and perform the XOR operation on all the elements. The XOR operation of a number with itself is 0. The XOR operation of a number with 0 is the number itself. The XOR operation of all the elements in the array will give the number that appears only once. The code snippet for the same is given below:

#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int val=0;
            for(int num:nums){
                val=val^num;
            }
            return val;
        }
    };