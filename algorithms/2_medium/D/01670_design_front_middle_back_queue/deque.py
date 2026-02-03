class FrontMiddleBackQueue:

    def __init__(self):
        self.q_l = deque()
        self.q_r = deque()

    def balance_queues(self):
        while len(self.q_l) > len(self.q_r):
            self.q_r.appendleft(self.q_l.pop())

        while len(self.q_r) - len(self.q_l) > 1:
            self.q_l.append(self.q_r.popleft())

    def pushFront(self, val: int) -> None:
        self.q_l.appendleft(val)

    def pushMiddle(self, val: int) -> None:
        self.balance_queues()
        self.q_l.append(val)

    def pushBack(self, val: int) -> None:
        self.q_r.append(val)

    def popFront(self) -> int:
        if self.q_l:
            return self.q_l.popleft()
        elif self.q_r:
            return self.q_r.popleft()

        return -1

    def popMiddle(self) -> int:
        self.balance_queues()

        if len(self.q_l) == len(self.q_r):
            if self.q_l:
                return self.q_l.pop()
        else:
            if self.q_r:
                return self.q_r.popleft()

        return -1

    def popBack(self) -> int:
        if self.q_r:
            return self.q_r.pop()
        elif self.q_l:
            return self.q_l.pop()

        return -1
