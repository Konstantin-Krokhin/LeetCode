class Solution:

    def count_island(self, x, y, grid):
        if x < 0 or x >= len(grid) or y < 0 or y >= len(grid[0]) or grid[x][y] == "0":
            return 0
        
        grid[x][y] = "0"

        self.count_island(x - 1, y, grid)
        self.count_island(x + 1, y, grid)
        self.count_island(x, y - 1, grid)
        self.count_island(x, y + 1, grid)

    def numIslands(self, grid: List[List[str]]) -> int:
        islands = 0

        for x in range(len(grid)):
            for y in range(len(grid[0])):
                if grid[x][y] == "1":
                    islands += 1
                    self.count_island(x, y, grid)

        return islands
        
                                    