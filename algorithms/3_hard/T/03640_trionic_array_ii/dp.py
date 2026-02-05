class Solution:
    def maxSumTrionic(self, nums: List[int]) -> int:
        n = len(nums)
        prev_state = [None, None, None]
        curr_state = [None, None, None]
        res = None

        for i in range(1, n):
            if prev_state[0] == None:
                if nums[i - 1] < nums[i]:
                    curr_state[0] = nums[i - 1] + nums[i]
                else:
                    curr_state[0] = None
            else:
                if nums[i - 1] < nums[i]:
                    curr_state[0] =  max(nums[i - 1], prev_state[0]) + nums[i]
                else:
                    curr_state[0] = None

            if prev_state[1] == None:
                if nums[i - 1] > nums[i]:
                    if prev_state[0] == None:
                        curr_state[1] = None
                    else:
                        curr_state[1] = prev_state[0] + nums[i]
                else:
                    curr_state[1] = None
            else:
                if nums[i - 1] > nums[i]:
                    curr_state[1] = prev_state[1] + nums[i]
                else:
                    curr_state[1] = None

            if prev_state[2] == None:
                if nums[i - 1] < nums[i]:
                    if prev_state[1] == None:
                        curr_state[2] = None
                    else:
                        curr_state[2] = prev_state[1] + nums[i]
                else:
                    curr_state[2] = None
            else:
                if nums[i - 1] < nums[i]:
                    curr_state[2] = prev_state[2] + nums[i]
                else:
                    curr_state[2] = None

            if curr_state[2] != None:
                if res == None:
                    res = curr_state[2]
                else:
                    res = max(res, curr_state[2])

            prev_state = curr_state.copy()

        if res == None:
            raise Exception("unreachable!") # It is guaranteed that at least one trionic subarray exists

        return res
