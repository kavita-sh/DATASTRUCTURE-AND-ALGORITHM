// A non-cyclical number is an integer defined by the following algorithm:

// Given a positive integer, replace it with the sum of the squares of its digits.
// Repeat the above step until the number equals 1, or it loops infinitely in a cycle which does not include 1.
// If it stops at 1, then the number is a non-cyclical number.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isHappy(int n) {
            unordered_set<int>st;
            int sum=0;
            while(n!=1 && st.find(n)==st.end()){
                st.insert(n);
                sum=0;
                int org=n;
            while(org!=0){
                int x= org%10;
                sum=sum+x*x;
                org=org/10;
            }
            n=sum;     
        }
        return n==1;   
        }
    };
    