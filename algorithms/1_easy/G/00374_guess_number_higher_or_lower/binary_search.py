# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:

        low = 1
        high = n

        while low <= high:
            guess_num = (high + low) // 2
            guess_result = guess(guess_num)

            match guess_result:
                case 1:
                    low = guess_num + 1
                case -1:
                    high = guess_num - 1
                case 0:
                    return guess_num

        return -1
