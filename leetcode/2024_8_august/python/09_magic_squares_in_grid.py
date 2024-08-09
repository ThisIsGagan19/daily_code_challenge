# CODE

from typing import List

class Solution:
    def solve(self, row, col, grid):
        # check unique numbers from 0 - 9
        check = [0] * 10
        for i in range(3):
            for j in range(3):
                if ((grid[row + i][col + j]) < 1 or 
                    (grid[row + i][col + j]) > 9):
                    return False
                if check[grid[row + i][col + j]] != 0:
                    return False
                check[grid[row + i][col + j]] += 1
        
        # check sums
        # 1. diagonals
        d1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2]
        d2 = grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2]
        if d1 != d2:
            return False
        
        # 2. rows
        r1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2]
        r2 = grid[row + 1][col] + grid[row + 1][col + 1] + grid[row + 1][col + 2]
        r3 = grid[row + 2][col] + grid[row + 2][col + 1] + grid[row + 2][col + 2]
        if r1 != d1 or r2 != d1 or r3 != d1:
            return False
        
        # 3. cols
        c1 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col]
        c2 = grid[row][col + 1] + grid[row + 1][col + 1] + grid[row + 2][col + 1]
        c3 = grid[row][col + 2] + grid[row + 1][col + 2] + grid[row + 2][col + 2]
        if c1 != d1 or c2 != d1 or c3 != d1:
            return False

        return True

    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        m, n, res = len(grid), len(grid[0]), 0
        for row in range(m - 2):
            for col in range(n - 2):
                if self.solve(row, col, grid):
                    res += 1
        return res