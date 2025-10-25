class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        hashmap = {}

        for (index, num) in enumerate(nums):
            other_index = hashmap.get(target - num)
            if other_index != None:
                return [other_index, index]
            else:
                hashmap[num] = index

        return []
