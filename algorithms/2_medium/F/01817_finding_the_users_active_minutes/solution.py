class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        user_to_activity_count = defaultdict(int)
        logs_set = set()

        for log in logs:
            logs_set.add((log[0], log[1]))

        res = [0] * k

        for log in logs_set:
            user_to_activity_count[log[0]] += 1

        for count in user_to_activity_count.values():
            res[count - 1] += 1

        return res
