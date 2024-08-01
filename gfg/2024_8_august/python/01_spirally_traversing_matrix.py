# CODE

class Solution:
    def spirallyTraverse(self, matrix):
        result=[]
        while matrix:
            result.extend(matrix.pop(0))
            matrix=list(zip(*matrix))[::-1]
        return result