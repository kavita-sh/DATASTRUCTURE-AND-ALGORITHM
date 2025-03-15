//We need to multiply two strings. 
//We will iterate through the strings from the end and multiply the numbers.
//We will store the result in a vector.
//We will iterate through the vector and add the numbers.
//We will iterate through the vector and add the carry.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string multiply(string num1, string num2) {
           if(num1=="0" || num2=="0"){
            return "0";
           } 
            int n= num1.size();
            int m= num2.size();
            vector<int>res(n+m,0);
            for(int i=n-1;i>=0;i--){
             for(int j=m-1;j>=0;j--){
                int mul = (num1[i]-'0')*(num2[j]-'0');
                int sum= mul+res[i+j+1];
    
                res[i+j+1]=sum%10;
                res[i+j]+=sum/10;
             }
            }
           string ans="";
           for(int i=0;i<res.size();i++){
              if(!(ans.empty() && res[i]==0)){
                ans = ans+ char(res[i]+'0');
              }
           }
           return ans;
        }
    };
    