class Solution:
    def checkValidString(self, s: str) -> bool:
        n = len(s)
        points = 0
        balance = 0

        for ch in s:
            if ch == ')':
                balance -= 1

                if balance < 0:
                    if points > 0:
                        points -= 1
                        balance += 1
                    else:
                        return False
            elif ch == '(':
                balance += 1
            else:
                points += 1

        balance = 0
        points = 0

        for i in range(n - 1, -1, -1):
            ch = s[i]

            if ch == '(':
                balance -= 1

                if balance < 0:
                    if points > 0:
                        points -= 1
                        balance += 1
                    else:
                        return False
            elif ch == ')':
                balance += 1
            else:
                points += 1

        return True
