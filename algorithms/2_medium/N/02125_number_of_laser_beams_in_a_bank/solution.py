class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:

        prev_valid_count = 0
        res = 0

        for row in bank:
            curr_count = row.count('1')
            if curr_count > 0:
                res += prev_valid_count * curr_count
                prev_valid_count = curr_count

        return res
