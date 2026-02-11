class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 3:
            return 0

        is_prime = [True] * n
        is_prime[0] = False
        is_prime[1] = False
        ceil_sqrt_n = ceil(sqrt(n))

        for i in range(ceil_sqrt_n + 1):
            if is_prime[i]:
                for j in range(2 * i, n, i):
                    is_prime[j] = False

        return is_prime.count(True)
