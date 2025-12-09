class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        shift_count = 0

        while right != left:
            shift_count += 1
            right = right >> 1
            left = left >> 1

        return right << shift_count
