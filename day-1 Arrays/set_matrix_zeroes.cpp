/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<int> r(row,-1), c(col,-1);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    r[i]=0;
                    c[j]=0;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(r[i]==0 || c[j]==0) matrix[i][j]=0;
            }
        }
    }
};

TC: O(n^2)
