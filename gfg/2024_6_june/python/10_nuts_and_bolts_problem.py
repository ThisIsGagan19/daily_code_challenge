# CODE

class Solution:
    def matchPairs(self, n, nuts, bolts):
        matching_order = ['!', '#', '$', '%', '&', '*', '?', '@', '^']
        nut_sack = set(nuts)
        res = [ch for ch in matching_order if ch in nut_sack]
        nuts[:] = res
        bolts[:] = res