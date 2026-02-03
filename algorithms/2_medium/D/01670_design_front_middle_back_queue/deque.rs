use std::collections::VecDeque;

struct FrontMiddleBackQueue {
    q_l: VecDeque<i32>,
    q_r: VecDeque<i32>,
}

impl FrontMiddleBackQueue {

    #[inline(always)]
    fn balance_queues(&mut self) {
        while self.q_l.len() > self.q_r.len() {
            self.q_r.push_front(self.q_l.pop_back().unwrap());
        }

        while self.q_r.len() - self.q_l.len() > 1 {
            self.q_l.push_back(self.q_r.pop_front().unwrap());
        }
    }

    fn new() -> Self {
        Self {
            q_l: VecDeque::new(),
            q_r: VecDeque::new(),
        }
    }

    fn push_front(&mut self, val: i32) {
        self.q_l.push_front(val);
    }

    fn push_middle(&mut self, val: i32) {
        self.balance_queues();
        self.q_l.push_back(val);
    }

    fn push_back(&mut self, val: i32) {
        self.q_r.push_back(val);
    }

    fn pop_front(&mut self) -> i32 {
        if let Some(val) = self.q_l.pop_front() {
            return val;
        } else if let Some(val) = self.q_r.pop_front() {
            return val;
        }

       -1
    }

    fn pop_middle(&mut self) -> i32 {
        self.balance_queues();

        if self.q_l.len() == self.q_r.len() {
            if let Some(val) = self.q_l.pop_back() {
                return val;
            }
        } else {
            if let Some(val) = self.q_r.pop_front() {
                return val;
            }
        }

        -1
    }

    fn pop_back(&mut self) -> i32 {
        if let Some(val) = self.q_r.pop_back() {
            return val;
        } else if let Some(val) = self.q_l.pop_back() {
            return val;
        }

        -1
    }
}
