class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        min_distance = -1
        datas = {}

        for (i, num) in enumerate(nums):
            num_data = datas.get(nums[i])
            if num_data == None:
                datas[num] = [-1, -1, -1]
                num_data = datas[num]

            if num_data[0] == -1:
                num_data[0] = i
            elif num_data[1] == -1:
                num_data[1] = i
            else:
                if num_data[2] == -1:
                    num_data[2] = i
                else:
                    num_data[0] = num_data[1]
                    num_data[1] = num_data[2]
                    num_data[2] = i

                curr_distance = (num_data[2] - num_data[0]) * 2

                if min_distance == -1 or min_distance > curr_distance:
                    min_distance = curr_distance

        return min_distance
