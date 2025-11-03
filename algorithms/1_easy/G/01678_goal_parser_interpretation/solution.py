class Solution:
    def interpret(self, command: str) -> str:
        res = []

        for ch in command:
            if ch == ')':
                if res and res[-1] == '(':
                    res.pop()
                    res.append('o')
            else:
                if res and res[-1] == '(':
                    res.pop()

                res.append(ch)

        return "".join(res)
