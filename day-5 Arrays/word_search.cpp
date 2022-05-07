/*
word search
*/

class Solution {
public:

    bool search(int i, int j, vector<vector<char>>& board, string str, int idx, vector<vector<int>>& vis) {
        if(idx==str.size()) return true;
        if(i>=board.size() || j>=board[0].size()) return false;
        else if(vis[i][j]!=1 && str[idx] == board[i][j]) {
            vis[i][j]=1;
            bool res = search(i+1, j, board, str, idx+1, vis) || search(i, j+1, board, str, idx+1, vis) || search(i-1,j,board, str,idx+1, vis) || search(i, j-1, board, str, idx+1, vis);
            vis[i][j]=-1;
            return res;
        }
        else return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), -1));
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(search(i,j,board, word, 0, vis)) return true;
            }
        }
        return false;
    }
};
