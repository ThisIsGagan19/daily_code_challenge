# CODE

class Solution:
    def largestRectangleArea(self, histogram):
        stack = deque()
        area = 0
        histogram.append(0)  # Append a sentinel to handle the end condition
        for i, height in enumerate(histogram):
            while stack and height <= histogram[stack[-1]]:
                h = histogram[stack.pop()]
                w = i if not stack else i - stack[-1] - 1
                area = max(area, h * w)
            stack.append(i)
        return area

    def maximalRectangle(self, matrix):
        maxArea = 0
        prefixHeight = [0] * len(matrix[0]) if matrix else []
        for row in matrix:
            for j, cell in enumerate(row):
                prefixHeight[j] = prefixHeight[j] + 1 if cell == '1' else 0
            maxArea = max(maxArea, self.largestRectangleArea(prefixHeight))
        return maxArea