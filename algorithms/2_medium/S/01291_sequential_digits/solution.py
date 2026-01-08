class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        res = []

        for i in range(1, 10):
            curr_num = 0
            curr_dig = i

            while curr_num <= high:
                if curr_num >= low:
                    res.append(curr_num)

                if curr_dig > 9:
                    break

                curr_num = curr_num * 10 + curr_dig;
                curr_dig += 1

        res.sort()

        return res
