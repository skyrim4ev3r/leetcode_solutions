class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:

        res = 0

        for num in nums:

            sq = int(sqrt(num))
            count = 0
            t_sum = 0

            for i in range(1, sq + 1):
                if num % i == 0 :
                    other = num // i

                    if other == i:
                        count += 1
                        t_sum += i 
                    else:
                        count += 2
                        t_sum += i + other

                if count > 4:
                    break

            if count == 4:
                res += t_sum

        return res
