class Solution:
    def reverseVowels(self, s: str) -> str:
        s_list = list(s)
        left = 0
        right = len(s_list) - 1
        vowels = "aeiouAEIOU"

        while True:
            while left < right and not s_list[right] in vowels:
                right -= 1

            while left < right and not s_list[left] in vowels:
                left += 1

            if left >= right:
                break

            temp = s_list[left]
            s_list[left] = s_list[right]
            s_list[right] = temp

            right -= 1
            left += 1

        return "".join(s_list)
