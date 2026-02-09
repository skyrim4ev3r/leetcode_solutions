class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        q = deque()

        for i in range(1, n + 1):
            q.append(i)

        while len(q) > 1:
            curr_len = len(q)
            index_to_del = curr_len - 1 if k % curr_len == 0 else k % curr_len - 1

            for i in range(index_to_del):
                q.append(q.popleft())

            q.popleft()

        return q.popleft()
