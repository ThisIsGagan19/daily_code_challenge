# INTUITION
# Use backtracking, fill ones and then zeros according to condition

# CODE 

class Solution:
    def solve(self, i, countOne, countZero, num, n, res) -> None:
        if i >= n:
            res.append(num)
            return

        num += '1'
        self.solve(i + 1, countOne + 1, countZero, num, n, res)
        num = num[:-1]

        if countOne > countZero:
            num += '0'
            self.solve(i + 1, countOne, countZero + 1, num, n, res)
                               
    def NBitBinary(self, n):
        res = []
        num = ""
        self.solve(0, 0, 0, num, n, res)
        return res