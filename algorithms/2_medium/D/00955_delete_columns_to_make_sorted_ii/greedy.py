class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        rows = len(strs)
        cols = len(strs[0])
        is_sorted = [False] * rows
        count = 0

        for j in range(cols):
            should_delete = False

            for i in range(1, rows):
                if not is_sorted[i]:
                    if strs[i][j] < strs[i - 1][j]:
                        should_delete = True
                        break

            if should_delete:
                count += 1
            else:
                are_all_sorted = True

                for i in range(1, rows):
                    is_sorted[i] |= (strs[i][j] > strs[i - 1][j])
                    are_all_sorted &= is_sorted[i]

                if are_all_sorted:
                    break

        return count
