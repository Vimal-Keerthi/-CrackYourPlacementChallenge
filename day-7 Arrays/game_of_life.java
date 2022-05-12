/*
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.
*/

class Solution {
    int a1[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int a2[] = {0, 0, -1, 1, -1, 1, -1, 1};
    public boolean isOneSafe(int i, int j, int[][] board, int m, int n) {
        int count = 0;
        for(int k=0;k<8;k++){
            if(i+a1[k]<0 || i+a1[k]>=m || j+a2[k]<0 || j+a2[k]>=n) continue;
            if(board[i+a1[k]][j+a2[k]]==1) count++;
        } 
        if(count == 2 || count == 3) return true;
        return false;
    }
    public boolean isZeroSafe(int i, int j, int[][] board, int m, int n) {
        int count = 0;
        for(int k=0;k<8;k++){
            if(i+a1[k]<0 || i+a1[k]>=m || j+a2[k]<0 || j+a2[k]>=n) continue;
            if(board[i+a1[k]][j+a2[k]]==1) count++;
        } 
        if(count == 3) return true;
        return false;
    }
    public void gameOfLife(int[][] board) {
        int m = board.length;
        int n = board[0].length;
        int[][] temp = new int[m][n];
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == 1 && isOneSafe(i,j,board, m, n))
                    temp[i][j] = 1;
            }
        } 
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(temp[i][j] == 0 && isZeroSafe(i,j,board, m, n))
                    temp[i][j] = 1;
            }
        }
        // System.out.println("===================================");
        // for(int i=0;i<m;i++) {
        //     for(int j=0;j<n;j++)
        //         System.out.print(temp[i][j]+" ");
        //     System.out.println();
        // }
        // System.out.println("===================================");
        for(int i=0;i<m;i++) {
            board[i] = temp[i].clone();
        }
    }
}