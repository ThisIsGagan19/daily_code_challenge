# CODE

from typing import List

class Solution:
    def countSeniors(self, details: List[str]) -> int:
        res = 0
        for val in details:
            age = int(val[11:13])
            if age > 60:
                res += 1
        return res