class Solution:
    def stringHash(self, s: str, k: int) -> str:
        old_len = len(s)
        res = []
        count = 0
        curr_sum = 0

        for (i, ch) in enumerate(s):
            count += 1
            curr_sum += ord(ch) - ord('a')

            if count == k or i == old_len - 1:
                count = 0
                res.append(chr((curr_sum % 26) + ord('a')))
                curr_sum = 0

        return "".join(res)
