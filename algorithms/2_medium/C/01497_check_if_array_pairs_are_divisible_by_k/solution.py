class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        if k == 1:
            return True

        reminders_freqs = [0] * k
        for a in arr:
            reminders_freqs[a % k] += 1

        # if first freq be even
        # then for even values of k
        # freq[(k / 2)] have to be even too
        # so both edge cases are checked!
        if (reminders_freqs[0] & 1) == 1:
            return False

        half = k // 2
        for i in range(1, half + 1):
            other = k - i

            if reminders_freqs[i] != reminders_freqs[other]:
                return False

        return True
