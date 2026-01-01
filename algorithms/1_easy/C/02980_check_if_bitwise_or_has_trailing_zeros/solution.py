class Solution:
    def hasTrailingZeros(self, nums: List[int]) -> bool:
        even_count = 0

        for num in nums:
            if (num & 1) == 0:
                even_count += 1

                if even_count > 1:
                    return True

        return False
