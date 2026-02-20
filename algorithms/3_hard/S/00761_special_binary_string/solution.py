class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        n: int = len(s)
        if n <= 2:
            return s
        left: int = 0
        balance: int = 0
        parts: List[str] = []

        for right in range(n):
            if s[right] == '1':
                balance += 1
            else:
                balance -= 1

            if balance == 0:
                parts.append("1" + self.makeLargestSpecial(s[left + 1: right]) + "0")
                left = right + 1

        parts.sort(reverse=True)
        return "".join(parts)
