class Solution:
    def is_prime(self, num):
        match num:
            case 2 | 3 | 5 | 7 | 11 | 13 | 17 | 19 | 23 | 29 | 31:
                return True
        return False

    def countPrimeSetBits(self, left: int, right: int) -> int:
        count = 0

        for num in range(left, right + 1):
            if self.is_prime(bin(num).count('1')):
                count += 1

        return count
