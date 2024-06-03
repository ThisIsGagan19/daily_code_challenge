# INTUITION
# As we have to choose minimum number of arrows, we can take it like 
# we have to burst maximum no. of ballons with a single arrow possible.
# How?
# Just burst all the overlapping balloons with single arrow

# APPROACH
# 1. Sort the points.
# 2. Traverse in points array, for all points which are not overlapping
#    increment the result & choose current point as new window.
# 3. If overlapping points then readjust the overlapping window's end.
# 4. Finally return the result.

# TIME COMPLEXITY
# TC: O(n * log(n)) + O(n) - sorting + traversing

# SPACE COMPLEXITY
# SC: O(1)

# CODE

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        res = 1
        points.sort()
        end = points[0][1]
        for i in range(1, len(points)):
            if points[i][0] > end:
                res += 1
                end = points[i][1]
            end = min(points[i][1], end)
        return res