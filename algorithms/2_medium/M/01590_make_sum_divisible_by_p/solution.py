class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        total_sum = sum(nums)
        rem = total_sum % p

        if rem == 0:
            return 0

        complement_rem = p - rem
        hashmap = {0: -1}

        curr_rem = 0
        min_eleme_to_remove = len(nums)

        for i, num in enumerate(nums):
            curr_rem = (curr_rem + num) % p

            target_rem = (curr_rem + complement_rem) % p
            val = hashmap.get(target_rem)

            if val != None:
                min_eleme_to_remove = min(min_eleme_to_remove, i - val)

            hashmap[curr_rem] = i

        return - 1 if min_eleme_to_remove == len(nums) else min_eleme_to_remove
