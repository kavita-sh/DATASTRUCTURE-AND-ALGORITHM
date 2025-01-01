//
// Kth Largest Element in a Stream
// Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

#include<bits/stdc++.h>
using namespace std;

class KthLargest {
    private:
    priority_queue<int, vector<int> , greater<int>>mini;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto i:nums){
            mini.push(i);
            if(mini.size()>k)
            mini.pop();
        }
    }
    
    int add(int val) {
        mini.push(val);
        if(mini.size()>k)
        mini.pop();
        return mini.top();
    }
};