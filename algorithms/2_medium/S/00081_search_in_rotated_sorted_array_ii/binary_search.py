class Solution:
    def element_found(self, nums: List[int], x:int) -> bool:
        pos = bisect.bisect_left(nums, x)
        if pos != len(nums) and nums[pos] == x:
            return True
        return False

    def find_smallest_index(self, nums: List[int], n: int) -> int:
        left = 0
        right = n - 1

        while left < right:
            mid = left + (right - left) // 2

            if nums[mid] == nums[left] and nums[mid] == nums[right]:
                left += 1

                if nums[left - 1] > nums[left]:
                    return left
            elif nums[mid] >= nums[left]:
                left = mid + 1

                if nums[left - 1] > nums[left]:
                    return left
            else:
                right = mid - 1

                if nums[right] > nums[right + 1]:
                    return right + 1

        return left

    def search(self, nums: List[int], target: int) -> bool:
        n = len(nums)
        min_index = self.find_smallest_index(nums, n)

        return (
            self.element_found(nums[:min_index], target) or
            self.element_found(nums[min_index:], target)
        )
