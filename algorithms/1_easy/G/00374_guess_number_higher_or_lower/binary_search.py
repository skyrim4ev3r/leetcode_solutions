# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        lo = 1
        hi = n

        while lo <= hi:
            guess_num = lo + (hi - lo) // 2
            guess_result = guess(guess_num)

            match guess_result:
                case 1: 
                    lo = guess_num + 1
                case -1: 
                    hi = guess_num - 1
                case 0: 
                    return guess_num

        return -1
