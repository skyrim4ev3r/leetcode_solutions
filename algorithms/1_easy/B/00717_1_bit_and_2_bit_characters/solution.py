class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        n = len(bits)
        index = 0
        last_is_zero = False

        while index < n:
            if bits[index] == 0:
                last_is_zero = True
                index += 1
            else:
                last_is_zero = False
                index += 2

        return last_is_zero
