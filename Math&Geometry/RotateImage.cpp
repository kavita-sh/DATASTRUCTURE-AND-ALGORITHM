//We have to rotate the image by 90 degrees in clockwise direction.
//We can do this by taking the transpose of the matrix and then reversing the rows of the matrix.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int n= matrix.size();
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                   swap(matrix[i][j],matrix[j][i]); 
                }
            }
            for(int i=0;i<n;i++){
                reverse(matrix[i].begin(),matrix[i].end());
            }
        }
    };