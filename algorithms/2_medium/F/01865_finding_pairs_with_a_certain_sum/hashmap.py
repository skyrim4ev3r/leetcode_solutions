class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.nums1 = nums1
        self.nums2 = nums2
        self.freqs_nums2 = dict(Counter(nums2))

    def add(self, index: int, val: int) -> None:
        num2_prev_val = self.nums2[index]
        num2_new_val = num2_prev_val + val
        self.nums2[index] += val

        self.freqs_nums2[num2_prev_val] -= 1
        if self.freqs_nums2[num2_prev_val] == 0:
            del self.freqs_nums2[num2_prev_val]

        if num2_new_val in self.freqs_nums2:
            self.freqs_nums2[num2_new_val] += 1
        else:
            self.freqs_nums2[num2_new_val] = 1

    def count(self, tot: int) -> int:
        count = 0

        for num1 in self.nums1:
            other = tot - num1
            freq = self.freqs_nums2.get(other)
            if freq != None:
                count += freq

        return count
