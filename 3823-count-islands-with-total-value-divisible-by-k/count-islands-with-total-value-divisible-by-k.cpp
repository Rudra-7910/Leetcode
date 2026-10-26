class Solution {
public:
long long sum =0;
bool dfs(vector<vector<int>> &grid, int startidx, int startcol, int k)
{
    int m= grid.size();
    int n= grid[0].size();
    if(startidx<0 || startidx >= m || startcol<0  || startcol >=n || grid[startidx][startcol]==0 )
    {
        return false;
    }
    sum= sum + grid[startidx][startcol];
    grid[startidx][startcol] = 0; //mark krde , 0 , 

        dfs(grid, startidx - 1, startcol, k);
        dfs(grid, startidx + 1, startcol, k);
        dfs(grid, startidx, startcol - 1, k);
        dfs(grid, startidx, startcol + 1, k);

        return sum % k == 0;

}


    int countIslands(vector<vector<int>>& grid, int k) {
        int count=0 ;
        int m= grid.size();
        int n= grid[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != 0)
                {
                    sum = 0;

                    if(dfs(grid, i, j, k) == true)
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};