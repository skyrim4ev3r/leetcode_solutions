class Solution:
    def minProcessingTime(self, processorTime: List[int], tasks: List[int]) -> int:
        tasks_len = len(tasks)
        res = 0

        processorTime.sort(reverse=True)
        tasks.sort()

        for i in range(0, tasks_len, 4):
            max_elem = max(tasks[i : (i + 4)])
            res = max(res, max_elem + processorTime[i // 4])

        return res
