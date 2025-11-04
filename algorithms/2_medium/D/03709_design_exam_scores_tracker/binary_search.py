class ExamTracker:

    def __init__(self):
        self.time = [0]
        self.score = [0]

    def record(self, time: int, score: int) -> None:
        self.time.append(time)
        self.score.append(self.score[-1] + score)

    def totalScore(self, startTime: int, endTime: int) -> int:
        left = bisect.bisect_left(self.time, startTime)
        right = bisect.bisect_right(self.time, endTime)

        return self.score[right - 1] - self.score[left - 1]
