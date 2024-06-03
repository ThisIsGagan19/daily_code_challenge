# CODE

class Solution:
    def reversedBits(self, x):
        return int(bin(x)[2:].zfill(32)[::-1], 2)