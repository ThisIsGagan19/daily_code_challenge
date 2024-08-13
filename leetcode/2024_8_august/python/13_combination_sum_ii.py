# CODE 

from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()
        
        def solve(idx, path, sum, res, candidates):
            if sum <= 0:
                if sum == 0:
                    res.append(path)
                return 
            for i in range(idx, len(candidates)):
                if i == idx or candidates[i] != candidates[i - 1]:
                    solve(i + 1, path + [candidates[i]], sum - candidates[i], res, candidates)

        solve(0, [], target, res, candidates)
        return res         