class Solution:
    def minOperations(self, nums: List[int]) -> int:
        stack = []
        count = 0

        for num in nums:
            while stack and stack[-1] > num:
                stack.pop()
                count += 1

            if num == 0 or (stack and stack [-1] == num):
                continue

            stack.append(num)

        return count + len(stack) 
