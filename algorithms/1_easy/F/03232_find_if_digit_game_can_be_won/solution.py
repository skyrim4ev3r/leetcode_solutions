class Solution:
    def canAliceWin(self, nums: List[int]) -> bool:
        balance = 0

        for num in nums:
            if num > 9:
                balance += num
            else:
                balance -= num

        return balance != 0
