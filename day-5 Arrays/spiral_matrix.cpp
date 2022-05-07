/*
Spiral Matrix
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        int lc=0, rc=n-1, fr=0, lr=m-1;
        vector<int> res;
        while(lc<=rc && fr<=lr){

            for(int i=lc;i<=rc;i++){
                res.push_back(matrix[fr][i]);
            }
            fr++;

            for(int i=fr;i<=lr;i++){
                res.push_back(matrix[i][rc]);
            }
            rc--;
            if(fr<=lr) {
            for(int i=rc;i>=lc;i--){
                res.push_back(matrix[lr][i]);
            }
            lr--;}
            if(lc<=rc) {
            for(int i=lr;i>=fr;i--){
                res.push_back(matrix[i][lc]);
            }
            lc++;
            }
        }
        return res;
    }
};
