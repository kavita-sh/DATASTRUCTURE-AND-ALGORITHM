//We have to reverse the bits of the given number.
//We can use the AND operation to reverse the bits of the given number. The AND operation of a number with 1 will give the number itself. The AND operation of a number with 0 will give 0. We can iterate through the bits of the number and perform the AND operation with 1. If the result is 1, then we set the bit at the corresponding position in the result. The code snippet for the same is given below:

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            uint32_t result=0;
            for(int i=0;i<32;i++){
                result =  (result<<1) | (n&1);
                n=n>>1;
            }
            return result;
        }
    };
