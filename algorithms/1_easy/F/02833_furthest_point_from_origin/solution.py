class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        balance = 0
        offset = 0

        for ch in moves:
            match ch:
                case 'L':
                    balance -= 1
                case 'R':
                    balance += 1
                case _:
                    offset += 1

        if balance < 0:
            return abs(balance - offset)

        return balance + offset
