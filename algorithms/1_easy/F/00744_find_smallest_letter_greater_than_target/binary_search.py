class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        pos = bisect.bisect_right(letters, target)

        if pos == len(letters):
            return letters[0]

        return letters[pos]
