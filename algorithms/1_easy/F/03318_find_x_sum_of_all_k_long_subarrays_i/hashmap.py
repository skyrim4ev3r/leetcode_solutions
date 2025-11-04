class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        nums_len = len(nums)
        freqs = dict(Counter(nums[:k]))
        res = [0] * (nums_len - k + 1)
        left = 0

        def calculate_x_sum(freqs, x):
            freqs_vec = list(freqs.items())
            print(freqs_vec)
            freqs_vec.sort(key=lambda k: (-k[1], -k[0]))
            print(freqs_vec)
            freqs_vec_len = len(freqs_vec)
            return sum(k * v for k, v in freqs_vec[:min(x, freqs_vec_len)])

        res[0] = calculate_x_sum(freqs, x)

        for right in range(k, nums_len):
            if nums[right] in freqs:
                freqs[nums[right]] += 1
            else:
                freqs[nums[right]] = 1

            freqs[nums[left]] -= 1
            if freqs[nums[left]] == 0:
                del freqs[nums[left]]

            left += 1

            res[right - k + 1] = calculate_x_sum(freqs, x)

        return res
