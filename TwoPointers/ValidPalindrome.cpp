#include<cctype>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        for(char &ch:s){
            ch= tolower(ch);
        }
        int n= s.length();
        int i=0,j=n-1;
        while(i<=j){
        while(!isalnum(s[i])){
          i++;
        }
        while(!isalnum(s[j])){
            j--;
        }
        if(s[i]!=s[j] && i<=j){
        return false;
        }
        i++;
        j--;
        }
        return true;
    }
};