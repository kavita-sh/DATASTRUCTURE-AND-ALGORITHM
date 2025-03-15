//We have to set the entire row and column of the matrix to zero if we encounter a zero at that position.
//We can do this by keeping a boolean variable to check if the first row and first column has zero or not.
//If the first row has zero then we will set the first row to zero.
//If the first column has zero then we will set the first column to zero.
//We will iterate through the matrix and if we encounter a zero then we will set the first row and first column to zero.
//Then we will set the entire row and column to zero if the first row and first column is zero.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int n= matrix.size();
            int m= matrix[0].size();
            bool rowzero=false,colzero=false;
            for(int i=0;i<n;i++){
               if(matrix[i][0]==0){
               colzero=true;
               break;}
            }
            for(int i=0;i<m;i++){
                if(matrix[0][i]==0){
                rowzero=true;
                break;}
            }
            for(int i=1;i<n;i++){
                for(int j=1;j<m;j++){
                    if(matrix[i][j]==0){
                        matrix[i][0]=0;
                        matrix[0][j]=0;
                    }
                }
            }
            for(int i=1;i<n;i++){
              if(matrix[i][0]==0){
                for(int j=1;j<m;j++){
                    matrix[i][j]=0;
                }
              }
            }
            for(int i=1;i<m;i++){
                if(matrix[0][i]==0){
                for(int j=1;j<n;j++){
                    matrix[j][i]=0;
                }
             }
            }
            if(rowzero){
                for(int i=0;i<m;i++){
                    matrix[0][i]=0;
                }
            }
            if(colzero){
                for(int i=0;i<n;i++){
                    matrix[i][0]=0;
                }
            }
        }
    };
    