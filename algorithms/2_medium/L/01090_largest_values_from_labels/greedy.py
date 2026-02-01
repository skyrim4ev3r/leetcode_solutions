class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], num_wanted: int, use_limit: int) -> int:
        arr = list(zip(values, labels))
        arr.sort(key= lambda x: x[0], reverse=True)
        freqs = defaultdict(int)
        res = 0
        count = 0

        for (val, label) in arr:
            if count >= num_wanted:
                break

            if freqs[label] < use_limit:
                freqs[label] += 1
                count += 1
                res += val

        return res
