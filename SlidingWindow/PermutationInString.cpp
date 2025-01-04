// Problem Link: https://leetcode.com/problems/permutation-in-string/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s= s1.size();
        map<char,int>mp1,mp2;
        int n=s2.size(),i=0,j=s;
        for(int i=0;i<s1.size();i++){
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        while(j<n){
         if(mp1!=mp2){
           mp2[s2[i]]--;
           
           if(mp2[s2[i]]==0){
           mp2.erase(mp2[s2[i]]);
           }
           i++;
           mp2[s2[j]]++;
         }else{
            return true;
         }
         j++;
        }
        return mp1==mp2;
    }
};