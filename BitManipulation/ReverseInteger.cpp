//We have to reverse the given integer. If the reversed integer is out of the range of 32-bit signed integer, then return 0.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int reverse(int x) {
            int n=0;
            while(x!=0){
            int r= x%10;
            if(n> INT_MAX/10 || (n==INT_MAX && r>7)) return 0;
            if(n< INT_MIN/10 || (n==INT_MIN && r<-8)) return 0;
            n= (n*10)+r;
            x=x/10;
            }
            return n; 
        }
    };
    