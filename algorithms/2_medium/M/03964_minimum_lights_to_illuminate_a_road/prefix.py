class Solution:
    def minLights(self, lights: list[int]) -> int:
        n = len(lights)
        prefix = [0] * (n + 3)

        for (i, light) in enumerate(lights):
            if light > 0:
                lo = max(i - light, 0)
                hi = min(i + light + 1, n)
                prefix[lo] += 1
                prefix[hi] -= 1

        total_sum = 0
        cnt_need = 0
        for i in range(n):
            total_sum += prefix[i]
            if total_sum == 0:
                total_sum += 1
                cnt_need += 1
                prefix[i + 3] -= 1

        return cnt_need
