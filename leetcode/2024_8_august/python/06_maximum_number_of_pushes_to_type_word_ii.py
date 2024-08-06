# CODE

class Solution:
    def minimumPushes(self, word: str) -> int:
        alpha_cnt = [0] * 26
        for ch in word:
            alpha_cnt[ord(ch) - ord('a')] += 1
        cnts = sorted(alpha_cnt, reverse = True)
        res = 0
        for i, cnt in enumerate(cnts):
            if cnt == 0:
                break
            res += (i // 8 + 1) * cnt
        return res