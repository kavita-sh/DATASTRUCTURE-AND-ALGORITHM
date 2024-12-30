// Problem: Word Ladder
// Given two words beginWord and endWord, and a dictionary wordList, return the length of the shortest transformation sequence from beginWord to endWord, such that:
// Only one letter can be changed at a time.
// Each transformed word must exist in the wordList.
// Return 0 if there is no such transformation sequence.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        if(st.find(endWord)==st.end())
        return 0;
        while(!q.empty()){
            string word = q.front().first;
            int c= q.front().second;
            q.pop();
            if(word==endWord){
                return c;
            }
            for(int i=0;i<word.size();i++){
                char org= word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,c+1});
                      st.erase(word);
                    }
                      
                }
                word[i]=org;
            }
        }
        return 0;
    }
};