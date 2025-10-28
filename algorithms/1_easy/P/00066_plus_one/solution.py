class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = 1
        digits_len = len(digits)

        for i in range(digits_len - 1, -1, -1):
            digits[i] += carry
            carry = 0

            if digits[i] > 9:
                digits[i] -= 10
                carry = 1

            if carry == 0:
                break;

        # This case occurs when all digits are 9 (e.g., [9,9,9,9]), 
        # resulting in [0,0,0,0]. We push a 0 and set the first digit to 1.
        if carry == 1:
            digits.append(0)
            digits[0] = 1

        return digits
