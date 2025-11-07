class Solution:
    def maximum69Number (self, num: int) -> int:
        p = 1

        while p <= num:
            p *= 10

        p //= 10

        while p > 0:
            curr_digit = (num // p) % 10

            if curr_digit == 6:
                return num + (3 * p) # This number 3 comes from here: 9 - 6 = 3;
                                     # + (3 * p) will add 3 to highest 6
            p //= 10

        return num
