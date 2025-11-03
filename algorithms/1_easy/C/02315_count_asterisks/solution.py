class Solution:
    def countAsterisks(self, s: str) -> int:
        list_s = list(s)
        count = 0
        can_count = True

        while list_s:
            ch = list_s.pop()
            match ch:
                case '|':
                    can_count = not can_count
                case '*':
                    if can_count:
                        count += 1

        return count
