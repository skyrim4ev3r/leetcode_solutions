class Solution:
    def climbStairs(self, n: int) -> int:
        # Edge case: Directly return 1 to reduce complexity of creating the memoization vector
        if n == 1:
            return 1

        mem = [0] * n

        mem[n - 1] = 1
        mem[n - 2] = 2

        for i in range(n - 3, -1, -1):
            mem[i] = mem[i + 1] + mem[i + 2]

        return mem[0]
