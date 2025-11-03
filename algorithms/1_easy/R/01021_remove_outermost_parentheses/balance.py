class Solution:
    def removeOuterParentheses(self, s: str) -> str:

        res = []
        balance = 0

        for ch in s:
            if ch == '(':
                balance += 1
            else:
                balance -= 1

            if (balance == 1 and ch == '(') or balance == 0:
               continue

            res.append(ch)

        return "".join(res)
