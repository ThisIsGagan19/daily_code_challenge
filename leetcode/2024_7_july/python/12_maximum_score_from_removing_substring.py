# CODE

class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        res = 0
        bade = 'ab' if x > y else 'ba'
        chote = 'ba' if bade == 'ab' else 'ab'

        # remove substring function
        def remove(s, t):
            stk = []
            for ch in s:
                if (ch == t[1] and stk and stk[-1] == t[0]):
                    stk.pop()
                else:
                    stk.append(ch)
            return ''.join(stk)

        # first pass
        remove_pair_str = remove(s, bade)
        remove_pair_cnt = (len(s) - len(remove_pair_str)) // 2
        res += (remove_pair_cnt * max(x, y))

        # second pass
        s = remove(remove_pair_str, chote)
        remove_pair_cnt = (len(remove_pair_str) - len(s)) // 2
        res += (remove_pair_cnt * min(x, y))

        return res