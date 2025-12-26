class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        n = len(nums)
        exact = set(nums)
        curr = '0' * n
        curr_bytes = list(curr)

        while curr in exact:
            i = n - 1
            curr_bytes[i] = chr(ord(curr_bytes[i]) + 1)

            while curr_bytes[i] > '1':
                curr_bytes[i] = '0'

                if i > 0:
                    curr_bytes[i - 1] = chr(ord(curr_bytes[i - 1]) + 1)
                    i -= 1
                else:
                    break

            curr = "".join(curr_bytes)

        return curr
