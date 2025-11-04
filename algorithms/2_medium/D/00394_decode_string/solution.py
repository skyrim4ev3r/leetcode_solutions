class Solution:
    def decodeString(self, s: str) -> str:
        current_str = ""
        multiplier = 0
        stack_multipliers = []
        stack_strs = []

        for ch in s:
            if ord(ch) >= ord('0') and ord(ch) <= ord('9'):
                multiplier = multiplier * 10 + ord(ch) - ord('0')
            elif ord(ch) == ord('['):
                stack_multipliers.append(multiplier)
                stack_strs.append(current_str)
                multiplier = 0
                current_str = ""
            elif ord(ch) >= ord('a') and ord(ch) <= ord('z'):
                current_str += ch
            else:
                last_multiplier = stack_multipliers[-1]
                last_str = stack_strs[-1]
                tmp = ""
                for _ in range(last_multiplier):
                        tmp += current_str
                current_str = last_str + tmp
                stack_multipliers.pop()
                stack_strs.pop()

        return current_str
