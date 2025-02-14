//We have to find if the given two strings are anagrams of each other. We can use the same approach as above to solve this problem. We can use a hash map to store the frequency of each character in the first string. Then we can iterate through the second string and decrement the frequency of each character in the hash map. If we find any character whose frequency is less than 0, we can return false. Otherwise, we can return true. The code snippet for the same is given below:
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        return false;
        unordered_map<char,char>mp1,mp2;
        for(int i=0;i<s.size();i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        return mp1==mp2;
    }
};
