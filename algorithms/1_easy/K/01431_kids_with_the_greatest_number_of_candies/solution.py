class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        max_candy = 0
        for num in candies:
            if max_candy < num:
                max_candy = num

        res = []
        for num in candies:
            if num + extraCandies >= max_candy:
                res.append(True)
            else:
                res.append(False)

        return res
