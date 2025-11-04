# Time Complexity: O(N) - Ignore the nested loops; the overall complexity is linear
# Follow i and j's changing behavior for clarification.
class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        max_energy_absorb = -sys.maxsize-1
        energy_len = len(energy)

        for i in range(k):
            total_sum = 0

            for j in range(i, energy_len, k):
                if total_sum < 0:
                    total_sum = 0

                total_sum += energy[j]

            if max_energy_absorb < total_sum:
                max_energy_absorb = total_sum

        return max_energy_absorb
