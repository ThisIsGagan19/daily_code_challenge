# CODE

class Solution:
    def celebrity(self, matrix):
        num_people = len(matrix)
        for person_index, person_row in enumerate(matrix):
            knows_count = sum(person_row)
            known_by_count = sum([matrix[other_person][person_index] for other_person in range(num_people)])
            if knows_count == 0 and known_by_count == num_people - 1:
                return person_index
        return -1