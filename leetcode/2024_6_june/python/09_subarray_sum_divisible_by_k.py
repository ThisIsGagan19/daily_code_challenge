# CODE

from typing import List
class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        cnt = 0
        prefix_sum = 0
        mod_map = {0: 1}
        for val in nums:
            prefix_sum += val
            mod = prefix_sum % k
            if mod < 0:
                mod += k
            if mod in mod_map:
                cnt += mod_map[mod]
                mod_map[mod] += 1
            else:
                mod_map[mod] = 1
        return cnt