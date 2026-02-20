class Solution:
    def mergeAdjacent(self, nums: List[int]) -> List[int]:
        stack = []

        for num in nums:
            temp = num

            while stack and stack[-1] == temp:
                temp *= 2
                stack.pop()

            stack.append(temp)

        return stack
