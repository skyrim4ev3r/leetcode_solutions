class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        # Its more efficent to use fixed size array here because:
        # 1 <= nums[i] <= 100
        freqs = [0] * 101

        for num in nums:
            freqs[num] += 1

        count = 0
        for freq in freqs:
            # A pair (i, j) is called good if nums[i] == nums[j] and i < j.
            # So if there be five ones like: 1,1,1,1,1
            # For lowest index of nums[i] = 1 there is 4 good pair, next i have 3 good pairs, next 2, next 1
            # 1 + 2 +...+ n = (n * (n + 1)) /2
            # n = freq - 1 =>  n + 1 = freq  => ((freq - 1) * freq) / 2
            count += ((freq - 1) * freq) // 2

        return count
