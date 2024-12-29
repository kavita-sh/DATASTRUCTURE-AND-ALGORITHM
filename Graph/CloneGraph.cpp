#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node== NULL)
        return node;
       unordered_map<Node*, Node*> mp;
       queue<Node*> q;
       mp[node]= new Node(node->val);
       q.push(node);
       while(!q.empty()){
        Node* n= q.front();
        q.pop();
        for(auto i: n->neighbors){
          if(mp.find(i)==mp.end()){
            mp[i]=new Node(i->val);
            q.push(i);
          }
          mp[n]->neighbors.push_back(mp[i]);
        } 
       }
       return mp[node];
    }
};