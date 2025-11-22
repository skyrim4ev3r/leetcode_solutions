class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        zeros = students.count(0)
        ones = len(students) - zeros

        for sandwich in sandwiches:
            if sandwich == 1:
                if ones > 0:
                    ones -= 1
                else:
                    break
            elif sandwich == 0:
                if zeros > 0:
                    zeros -= 1
                else:
                    break

        return ones + zeros
