// Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:


#include<bits/stdc++.h>
using namespace std;

class Twitter {
    int count;
    unordered_map<int,vector<pair<int,int>>>tweet;
    unordered_map<int,set<int>>fol;
public:
    Twitter() {
        count=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({count++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>ans;
        addtweettoheap(userId,pq);
        if(fol.count(userId)){
            for(auto i :fol[userId]){
                if(i!=userId)
                addtweettoheap(i,pq);
            }
            
        }

        while(!pq.empty()){
            int c= pq.top().first;
            int t= pq.top().second;
            ans.push_back(t);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        fol[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(fol.count(followerId))
        fol[followerId].erase(followeeId);
    }
    void addtweettoheap(int userId,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>&pq){

        if(tweet.count(userId)){
            for(auto i : tweet[userId]){
                pq.push(i);
                if(pq.size()>10){
                    pq.pop();
                }
            }
        }
    } 
};