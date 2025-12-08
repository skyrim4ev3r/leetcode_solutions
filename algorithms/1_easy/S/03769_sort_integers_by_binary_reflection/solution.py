class Solution:
    def sortByReflection(self, nums: List[int]) -> List[int]:
        def manual_rev_bin(num):
            rev = 0

            while num > 0:
                rev = rev << 1
                rev |= (num & 1)
                num = num >> 1

            return rev

        nums.sort(key=lambda x: (manual_rev_bin(x), x))

        return nums
