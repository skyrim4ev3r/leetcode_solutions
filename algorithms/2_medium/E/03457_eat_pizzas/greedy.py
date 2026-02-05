class Solution:
    def maxWeight(self, pizzas: List[int]) -> int:
        pizzas.sort()

        n = len(pizzas)
        total_days = n // 4
        odd_days = (total_days // 2) + (total_days & 1)
        even_days = (total_days // 2)
        total_sum = 0
        curr_index = n - 1

        for _ in range(odd_days):
            total_sum += pizzas[curr_index]
            curr_index -= 1

        for _ in range(even_days):
            curr_index -= 1
            total_sum += pizzas[curr_index]
            curr_index -= 1

        return total_sum
