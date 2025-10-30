#	if there be now vowel then player1 has "no-move" and lose and if there be any vowel in string
#        then player1 can win in eighter "1-step" or "3-steps" and it should return true:
#
#                "1-step"
#                        if it be odd vowels: player1 took them all
#
#                "3-steps:
#                        if they be even vowels: player1 take odd numbers(even - odd = odd numbers will remain),
#                        player2 will have to take even numbers of them(odd - even = odd  numbers will remain)
#                        player1 take the rest and win
#
#        so answer is just checking that if there is any vowels in string

class Solution:
    def doesAliceWin(self, s: str) -> bool:
        return any(ch in "aeiouAEIOU" for ch in s)
