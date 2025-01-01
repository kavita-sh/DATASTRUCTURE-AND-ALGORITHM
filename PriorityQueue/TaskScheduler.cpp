// Problem: Task Scheduler
// Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
// However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.
// Return the least number of units of times that the CPU will take to finish all the given tasks.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        queue<pair<int,int>>q;
        int time=0;
        int a[26]={0};
        for(int i=0;i<tasks.size();i++){
           a[tasks[i]-'A']++;
        }
        for(int i=0;i<26;i++){
            if(a[i]>0)
            pq.push(a[i]);
        }
        while(!pq.empty() || !q.empty()){
            int f=0;
            time++;
            if(!pq.empty()){
            f = pq.top();
            f--;
            pq.pop();
            }
            
            if(f >0 )
            q.push({f,time+n});
            if(!q.empty() && q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }
            
        }
        return time;
    }
};