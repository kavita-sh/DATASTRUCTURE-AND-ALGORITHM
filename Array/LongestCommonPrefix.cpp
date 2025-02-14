//We have find common prefix of all the strings in the given array of strings. We can use the same approach as above to solve this problem. We can iterate through the first string and find the common prefix of the first string with the second string. Then we can find the common prefix of the first string with the third string and so on. The code snippet for the same is given below:


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
        return "";
        string s=strs[0];
        
        for(int i=1;i<strs.size();i++){
            int j=0;
            while(j<s.length() && j<strs[i].length() && s[j]==strs[i][j]){
                j++;
            }
            s= s.substr(0,j);
        }
        if(s.empty())
        return "";
        else 
        return s;
    }
};