class Solution {
public:
    void dfs(vector<vector<char>>& grid, int m, int n)
    {
        if (m >= grid.size() || n >= grid[0].size() || m < 0 || n < 0 || grid[m][n] == '0') return;
        grid[m][n] = '0';

        dfs(grid, m + 1, n);
        dfs(grid, m - 1, n);
        dfs(grid, m, n + 1);
        dfs(grid, m, n - 1);
    }
    int numIslands(vector<vector<char>>& grid)
    {
        int m = 0, n = 0, island_count = 0;
        
        while (m < grid.size())
        {
            n = 0;
            while (n < grid[0].size())
            {
                if (grid[m][n] == '1')
                {
                    island_count++;
                    dfs(grid, m, n);
                }
                n++;
            }
            m++;
        }

        return island_count;
    }
};