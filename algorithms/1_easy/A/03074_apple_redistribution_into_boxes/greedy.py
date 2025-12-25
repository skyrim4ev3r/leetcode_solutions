class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        total_apples = sum(apple)
        capacity.sort()
        count = 0

        while total_apples > 0:
            curr_capacity = capacity.pop()

            count += 1
            total_apples -= curr_capacity

        return count
