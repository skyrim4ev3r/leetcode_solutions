class Solution:
    def backtrack(
        self,
        digits_count:  List[int],
        res: List[int],
        curr_num: int,
        curr_depth: int,
    ):
        if curr_depth == 3:
            if curr_num >= 100 and curr_num < 1000 and curr_num % 2 == 0:
                res.append(curr_num)

            return

        for i in range(10):
            if digits_count[i] > 0:
                digits_count[i] -= 1
                self.backtrack(digits_count, res, curr_num * 10 + i, curr_depth + 1);
                digits_count[i] += 1

    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        digits_count = [0] * 10

        for digit in digits:
            digits_count[digit] += 1

        res = []

        self.backtrack(digits_count, res, 0, 0)

        return res
