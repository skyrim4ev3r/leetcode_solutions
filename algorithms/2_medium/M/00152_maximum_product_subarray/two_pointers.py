class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        left = 0
        prod = 1
        max_prod = -sys.maxsize -1

        for right in range(n):
            if nums[right] == 0:
                max_prod = max(max_prod, 0)
                left = right + 1
                prod = 1
            else:
                prod *= nums[right]
                max_prod = max(max_prod, prod)

                if right + 1 == n or nums[right + 1] == 0:
                    while left < right:
                        prod //= nums[left]
                        max_prod = max(max_prod, prod)
                        left += 1

        return max_prod
