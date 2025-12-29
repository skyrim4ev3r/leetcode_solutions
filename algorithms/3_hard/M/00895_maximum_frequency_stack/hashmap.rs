use std::collections::HashMap;

struct FreqStack {
    max_freq: u16,
    freqs: HashMap<i32, u16>,
    hash_stack: HashMap<u16, Vec<i32>>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl FreqStack {

    fn new() -> Self {
        Self {
            max_freq: 0_u16,
            freqs: HashMap::new(),
            hash_stack: HashMap::new(),
        }
    }

    fn push(&mut self, val: i32) {
        let freq = self.freqs.entry(val).or_insert(0);
        *freq += 1;
        self.max_freq = self.max_freq.max(*freq);
        self.hash_stack.entry(*freq).or_insert(Vec::new()).push(val);
    }

    fn pop(&mut self) -> i32 {
        let vec = self.hash_stack.get_mut(&self.max_freq).unwrap();
        let val = vec.pop().unwrap();

        *self.freqs.get_mut(&val).unwrap() -= 1;

        if vec.len() == 0 && self.max_freq != 0 {
            self.max_freq -= 1;
        }

        val
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * let obj = FreqStack::new();
 * obj.push(val);
 * let ret_2: i32 = obj.pop();
 */
