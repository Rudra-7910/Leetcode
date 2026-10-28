class Solution {
public:
    int solve(int row, int col1, int col2,vector<vector<int>>& grid, vector<vector<vector<int>>>& dp,int n, int m) {
        if (col1 < 0 || col1 >= m ||
            col2 < 0 || col2 >= m) {
            return -100000000;
        }

        if (dp[row][col1][col2] != -1) {
            return dp[row][col1][col2];
        }
        int current = 0;
        if (col1 == col2) {
            current += grid[row][col1];
        } else {
            current += grid[row][col1];
            current += grid[row][col2];
        }
        if (row == n - 1) {
            dp[row][col1][col2] = current;
            return current;
        }
        int bestNext = -100000000;
        for (int d1 = -1; d1 <= 1; d1++) {

            for (int d2 = -1; d2 <= 1; d2++) {

                int nextCol1 = col1 + d1;
                int nextCol2 = col2 + d2;

                int next = solve(row + 1,nextCol1,nextCol2,grid,dp,n,m);
                if (next > bestNext) {
                    bestNext = next;
                }
            }
        }
        dp[row][col1][col2] = current + bestNext;
        return dp[row][col1][col2];
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(0, 0, m - 1, grid, dp, n, m);
    }
};