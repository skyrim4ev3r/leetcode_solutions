class Solution:
    def checkRecord(self, s: str) -> bool:
        absent_count = 0
        consecutive_late_count = 0

        for ch in s:
            if ch == 'A':
                absent_count += 1
                consecutive_late_count = 0
            elif ch == 'L':
                consecutive_late_count += 1
            else:
                consecutive_late_count = 0

            if consecutive_late_count == 3 or absent_count == 2:
                return False

        return True
