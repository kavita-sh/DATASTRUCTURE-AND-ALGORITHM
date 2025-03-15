//We have to find x^n in O(logn) time complexity
//We can do this by using the concept of binary exponentiation
//We can write n as a sum of powers of 2


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        double myPow(double x, int n) {
            double res=1.0;
            int org=n;
            if(org<0){
                x= 1/x;
                org=-org;
            }
            while(org>0){
                if(org%2==1)
                res*=x;
    
                x*=x;
                org=org/2;
            }
            return res;
        }
    };
    