// Problem Link: https://leetcode.com/problems/longest-repeating-character-replacement/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0,n=s.size(),maxi=0,ans=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[s[j]]++;
            maxi= max(maxi,mp[s[j]]);
            if(j-i+1 -maxi<=k){
                ans=max(ans,j-i+1);
            }else{
                mp[s[i]]--;
                if(s[i]==0)
                mp.erase(s[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};