//We have to count the number of 1 bits in the given number.
//We can use the AND operation to count the number of 1 bits in the given number. The AND operation of a number with 1 will give the number itself. The AND operation of a number with 0 will give 0. We can iterate through the bits of the number and perform the AND operation with 1. If the result is 1, then we increment the count. The code snippet for the same is given below:

#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> countBits(int n) {
            vector<int>v;
            for(int i=0;i<=n;i++){
                int count=0;
                int j=i;
                while(j){
                 j&=(j-1);
                 count++;
                }
                v.push_back(count);
            }
            return v;
        }
    };
    