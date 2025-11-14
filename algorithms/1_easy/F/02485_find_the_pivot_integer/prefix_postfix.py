class Solution:
    def pivotInteger(self, n: int) -> int:
        prefix_sum = (n * (n + 1)) // 2
        postfix_sum = n
        pivot = n

        while pivot > 0 and prefix_sum >= postfix_sum:
            if prefix_sum == postfix_sum:
                return pivot
            prefix_sum -= pivot
            postfix_sum += pivot - 1
            pivot -= 1

        return -1
