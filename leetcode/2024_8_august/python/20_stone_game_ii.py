# CODE

class Solution:
    def solve(self, turn, index, m, piles, cache):
        if index == len(piles):
            return 0

        key = f"{turn}${index}#{m}"
        if key in cache:
            return cache[key]

        if turn:
            currRes = 0
        else:
            currRes = float('inf')

        total = 0

        for i in range(1, 2 * m + 1):
            if index + i > len(piles):
                break
            total += piles[index + i - 1]

            if turn:
                currRes = max(currRes, total + self.solve(not turn, index + i, max(m, i), piles, cache))
            else:
                currRes = min(currRes, self.solve(not turn, index + i, max(m, i), piles, cache))

        cache[key] = currRes
        return currRes

    def stoneGameII(self, piles):
        cache = {}
        return self.solve(True, 0, 1, piles, cache)