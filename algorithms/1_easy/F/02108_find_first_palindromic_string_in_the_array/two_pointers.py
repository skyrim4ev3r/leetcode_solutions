class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            right = len(word) - 1
            left = 0

            while left < right:
                if word[left] != word[right]:
                    break

                left += 1
                right -= 1

            if left >= right:
                return word

        return ""
