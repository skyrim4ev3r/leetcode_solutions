import queue

class MyStack:

    def __init__(self):
        self.queue = queue.Queue()

    def push(self, x: int) -> None:
        self.queue.put(x)
    def pop(self) -> int:
        q_len = self.queue.qsize()

        for i in range(q_len - 1):
            self.queue.put(self.queue.get())

        return self.queue.get()


    def top(self) -> int:
        q_len = self.queue.qsize()

        for i in range(q_len - 1):
            self.queue.put(self.queue.get())

        top_val = self.queue.get()
        self.queue.put(top_val)

        return top_val

    def empty(self) -> bool:
        return self.queue.empty()


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
