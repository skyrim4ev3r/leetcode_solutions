INT_MIN = -sys.maxsize - 1

class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        curr_max = INT_MIN
        hashmap = {}
        stack = []

        for num in reversed(nums2):
            while stack and stack[-1] < num:
                stack.pop()

            if stack:
                hashmap[num] = stack[-1]
            else:
                hashmap[num] = -1

            stack.append(num)

        res = []

        for num in nums1:
            res.append(hashmap[num])

        return res
