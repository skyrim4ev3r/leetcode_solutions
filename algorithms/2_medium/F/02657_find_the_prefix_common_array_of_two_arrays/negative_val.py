class Solution:
    def findThePrefixCommonArray(self, a: List[int], b: List[int]) -> List[int]:

        res = []
        common = 0
        n = len(a)

        for i in range(n):
            index_num_a = abs(a[i]) - 1
            index_num_b = b[i] - 1

            if a[index_num_a] < 0:
                common += 1
            else:
                a[index_num_a] *= -1

            if a[index_num_b] < 0:
                common += 1
            else:
                a[index_num_b] *= -1

            res.append(common)

        return res
