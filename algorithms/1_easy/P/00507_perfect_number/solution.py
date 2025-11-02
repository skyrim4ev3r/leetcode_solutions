class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num == 1:
            return False
        total_sum, sq = 1, int(sqrt(num))
        for i in range(2, sq + 1):
            if num % i == 0:
                total_sum += i
                if i != sq:
                    total_sum += num / i
                elif i != num / i:
                    total_sum += num / i
                if total_sum > num:
                    break
        return total_sum == num
