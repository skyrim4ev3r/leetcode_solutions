class Solution:
    def is_valid_char(self, ch):
        return (ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z')

    def reverseOnlyLetters(self, s: str) -> str:
        vec = list(s)
        left = 0
        right = len(vec) - 1

        while left < right:
            while left < right and not self.is_valid_char(vec[right]):
                right -= 1

            while left < right and not self.is_valid_char(vec[left]):
                left += 1

            if left >= right:
                break

            temp = vec[right]
            vec[right] = vec[left]
            vec[left] = temp

            right -= 1
            left += 1

        return "".join(vec)
