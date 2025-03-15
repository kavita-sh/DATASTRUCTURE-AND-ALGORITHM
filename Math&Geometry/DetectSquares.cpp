//ou are given a stream of points consisting of x-y coordinates on a 2-D plane. Points can be added and queried as follows:

// Add - new points can be added to the stream into a data structure. Duplicate points are allowed and should be treated as separate points.
// Query - Given a single query point, count the number of ways to choose three additional points from the data structure such that the three points and the query point form a square. The square must have all sides parallel to the x-axis and y-axis, i.e. no diagonal squares are allowed. Recall that a square must have four equal sides.

#include <bits/stdc++.h>
using namespace std;

class CountSquares {

    public:
    unordered_map<int,unordered_map<int,int>>mp;
    unordered_set<int>xm;
        CountSquares() {
        }
        
        void add(vector<int> point) {
            int x=point[0],y=point[1];
            mp[x][y]++;
            xm.insert(x);
        }
        
        int count(vector<int> point) {
            int x= point[0],y=point[1];
            int res=0;
            for(auto dx:xm){
                if(dx==x)
                continue;
                int side= abs(dx-x);
                res+=mp[x][y+side]*mp[dx][y]*mp[dx][y+side];
                res+=mp[x][y-side]*mp[dx][y]*mp[dx][y-side];
            }
            return res;
        }
    };
    