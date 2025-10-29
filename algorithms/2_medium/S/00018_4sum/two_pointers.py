class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        nums_len = len(nums)

        if nums_len < 4:
            return res

        nums.sort()

        first = 0
        while first < nums_len - 3:
            if first > 0 and nums[first] == nums[first - 1]:
                first += 1
                continue

            second = first + 1
            while second < nums_len - 2:
                if second > first + 1 and nums[second] == nums[second - 1]:
                    second += 1
                    continue

                third = second + 1
                fourth = nums_len - 1

                while third < fourth:
                    curr_sum = nums[first] + nums[second] + nums[third] + nums[fourth]

                    if curr_sum == target:

                        res.append([nums[first], nums[second], nums[third], nums[fourth]])

                        fourth -= 1
                        while third < fourth and nums[fourth] == nums[fourth + 1]:
                            fourth -= 1

                        third += 1
                        while third < fourth and nums[third] == nums[third - 1]:
                            third += 1

                    elif curr_sum < target:
                        third += 1
                    else:
                        fourth -= 1

                second += 1

            first += 1

        return res
