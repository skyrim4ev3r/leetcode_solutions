class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        res = []

        for i in range(left, right + 1):

            tmp = i
            is_divisible = True

            while tmp > 0:
                digit = tmp % 10
                if digit == 0 or i % digit != 0:
                    is_divisible = False
                    break

                tmp //= 10

            if is_divisible:
                res.append(i)

        return res
