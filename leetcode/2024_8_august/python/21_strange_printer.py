# INTUITION
# 1. If we print, a or aaa it will require only 1 turn in both cases, just
#    just cut down or remove the repetitive characters.
# 2. If you take the case like 'aba' then it the answer will always be a + 'remaining string' + a
#    means 1 + remaining string answer. Hence, first and end character if same constitute in single
#    answer.
# 3. Great!! Now apply DP that's it problem solved :)


# TIME COMPLEXITY
# O(n ^ 3)


# SPACE COMPLEXITY
# O(n ^ 2)


# CODE 

import re

class Solution:
    def strangePrinter(self, s: str) -> int:
        s = re.sub(r'(.)\1*', r'\1', s)
        cache = {}
        
        def solve(start, end):
            if start > end:
                return 0
            
            if (start, end) in cache:
                return cache[(start, end)]

            # each character separately
            res = 1 + solve(start + 1, end)

            # search for the matches to split the string
            for i in range(start + 1, end + 1):
                if s[i] == s[start]:
                    matched_character_res = solve(start, i - 1) + solve(i + 1, end)
                    res = min(res, matched_character_res)

            cache[(start, end)] = res
            return res

        return solve(0, len(s) - 1)