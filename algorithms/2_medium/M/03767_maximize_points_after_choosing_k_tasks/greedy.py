class Solution:
    def maxPoints(self, technique1: List[int], technique2: List[int], k: int) -> int:
        n: int = len(technique2)
        sum_tech2: int = sum(technique2)
        diff: List[int] = [(technique1[i] - technique2[i]) for i in range(n)]
        diff.sort(reverse=True)
        forced_to_pick: int = sum(diff[:k])
        pick_if_good: int = sum(filter(lambda num: num > 0, diff[k:]))

        return sum_tech2 + forced_to_pick + pick_if_good
