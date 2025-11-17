class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        curr_distance = k

        for num in nums:
            if num == 1:
                if curr_distance < k:
                    return False

                curr_distance = 0
            else:
                curr_distance += 1

        return True
