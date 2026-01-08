class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        n = len(customers)
        base = 0

        for i in range(n):
            if grumpy[i] == 0:
                base += customers[i]

        windows_len = minutes
        curr = 0

        for i in range(windows_len):
            if grumpy[i] == 1:
                curr += customers[i]

        max_window = curr

        for i in range(windows_len, n):
            if grumpy[i] == 1:
                curr += customers[i]

            if grumpy[i - windows_len] == 1:
                curr -= customers[i - windows_len]

            max_window = max(max_window, curr)

        return base + max_window
