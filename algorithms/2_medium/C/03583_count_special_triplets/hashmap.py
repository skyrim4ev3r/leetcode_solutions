MOD_TO = 1_000_000_007

class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        freqs = {}
        count = 0

        for num in nums:
            if num in freqs:
                freqs[num][1] += 1
            else:
                freqs[num] = [0, 1]

        for num in nums:
            freqs[num][1] -= 1

            pair_num_x2 = freqs.get(num + num)
            if pair_num_x2 != None:
                count += pair_num_x2[0] * pair_num_x2[1]

            freqs[num][0] += 1

        return count % MOD_TO
