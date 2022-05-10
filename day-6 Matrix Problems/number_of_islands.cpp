/*
Number of Islands
*/

class Solution {
public:

    int a1[4]={1,-1,0,0};
    int a2[4]={0,0,1,-1};

    bool isSafe(int i, int j, int m,int n){
        if(i>=0&&i<m&&j>=0&&j<n) return true;
        return false;
    }

    /*void bfs(vector<vector<char>>& grid, int i, int j, int m, int n, vector<vector<int>>& vis){
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x = p.first+a1[i];
                int y = p.second+a2[i];
                if(isSafe(x,y,m,n)&&vis[x][y]!=1&&grid[x][y]=='1'){
                    vis[x][y]=1;
                    q.push({x,y});
                }
            }

        }
    }
    */

    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n, vector<vector<int>>& vis){
        for(int k=0;k<4;k++){
            int x = i+a1[k];
            int y = j+a2[k];
            if(isSafe(x,y,m,n)&& vis[x][y]==0 && grid[x][y]=='1'){
                vis[x][y]=1;
                dfs(grid,x,y,m,n,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(),0));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && vis[i][j]==0) {
                    count++;
                    dfs(grid, i, j, grid.size(), grid[0].size(), vis);
                }
            }
        }
        return count;
    }
};
