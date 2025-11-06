class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        res = []

        for num in nums:
            tmp_list = []
            while num > 0:
                tmp_list.append(num % 10)
                num //= 10
            res += tmp_list[-1::-1]

        return res
