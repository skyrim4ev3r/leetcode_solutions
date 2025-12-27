class Solution:
    def bestClosingTime(self, customers: str) -> int:
        n = len(customers)
        curr_y  = customers.count('Y')
        curr_n  = 0
        min_penalty  = curr_y
        min_penalty_index = 0

        for i in range(1, n + 1):
            if customers[i - 1] == 'N':
                curr_n += 1
            else:
                curr_y -= 1

            total = curr_y + curr_n

            if total < min_penalty:
                min_penalty = total
                min_penalty_index = i

        return min_penalty_index
