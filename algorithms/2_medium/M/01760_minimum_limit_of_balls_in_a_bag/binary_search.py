class Solution:
    def minimumSize(self, nums: List[int], max_operations: int) -> int:
        high = max(nums)
        low = 1

        while low <= high:
            mid = low + (high - low) // 2
            op_left = max_operations

            for num in nums:
                if num > mid:
                    op_left = op_left - ((num + mid - 1) // mid) + 1

                if op_left < 0:
                    break

            if op_left < 0:
                low = mid + 1
            else:
                high = mid - 1

        return low
