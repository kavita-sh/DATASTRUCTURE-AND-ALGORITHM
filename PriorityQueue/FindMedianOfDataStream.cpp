//we will use two priority queues to store the elements of the stream. The first priority queue will store the first half of the stream in decreasing order. The second priority queue will store the second half of the stream in increasing order. The median will be the top element of the first priority queue if the size of the first priority queue is greater than the size of the second priority queue. Otherwise, the median will be the average of the top elements of the first and second priority queues.

#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
    priority_queue<int> a;
    priority_queue<int,vector<int>,greater<int>>b;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        a.push(num);

        b.push(a.top());
        a.pop();
        if(a.size()<b.size()){
            a.push(b.top());
            b.pop();
        }
    }
    
    double findMedian() {
        if(a.size()>b.size())
        return a.top()*1.0;
        else
        return (a.top()+b.top())/2.0;
    }
};
