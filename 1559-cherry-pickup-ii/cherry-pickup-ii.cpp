class Solution {
    static constexpr int NEG = -100000000;
    vector<vector<vector<int>>> dp;
    int solve(int row, int col1, int col2,vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (col1 < 0 || col1 >= cols ||
            col2 < 0 || col2 >= cols) {
            return NEG;
        }
        if (dp[row][col1][col2] != -1) {
            return dp[row][col1][col2];
        }
        int current = grid[row][col1];

        if (col1 != col2) {
            current += grid[row][col2];
        }

        if (row == rows - 1) {
            return dp[row][col1][col2] = current;
        }

        int bestNext = NEG;

        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {

                int next = solve(
                    row + 1,
                    col1 + d1,
                    col2 + d2,
                    grid
                );

                bestNext = max(bestNext, next);
            }
        }

        return dp[row][col1][col2] = current + bestNext;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        dp.assign(
            rows,
            vector<vector<int>>(
                cols,
                vector<int>(cols, -1)
            )
        );

        return solve(0, 0, cols - 1, grid);
    }
};