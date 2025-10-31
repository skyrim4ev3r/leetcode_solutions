class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:

        if num_people == 1:
            return [candies]

        res = [0] * num_people
        curr_count = 1
        curr_index = 0

        while candies > 0:
            res[curr_index] += min(curr_count, candies)
            candies -= curr_count
            curr_count += 1
            curr_index += 1

            if curr_index == num_people:
                curr_index = 0

        return res
