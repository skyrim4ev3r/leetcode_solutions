class Solution:
    def calc_cost(self, arr: List[int], brr: List[int]) -> int :
        n = len(arr)
        cost = 0

        for i in range(n):
            cost += abs(arr[i] - brr[i])

        return cost

    def minCost(self, arr: List[int], brr: List[int], k: int) -> int:
        by_default_cost = self.calc_cost(arr, brr)
        arr.sort()
        brr.sort()
        by_sort_cost = self.calc_cost(arr, brr) + k

        return min(by_default_cost, by_sort_cost)
