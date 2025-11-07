class Solution:
    def checkPrimeFrequency(self, nums: List[int]) -> bool:
        res = {}
        for i in range(0,len(nums)):
            res[nums[i]] = res[nums[i]] + 1 if nums[i] in res else 1
        for v in res.values():
            if v > 1:
                is_prime = True
                for i in range(2,int(sqrt(v))+1):
                    if v % i == 0 :
                        is_prime = False
                        break
                if is_prime :
                    return True
        return False
