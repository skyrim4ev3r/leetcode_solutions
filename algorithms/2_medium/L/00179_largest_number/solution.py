class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        nums_str = [str(num) for num in nums]

        def cmp(a, b):
            a_len = len(a)
            b_len = len(b)
            total = a_len + b_len

            for i in range(total):
                a_index = i % a_len
                b_index = i % b_len

                if a[a_index] > b[b_index]:
                    return -1

                if a[a_index] < b[b_index]:
                    return 1

            return 0

        nums_str.sort(key= cmp_to_key(cmp))

        if nums_str[0] == "0":
            return "0"

        return "".join(nums_str)
