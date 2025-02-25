// We have to count the number of 1 bits in the given number.
// We can use the AND operation to count the number of 1 bits in the given number. The AND operation of a number with 1 will give the number itself. The AND operation of a number with 0 will give 0. We can iterate through the bits of the number and perform the AND operation with 1. If the result is 1, then we increment the count. The code snippet for the same is given below:

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int hammingWeight(uint32_t n) {
            int count=0;
         while(n){
            count=count+(n&1);
            n=n>>1;
         }
         return count;
        }
    };
