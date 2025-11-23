class Solution:
    def isHappy(self, n: int) -> bool:
        hashset = {n}

        while True:
            if n == 1:
                return True

            new_n = 0
            while n > 0:
                new_n += (n % 10) ** 2
                n //= 10
            n = new_n

            if n in hashset:
                return False
            else:
                hashset.add(n)
