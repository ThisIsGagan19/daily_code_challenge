# CODE

class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        if tickets[k] == 1: return k + 1
        n = len(tickets)
        res = 0
        while tickets[k] > 0:
            for i in range(n):
                if tickets[i] != 0:
                    tickets[i] -= 1
                    res += 1
                if tickets[k] == 0: return res
        return res