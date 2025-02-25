//We have to find the bitwise AND of all the numbers in the range [left, right]. We can use the same approach as above to solve this problem.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int rangeBitwiseAnd(int left, int right) {
            while(left<right){
               right= right&(right-1); 
            }
            return right;
        }
    };