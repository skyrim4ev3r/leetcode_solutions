class Solution:
    def lengthOfLastWord(self, s: str) -> int:

        s = list(s)
        count = 0
        is_counting_started = False

        while s:
            ch = s.pop()
            if ch != ' ':
                is_counting_started = True

            if is_counting_started:
                if ch != ' ':
                    count += 1
                else:
                    break

        return count
