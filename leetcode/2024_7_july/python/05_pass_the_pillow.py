# CODE

class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        time = time % (n * 2 - 2)
        return time + 1 if time < n - 1 else n - (time - (n - 1))