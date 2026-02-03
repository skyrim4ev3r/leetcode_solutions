class Solution:
    def check_mid(self, position: List[int], mid: int, m: int, n: int) -> bool:
        pos = 0

        for _ in range(m - 1):
            next_val = position[pos] + mid

            while pos < n and position[pos] < next_val:
                pos += 1

            if pos == n:
                return False

        return True

    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        n = len(position)
        left = 1
        right = (position[n - 1] - position[0]) // (m - 1)

        while left <= right:
            mid = left + (right - left) // 2

            if self.check_mid(position, mid, m, n):
                left = mid + 1
            else:
                right = mid - 1

        return left - 1
