// we will use sliding window technique to solve this problem.
// We will use two pointers i and j to traverse the array.
// We will use a map to store the frequency of elements in the window.
// We will keep on increasing the window size by moving the pointer j until we get k elements in the window.
// Once we get k elements in the window, we will start decreasing the window size by moving the pointer i until we get k elements in the window.
// We will keep on updating the maximum element in the window.
// Finally, we will return the answer vector.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
       ans.push_back(mp.rbegin()->first);
      int i=0,j=k,n= nums.size();
      while(j<n){
        mp[nums[i]]--;
        if(mp[nums[i]]==0){
            mp.erase(nums[i]);
        }
        i++;
        mp[nums[j]]++;
        j++;
        ans.push_back(mp.rbegin()->first);
      }
    return ans;
    }
};