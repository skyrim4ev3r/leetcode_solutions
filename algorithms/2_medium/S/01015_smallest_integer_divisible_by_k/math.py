class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        prev_reminder = 1 % k
        seen = set()
        curr_len = 1

        while prev_reminder != 0:
            if prev_reminder in seen:
                return -1

            seen.add(prev_reminder)
            prev_reminder = (prev_reminder * 10 + 1) % k
            curr_len += 1

        return  curr_len
