#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxi;
        for(int i=0;i<stones.size();i++){
            maxi.push(stones[i]);
        }
        while(maxi.size()>1){
            int x= maxi.top(); maxi.pop();
            int y= maxi.top();maxi.pop();
            if(x-y>0)
            maxi.push(x-y);
        }
        if(maxi.size()==1)
        return maxi.top();
        else
        return 0;
    }
};
