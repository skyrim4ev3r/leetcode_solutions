class Solution:
    def average(self, salary: List[int]) -> float:
        min_salary = sys.maxsize
        max_salary = -sys.maxsize
        sum_salary = 0

        for val in salary:
            sum_salary += val
            min_salary = min(min_salary, val)
            max_salary = max(max_salary, val)

        sum_exclude_min_max = sum_salary - min_salary - max_salary
        count_exclude_min_max = len(salary) - 2

        return sum_exclude_min_max / count_exclude_min_max
