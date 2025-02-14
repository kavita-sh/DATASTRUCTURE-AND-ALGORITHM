//We have to find if there are any duplicate elements in the given array. We can use the same approach as above to solve this problem. We can use a hash map to store the frequency of each element in the array. If we find any element whose frequency is greater than 1, we can return true. Otherwise, we can return false. The code snippet for the same is given below:
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
      unordered_map<int,int>mp;
      for(int i=0;i<nums.size();i++){
      if(mp.find(nums[i])==mp.end()){
        mp[nums[i]]++;
      }
      else{
        return true;
        }
      }
      return false;
    }
};
