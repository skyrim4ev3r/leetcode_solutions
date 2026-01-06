class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        max_index = 0

        for i in range(n):
            if nums[i] > nums[max_index]:
                max_index = i

        res = [0] * n
        res[max_index] = -1
        index = n - 1 if max_index == 0 else max_index - 1
        stack = [nums[max_index]]

        while index != max_index:
            curr_num = nums[index]

            while stack and stack[-1] <= curr_num:
                stack.pop()

            if stack:
                res[index] = stack[-1]
            else:
                res[index] = -1

            if index == 0:
                index = n - 1
            else:
                index -= 1

            stack.append(curr_num)

        return res
