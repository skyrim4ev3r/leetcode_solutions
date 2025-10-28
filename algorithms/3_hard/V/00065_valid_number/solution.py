class Solution:
    def isNumber(self, s: str) -> bool:

        contains_e, contains_dot, contains_digits_before_e, contains_digits_after_e = (False, False, False, False)

        for i in range(len(s)):

            if (ord(s[i]) >= ord('A') and ord(s[i]) <= ord('Z')) or (ord(s[i]) >= ord('a') and ord(s[i]) <= ord('z')):
                if ord(s[i]) != ord('e') and ord(s[i]) != ord('E'):
                    return False

            if ord(s[i]) == ord('-') or ord(s[i]) == ord('+'):
                if contains_e:
                    if ord(s[i - 1]) != ord('e') and ord(s[i - 1]) != ord('E'):
                        return False
                else:
                    if i != 0:
                        return False

            if ord(s[i]) == ord('e') or ord(s[i]) == ord('E'):
                if contains_e or not contains_digits_before_e:
                    return False
                contains_e = True 
           
            if ord(s[i]) == ord('.'):
                if contains_e or contains_dot:
                    return False
                contains_dot = True

            if ord(s[i]) >= ord('0') and ord(s[i]) <= ord('9'):
                if contains_e:
                    contains_digits_after_e = True
                else:
                    contains_digits_before_e = True

        if (not contains_digits_before_e) or (contains_e and not contains_digits_after_e):
            return False

        return True
