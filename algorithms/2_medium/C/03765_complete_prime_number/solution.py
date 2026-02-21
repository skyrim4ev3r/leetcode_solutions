class Solution:
    def is_prime(self, num: int) -> bool:
        if num == 2:
            return True

        if num <= 1 or num % 2 == 0:
            return False

        sqrt_num = int(sqrt(num))

        for i in range(3, sqrt_num + 1, 2):
            if num % i == 0:
                return False

        return True

    def check_prefix(self, num: int) -> bool:
        prefix: int = num
        while prefix > 0:
            if not self.is_prime(prefix):
                return False
            prefix //= 10
        return True

    def check_suffix(self, num: int) -> bool:
        suffix: int = num
        p: int = 1

        while suffix // p >= 10:
            p *= 10

        while suffix > 0:
            if not self.is_prime(suffix):
                return False

            suffix = suffix - (suffix // p) * p
            p //= 10

        return True

    def completePrime(self, num: int) -> bool:
        return self.check_prefix(num) and self.check_suffix(num)
