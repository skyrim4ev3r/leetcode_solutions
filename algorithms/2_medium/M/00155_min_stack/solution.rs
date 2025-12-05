struct MinStack {
    stack: Vec<i32>,
    min_stack: Vec<i32>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MinStack {

    fn new() -> Self {
        Self {
            stack: Vec::new(),
            min_stack: Vec::new(),
        }
    }

    fn push(&mut self, val: i32) {
        self.stack.push(val);

        match self.min_stack.last() {
            None => self.min_stack.push(val),
            Some(min_val) => {
                if *min_val >= val {
                    self.min_stack.push(val);
                }
            },
        }
    }

    fn pop(&mut self) {
        let val = self.stack.pop().unwrap();

        if let Some(min_val) = self.min_stack.last() && *min_val == val {
            self.min_stack.pop();
        }
    }

    fn top(&self) -> i32 {
        *self.stack.last().unwrap()
    }

    fn get_min(&self) -> i32 {
        if let Some(min_val) = self.min_stack.last() {
            return *min_val;
        }

        *self.stack.last().unwrap()
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * let obj = MinStack::new();
 * obj.push(val);
 * obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: i32 = obj.get_min();
 */
