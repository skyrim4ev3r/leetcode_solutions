class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        nums = [a, b, c]
        nums.sort()

        diff1 = nums[1] - nums[0] - 1
        diff2 = nums[2] - nums[1] - 1

        min_move = 0 if diff1 == 0 and diff2 == 0 else (2 if diff1 > 1 and diff2 > 1 else 1)
        max_move = diff1 + diff2

        return [min_move, max_move]
