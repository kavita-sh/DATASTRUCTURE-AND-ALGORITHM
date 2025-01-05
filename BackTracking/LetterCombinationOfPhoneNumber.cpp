//we have to find all possible letter combinations that the number could represent
//We will use backtracking to solve this problem.
//We will have a helper function which will take the digits, the answer vector, the current string and the mapping of the digits to the letters.
//If the index is equal to the size of the digits, we will push the current string into the answer vector.
//Otherwise, we will get the letters corresponding to the current digit and call the helper function with the next index.
//We will call the helper function with the digits, an empty answer vector, an empty string and the mapping of the digits to the letters.
//We will return the answer vector.
//The time complexity of this approach is O(4^n) where n is the number of digits.
//The space complexity of this approach is O(4^n) where n is the number of digits.


#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void solve(string digits,vector<string>&ans,string &s,vector<string>&mp,int ind){
     if(ind==digits.size()){
        ans.push_back(s);
        return;
     }
        string d= mp[digits[ind]-'0'];
        for(auto i:d){
            s.push_back(i);
            solve(digits,ans,s,mp,ind+1);
            s.pop_back();
        }
     
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string s;
        if(digits.size()==0)
        return {};
        vector<string>mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,ans,s,mp,0);
        return ans;
    }
};
