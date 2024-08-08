# CODE

from typing import List

class Solution:
    def spiralMatrixIII(self, rows: int, cols: int, rStart: int, cStart: int) -> List[List[int]]:
        dirX = [0, 1, 0, -1]
        dirY = [1, 0, -1, 0]
        result = []

        cnt = 1
        n = dir = 0
        while n < rows * cols:
            
            # to generate spiral matrix, we have to follow 
            # sequence 1, 1, 2, 2, 3, 3, 4, 4, ...
            # thus, outside loop runs for 2 times.
            for _ in range(2):
                for _ in range(cnt):
                    if (rStart >= 0 and rStart < rows and cStart >= 0 and cStart < cols):
                        result.append([rStart, cStart])
                    rStart += dirX[dir]
                    cStart += dirY[dir]
                    
                # generate next direction
                dir = (dir + 1) % 4
            cnt += 1
            n = len(result)
        
        return result