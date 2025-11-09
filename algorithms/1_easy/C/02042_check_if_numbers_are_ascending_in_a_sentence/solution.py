class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        curr_max = -sys.maxsize - 1

        for part in s.split():
            if part.isdigit():
                number = int(part)

                if number <= curr_max:
                    return False

                curr_max = number

        return True
