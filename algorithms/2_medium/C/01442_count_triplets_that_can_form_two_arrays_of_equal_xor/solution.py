class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        n = len(arr)
        count = 0

        for i in range(n):
            curr_xor = 0

            for j in range(i, n):
                curr_xor ^= arr[j]

                if curr_xor == 0:
                    count += j - i

        return count
