class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        rows = len(strs)
        cols = len(strs[0])
        count = 0

        for j in range(cols):

            is_sorted = True
            for i in range(1, rows):
                if strs[i][j] < strs[i - 1][j]:
                    is_sorted = False
                    break

            if not is_sorted:
                count += 1

        return count
