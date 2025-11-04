class Solution:
    def totalFruit(self, fruits: List[int]) -> int:

        hashmap = {}
        left = 0
        max_val = 0

        for right in range(0, len(fruits)):

            hashmap[fruits[right]] = hashmap.get(fruits[right], 0) + 1

            while len(hashmap) > 2:
                hashmap[fruits[left]] -= 1
                if hashmap[fruits[left]] == 0:
                    hashmap.pop(fruits[left])
                left += 1

            max_val = max(max_val, right - left + 1)

        return max_val
