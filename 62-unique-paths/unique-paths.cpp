class Solution {
public:

int solve(int i, int j , int m , int n ,int &count, vector<vector<int>>& dp )
{
    if(i>=m || j>=n || i<0 || j<0)
    {
        return 0 ; 
    }

    if(dp[i][j] != -1)
    {
        count += dp[i][j];
        return dp[i][j];
    }

    if(i==m-1 && j== n-1)
    {
        count++ ; 
        return dp[i][j] = 1;
    }
    int before = count;
    solve(i+1,j,m,n,count,dp);
    solve(i,j+1,m,n,count,dp);

        dp[i][j] = count - before;
    return dp[i][j];
}
    int uniquePaths(int m, int n) {
        int count =0 ; 
    vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve (0,0,m,n,count,dp);
    }
};