// We have to find all the permutations of the given array.
// We will use backtracking to solve this problem.
// We will have a helper function which will take the current index, the array itself and the answer vector.
// If the current index is equal to the size of the array, we will push the current permutation into the answer vector.
// Otherwise, we will swap the current element with every element after it and call the helper function with the next index.
// We will call the helper function with the initial index as 0 and the array itself.



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