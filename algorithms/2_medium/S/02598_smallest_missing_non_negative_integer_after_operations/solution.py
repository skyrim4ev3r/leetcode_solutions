class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        
        remainders = [0] * value

        for num in nums:
            index = abs(num) % value

            # Adjust index for negative numbers
            if index != 0 and num < 0:
                index = value - index

            remainders[index] += 1

        res = 0
        curr_reminder_index = 0

        while remainders[curr_reminder_index] != 0:
            remainders[curr_reminder_index] -= 1
            res += 1
            curr_reminder_index += 1

            if curr_reminder_index == value:
                curr_reminder_index = 0

        return res
