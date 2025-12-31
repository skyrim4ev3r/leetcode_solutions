class Solution:
    def are_lefthalf_righthalf_same(self, word: str) -> bool:
        if len(word) % 2 == 1:
            return False
        half = len(word) // 2

        for i in range(half):
            if word[i] != word[i + half]:
                return False

        return True

    def numOfPairs(self, nums: List[str], target: str) -> int:
        target_len = len(target)
        lefthalf_righthalf_are_same = self.are_lefthalf_righthalf_same(target)
        counts_starts_with = [0] * target_len
        counts_ends_with = [0] * target_len
        count = 0

        for num in nums:
            if len(num) < target_len:
                if target.startswith(num):
                    counts_starts_with[len(num)] += 1

                if target.endswith(num):
                    counts_ends_with[len(num)] += 1

        for i in range(1, target_len):
            if lefthalf_righthalf_are_same and i == target_len - i:
                count += (counts_starts_with[i] - 1) * (counts_ends_with[target_len - i])
            else:
                count += counts_starts_with[i] * counts_ends_with[target_len - i]

        return count
