# CODE

import copy
from typing import List

class Solution:
    def solve(self, i, j, m, n, grid):
        if grid[i][j] == 0:
            return 
        grid[i][j] = 0
        if i - 1 >= 0:
            self.solve(i - 1, j, m, n, grid)
        if i + 1 < m:
            self.solve(i + 1, j, m, n, grid)
        if j - 1 >= 0:
            self.solve(i, j - 1, m, n, grid)
        if j + 1 < n:
            self.solve(i, j + 1, m, n, grid)


    def island_count(self, grid):
        cnt = 0
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    cnt += 1
                    self.solve(i, j, m, n, grid)
        return cnt

    def minDays(self, grid: List[List[int]]) -> int:
        days = 0
        new_grid = copy.deepcopy(grid)
        cnt = self.island_count(new_grid)
        if cnt != 1:
            return days
        
        days = 1
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                new_grid = copy.deepcopy(grid)
                new_grid[i][j] = 0
                cnt = self.island_count(new_grid)
                if cnt != 1:
                    return days
        
        days = 2
        return days