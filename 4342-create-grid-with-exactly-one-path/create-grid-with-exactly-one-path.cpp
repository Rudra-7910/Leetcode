class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid (m,string(n,'#') );

        int row = 0 ; 
        int col = 0 ; 
        grid[0][0] = '.';
        while(row<m-1 || col<n-1)
        {
            if(col<n-1)
            {
                col++;
                grid[row][col]='.';
            }

            if(row<m-1)
            {
                row++;
                grid[row][col]='.';
            }
        }

        return grid;
    }
};