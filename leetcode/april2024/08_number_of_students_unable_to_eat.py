class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        preferCircle = preferSquare = 0
        for s in students:
            if s == 1: preferSquare += 1
            else: preferCircle += 1
        for s in sandwiches:
            if s == 0 and preferCircle == 0:
                return preferSquare
            if s == 1 and preferSquare == 0:
                return preferCircle  
            if s == 1: preferSquare -= 1
            else: preferCircle -= 1
        return 0  