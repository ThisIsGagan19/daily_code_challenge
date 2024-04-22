# CODE

class Solution:
    def minRow(self, n, m, a):
        prefix_sum = []
        for row in a:
            prefix_sum.append(sum(row))
        return prefix_sum.index(min(prefix_sum)) + 1