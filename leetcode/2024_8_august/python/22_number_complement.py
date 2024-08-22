# CODE

class Solution:
    def findComplement(self, num: int) -> int:
        mask = -1
        while(num & mask): mask <<= 1
        return ~num ^ mask