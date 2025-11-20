class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n

        for i in range(n):
            curr = nums[i]

            if curr != 0:
                steps = abs(curr) % n

                if curr < 0:
                    steps *= -1

                target_index = i + steps

                if target_index < 0:
                    target_index += n
                elif target_index >= n:
                    target_index -= n

                res[i] = nums[target_index]

        return res
