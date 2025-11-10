class Solution:
    def findLucky(self, arr: List[int]) -> int:
        hashmap = {}

        for num in arr:
            if num in hashmap:
                hashmap[num] += 1
            else:
                hashmap[num] = 1

        max_lucky = -1
        for (key, val) in hashmap.items():
            if key == val:
                max_lucky = max(max_lucky, val)

        return max_lucky
