class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        points.sort(key= lambda a: (a[0] * a[0] + a[1] * a[1]))
        return points[:k]
