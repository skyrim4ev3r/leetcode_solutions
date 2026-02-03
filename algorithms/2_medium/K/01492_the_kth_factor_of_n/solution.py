class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        sqrt_n = int(sqrt(n))
        rest_factors = []

        for i in range(1, sqrt_n + 1):
            if n % i == 0:
                k -= 1
                if k == 0:
                    return i

                other = n // i
                if i != other:
                    rest_factors.append(other)

        len_rest_factors = len(rest_factors)
        if len_rest_factors < k:
            return -1

        return rest_factors[len_rest_factors - k]
