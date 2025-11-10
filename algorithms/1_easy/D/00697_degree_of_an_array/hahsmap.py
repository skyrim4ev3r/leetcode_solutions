class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        freqs = {}

        for (index, num) in enumerate(nums):
            data = freqs.get(num)

            if data == None:
                freqs[num] = [1, index, index]
            else:
                data[0] += 1
                data[2] = index

        max_freq = 0
        min_width = sys.maxsize

        for data in freqs.values():
            if data[0] > max_freq:
                max_freq = data[0]
                min_width = data[2] - data[1] + 1
            elif data[0] == max_freq:
                min_width = min(min_width, data[2] - data[1] + 1)

        return min_width
