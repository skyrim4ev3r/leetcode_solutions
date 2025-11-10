class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        hashset = set()

        for num in arr:
            if (num * 2) in hashset or ((num & 1) != 1 and (num // 2 in hashset)):
                return True

            hashset.add(num)

        return False
