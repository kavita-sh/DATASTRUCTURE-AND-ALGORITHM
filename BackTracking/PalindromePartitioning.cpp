// we have to find all the possible partition of the string such that each partition is a palindrome
// We will use backtracking to solve this problem.
// We will have a helper function which will take the string, the current index, the current partition and the answer vector.
// If the current index is equal to the size of the string, we will push the current partition into the answer vector.
// Otherwise, we will check if the current substring is a palindrome.
// If it is, we will include the current substring in the partition and call the helper function with the next index.
// We will call the helper function with the initial index as 0 and an empty partition.
// We will return the answer vector.
// The time complexity of this approach is O(n*2^n) where n is the size of the string.
// The space complexity of this approach is O(n) where n is the size of the string.


#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool palindrome(string s, int strt,int end){
        while(strt<=end){
            if(s[strt++]!=s[end--])
            return false;
        }
        return true;
    }
    public:
   void solve(string s, vector<string>&res,vector<vector<string>>&ans,int ind){
     if(ind==s.size()){
        ans.push_back(res);
        return;
     }
     for(int i=ind;i<s.size();i++){
        if(palindrome(s,ind,i)){
         res.push_back(s.substr(ind,i-ind+1));
         solve(s,res,ans,i+1);
         res.pop_back();
        }
     }
   }
public:
    vector<vector<string>> partition(string s) {
        vector<string>res;
        vector<vector<string>>ans;
        solve(s,res,ans,0);
        return ans;
    }
};