class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        res = []

        for num in nums:
            while len(res) > 0 and  gcd(num, res[-1]) > 1:
                num =  lcm(num, res[-1])
                res.pop()
            res.append(num)

        return res
