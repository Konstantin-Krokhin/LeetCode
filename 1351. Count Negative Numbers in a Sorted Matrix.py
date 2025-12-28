class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        neg_nums = 0

        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] < 0:
                    neg_nums += 1
        
        return neg_nums
        