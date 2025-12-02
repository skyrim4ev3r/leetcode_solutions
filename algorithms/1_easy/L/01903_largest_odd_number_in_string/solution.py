class Solution:
    def largestOddNumber(self, num: str) -> str:
        right_index = len(num) - 1

        while right_index >= 0 and num[right_index] not in "13579":
            right_index -= 1

        if right_index < 0:
            return ""

        return "".join(num[:right_index + 1])
