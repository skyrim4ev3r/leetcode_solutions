class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        freqs = list(Counter(arr).values())
        target_count = (len(arr) + 1) // 2
        curr_count = 0
        curr_count_uniques = 0

        freqs.sort(reverse=True)

        for freq in freqs:
            curr_count += freq
            curr_count_uniques += 1

            if curr_count >= target_count:
                return curr_count_uniques

        return -1
