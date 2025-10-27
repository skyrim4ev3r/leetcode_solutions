class Solution:
    def findThePrefixCommonArray(self, a: List[int], b: List[int]) -> List[int]:

        nums_set = set()
        res = []
        common = 0

        for i in range(len(a)):
            if a[i] in nums_set:
                nums_set.remove(a[i])
                common += 1
            else:
                nums_set.add(a[i])

            if b[i] in nums_set:
                nums_set.remove(b[i])
                common += 1
            else:
                nums_set.add(b[i])

            res.append(common)

        return res
