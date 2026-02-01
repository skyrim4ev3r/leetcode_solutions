class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        curr_sum = 0
        res = []

        for num in nums:
            if (num & 1) == 0:
                curr_sum += num

        for q in queries:
            val = q[0]
            index = q[1]

            if (nums[index] & 1) == 0:
                curr_sum -= nums[index]

            nums[index] += val

            if (nums[index] & 1) == 0:
                curr_sum += nums[index]

            res.append(curr_sum)

        return res
