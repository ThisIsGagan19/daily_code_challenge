# CODE

from collections import deque

class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        dead = set(deadends)
        vis = set()
        q = deque(["0000"])
        vis.add("0000")

        if "0000" in dead: return -1

        res = 0
        while q:
            sz = len(q)
            for _ in range(sz):
                curr = q.popleft()

                if curr == target: return res
                if curr in dead: continue

                for i in range(4):
                    old = int(curr[i])

                    # clockwise rotation
                    new_clockwise = (old + 1) % 10
                    new_curr_clockwise = curr[:i] + str(new_clockwise) + curr[i + 1:]
                    if new_curr_clockwise not in dead and new_curr_clockwise not in vis:
                        q.append(new_curr_clockwise)
                        vis.add(new_curr_clockwise)

                    # anti-clockwise rotation
                    new_anticlockwise = (old - 1) % 10
                    new_curr_anticlockwise = curr[:i] + str(new_anticlockwise) + curr[i + 1:]
                    if new_curr_anticlockwise not in dead and new_curr_anticlockwise not in vis:
                        q.append(new_curr_anticlockwise)
                        vis.add(new_curr_anticlockwise)

            res += 1

        return -1