# CODE

class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        n = len(deck)
        i, j = 0, 0
        flag = False
        res = [0] * n
        deck.sort()

        while j < n:
            if res[i] == 0:
                if not flag:
                    res[i] = deck[j]
                    j += 1
                flag = not flag
            i = (i + 1) % n
        
        return res