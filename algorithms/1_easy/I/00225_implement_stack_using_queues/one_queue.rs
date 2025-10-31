use std::collections::VecDeque;

struct MyStack {
    queue: VecDeque<i32>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyStack {

    fn new() -> Self {
        Self {
            queue: VecDeque::new(),
        }
    }

    fn push(&mut self, x: i32) {
        self.queue.push_back(x);
    }

    fn pop(&mut self) -> i32 {
        let len = self.queue.len();

        for i in 0..(len - 1) {
            self.queue.push_back(*self.queue.front().unwrap());
            self.queue.pop_front();
        }

        return self.queue.pop_front().unwrap();
    }

    fn top(&mut self) -> i32 {
        let len = self.queue.len();

        for i in 0..(len - 1) {
            self.queue.push_back(*self.queue.front().unwrap());
            self.queue.pop_front();
        }

        self.queue.push_back(*self.queue.front().unwrap());

        return self.queue.pop_front().unwrap();
    }

    fn empty(&self) -> bool {
        self.queue.is_empty()
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * let obj = MyStack::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: bool = obj.empty();
 */
