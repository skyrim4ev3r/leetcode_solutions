class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        total_sum = sum(nums)

        if total_sum % 3 == 0:
            return total_sum

        mod1_min1, mod1_min2, mod2_min1, mod2_min2 = (-1, -1, -1, -1)

        for num in nums:
            match num % 3:
                case 1:
                    if mod1_min1 == -1 or mod1_min1 > num:
                        mod1_min2 = mod1_min1
                        mod1_min1 = num
                    elif mod1_min2 == -1 or mod1_min2 > num:
                        mod1_min2 = num

                case 2:
                    if mod2_min1 == -1 or mod2_min1 > num:
                        mod2_min2 = mod2_min1
                        mod2_min1 = num
                    elif mod2_min2 == -1 or mod2_min2 > num:
                        mod2_min2 = num

        match total_sum % 3:
            case 1:
                sum1 = total_sum - mod1_min1 if mod1_min1 != -1 else 0
                sum2 = total_sum - mod2_min1 - mod2_min2 if mod2_min1 != -1 and mod2_min2 != -1 else 0

                return max(sum1, sum2)

            case 2:
                sum1 = total_sum - mod1_min1 - mod1_min2 if mod1_min1 != -1 and mod1_min2 != -1 else 0
                sum2 = total_sum - mod2_min1 if mod2_min1 != -1 else 0

                return max(sum1, sum2)

        return -1
