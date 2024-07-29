# CODE

from typing import List

class Solution:
    # for increasing teams
    def solve_L2R(self, index, size, L2R_cache, n, rating):

        # base cases
        if index == n:
            return 0
        if size == 3:
            return 1

        # memoized result
        if L2R_cache[index][size] != -1:
            return L2R_cache[index][size]
        
        # calculation
        res = 0
        for i in range(index + 1, n):
            if rating[i] > rating[index]:
                res += self.solve_L2R(i, size + 1, L2R_cache, n, rating)

        L2R_cache[index][size] = res
        return res

    # for decreasing teams
    def solve_R2L(self, index, size, R2L_cache, n, rating):

        # base cases
        if index == n:
            return 0
        if size == 3:
            return 1

        # memoized result
        if R2L_cache[index][size] != -1:
            return R2L_cache[index][size]
        
        # calculation
        res = 0
        for i in range(index + 1, n):
            if rating[i] < rating[index]:
                res += self.solve_R2L(i, size + 1, R2L_cache, n, rating)

        R2L_cache[index][size] = res
        return res

    # driver function
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        L2R_cache = [[-1] * 4 for _ in range(n)]
        R2L_cache = [[-1] * 4 for _ in range(n)]
        res = 0
        for i in range(n):
            res += (self.solve_L2R(i, 1, L2R_cache, n, rating) + 
                    self.solve_R2L(i, 1, R2L_cache, n, rating))
        return res