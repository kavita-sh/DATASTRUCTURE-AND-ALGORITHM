//We have to find the minimum window in the string s which contains all the characters of string t.
//We will use the sliding window technique to solve this problem.
//We will use two pointers i and j to traverse the string s.
//We will use two maps mp1 and mp2 to store the frequency of characters of string t and string s respectively.
//We will keep on increasing the window size by moving the pointer j until we get all the characters of string t in the window.
//Once we get all the characters of string t in the window, we will start decreasing the window size by moving the pointer i until we get all the characters of string t in the window.
//We will keep on updating the minimum length of the window and the answer string.
//Finally, we will return the answer string.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp1,mp2;
       int j=0,n = s.size(),i=0,len=INT_MAX,count=0;
       string ans;
        for(int i=0;i<t.size();i++){
            mp1[t[i]]++;
        }
        while(j<n){
            if(mp1.find(s[j])!= mp1.end()){
               mp2[s[j]]++;
               if(mp2[s[j]]<= mp1[s[j]])
               count++;
            }
            
            j++;
            while(count==t.size()){
              if(j-i<len){
                len= min(j-i,len);
                ans= s.substr(i,len);
              }
            if(mp1.find(s[i])!=mp1.end()){
                mp2[s[i]]--;
                if(mp2[s[i]]<mp1[s[i]])
                count--;
            }
            i++;
        }
        }

        return ans;
    }
};