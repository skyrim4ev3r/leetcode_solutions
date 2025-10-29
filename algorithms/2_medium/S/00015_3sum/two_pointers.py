class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        nums.sort()

        res = []
        nums_len = len(nums)

        if nums[nums_len - 1] < 0:
            return res

        for left in range(nums_len - 2):
            if nums[left] > 0:
                break

            if left > 0 and (nums[left] == nums[left - 1] or abs(nums[left]) > nums[nums_len - 1] * 2):
                continue

            right = nums_len - 1
            mid = left + 1

            while mid < right:
                curr_sum = nums[left] + nums[mid] + nums[right];

                if curr_sum < 0:
                    mid += 1
                elif curr_sum > 0:
                    right -= 1
                else:
                    res.append([nums[left], nums[mid], nums[right]])

                    while True:
                        mid += 1

                        if mid >= right or nums[mid] != nums[mid - 1]:
                            break

        return res
