class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        total_sum = (n * (n + 1)) // 2
        div_by_m_count = n // m
        div_by_m_sum = m * ((div_by_m_count * (div_by_m_count + 1)) // 2)
        not_div_by_m_sum = total_sum - div_by_m_sum

        return not_div_by_m_sum - div_by_m_sum
