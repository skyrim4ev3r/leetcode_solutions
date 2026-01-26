class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()

        n = len(arr)
        min_diff = sys.maxsize
        for i in range(n - 1):
            min_diff = min(min_diff, arr[i + 1] - arr[i])

        res = []

        for i in range(n - 1):
            if min_diff == arr[i + 1] - arr[i]:
                res.append([arr[i], arr[i + 1]])

        return res
