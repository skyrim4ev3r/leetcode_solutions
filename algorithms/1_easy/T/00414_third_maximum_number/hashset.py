class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        distinct_nums_list = list(set(nums))

        distinct_nums_list.sort(reverse=True)

        if len(distinct_nums_list) < 3:
            return distinct_nums_list[0]

        return distinct_nums_list[2]
