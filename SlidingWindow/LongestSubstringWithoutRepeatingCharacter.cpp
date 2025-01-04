// Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int l=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
           while(st.find(s[i])!=st.end()){
            st.erase(s[l]);
            l++;
           }
              st.insert(s[i]);
           
           int len= st.size();
           ans= max(ans,i-l+1);
        }
        return ans;
    }
};