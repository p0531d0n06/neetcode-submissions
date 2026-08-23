class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        maxA = 0

        def visitIsland(i, j) -> int:
            area = 1
            grid[i][j] = 0
            if i>0 and grid[i-1][j] != 0:
                area += visitIsland(i-1, j)
            if j>0 and grid[i][j-1] != 0:
                area += visitIsland(i, j-1)
            if i<len(grid) - 1 and grid[i+1][j] != 0:
                area += visitIsland(i+1, j)
            if j<len(grid[i]) - 1 and grid[i][j+1] != 0:
                area += visitIsland(i, j+1) 
            return area

        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    maxA = max(maxA, visitIsland(i,j))
        
        return maxA
                