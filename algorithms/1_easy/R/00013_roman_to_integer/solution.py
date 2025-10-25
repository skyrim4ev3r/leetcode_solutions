class Solution:
    def romanToInt(self, s: str) -> int:

        total_sum = 0
        curr_max = 0

        for ch in reversed(s):

            curr_num = 0

            match ch:
                case 'I':
                    curr_num = 1
                case 'V':
                    curr_num = 5
                case 'X':
                    curr_num = 10
                case 'L':
                    curr_num = 50
                case 'C':
                    curr_num = 100
                case 'D':
                    curr_num = 500
                case 'M':
                    curr_num = 1000

            if curr_num >= curr_max:
                total_sum += curr_num
                curr_max = curr_num
            else:
                total_sum -= curr_num

        return total_sum
