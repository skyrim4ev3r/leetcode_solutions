class Solution:
    def sortSentence(self, s: str) -> str:
        arr = []

        for part in s.split():
            arr.append((ord(part[-1]) - ord('0'), part[:-1]))

        arr.sort()
        words = []

        for _, word in arr:
            words.append(word)

        return " ".join(words)
