class Solution:
    def minMovesToCaptureTheQueen(self, a: int, b: int, c: int, d: int, e: int, f: int) -> int:
        if a == e:
            if c == a and d > min(b, f) and d < max(b, f):
                return 2
            return 1

        if b == f:
            if b == d and c > min(a, e) and c < max(a, e):
                return 2
            return 1

        if abs(e - c) == abs(f - d):
            if abs(a - c) == abs(b - d):
                if a > min(c, e) and a < max(c, e) and b > min(d, f) and b < max(d, f):
                    return 2
            return 1

        return 2
