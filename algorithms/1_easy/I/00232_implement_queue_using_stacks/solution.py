class MyQueue:

    def __init__(self):
        self.put_stack = []
        self.get_stack = []

    def fill_get_stack(self):
        if len(self.get_stack) == 0:
            while len(self.put_stack) != 0:
                self.get_stack.append(self.put_stack.pop())

    def push(self, x: int) -> None:
        self.put_stack.append(x)

    def pop(self) -> int:
        self.fill_get_stack()
        return self.get_stack.pop()

    def peek(self) -> int:
        self.fill_get_stack()
        return self.get_stack[-1]

    def empty(self) -> bool:
        return len(self.get_stack) == 0 and len(self.put_stack) == 0
