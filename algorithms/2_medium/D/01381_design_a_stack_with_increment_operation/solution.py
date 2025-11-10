class CustomStack:

    def __init__(self, maxSize: int):
        self.max_size = maxSize
        self.stack = [0] * maxSize
        self.current_head = 0

    def push(self, x: int) -> None:
        if self.current_head < self.max_size:
            self.stack[self.current_head] = x
            self.current_head += 1

    def pop(self) -> int:
        if self.current_head == 0:
            return -1
        self.current_head -= 1
        return self.stack[self.current_head]

    def increment(self, k: int, val: int) -> None:
        for i in range(0, min(self.current_head, k)):
            self.stack[i] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
