class Solution:
    def maximumNumberOfStringPairs(self, words: List[str]) -> int:
        hashset = set()
        count = 0

        for word in words:
            rev_word = word[::-1]

            if rev_word in hashset:
                hashset.remove(rev_word)
                count += 1
            else:
                hashset.add(word)

        return count
