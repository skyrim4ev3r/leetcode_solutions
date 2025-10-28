class Solution:
    def occurrencesOfElement(self, nums: List[int], queries: List[int], x: int) -> List[int]:
        occurrences_vec = []

        for (index, num) in enumerate(nums):
            if num == x:
                occurrences_vec.append(index)

        res = []
        occurrences_vec_len = len(occurrences_vec)

        for query in queries:
            index = query - 1

            if index >= occurrences_vec_len:
                res.append(-1)
            else:
                res.append(occurrences_vec[index])

        return res
