// We have a vector of integers. We have to add one to the number represented by the vector.
// We will iterate through the vector from the end and keep on adding one to the number.
// If the number is less than 9, we will add one and return the vector.
// If the number is 9, we will set the number to zero and move to the next number.
// If we reach the beginning of the vector and the number is 9, we will set the number to zero and insert 1 at the beginning of the vector

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int n = digits.size();
            for(int i=n-1;i>=0;i--){
                if(digits[i]<9){
                    digits[i]++;
                    return digits;
                }
                digits[i]=0;
            }
            digits.insert(digits.begin(),1);
            return digits;
        }
    };