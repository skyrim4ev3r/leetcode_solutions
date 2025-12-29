use std::collections::{BinaryHeap, HashMap};
use std::cmp::Ordering;

#[derive(Debug, Eq, PartialEq)]
struct Data {
    freq: u16,
    ts: u16,
    val: i32
}

impl Ord for Data {
    fn cmp(&self, other: &Self) -> Ordering {
        if self.freq == other.freq {
            return self.ts.cmp(&other.ts);
        }

        self.freq.cmp(&other.freq)
    }
}

impl PartialOrd for Data {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

struct FreqStack {
    ts: u16,
    freqs: HashMap<i32, u16>,
    heap: BinaryHeap<Data>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl FreqStack {

    fn new() -> Self {
        Self {
            ts: 0_u16,
            freqs: HashMap::new(),
            heap: BinaryHeap::new(),
        }
    }
    
    fn push(&mut self, val: i32) {
        self.ts += 1;
        let freq = self.freqs.entry(val).or_insert(0);
        *freq += 1;

        self.heap.push(Data{
            ts: self.ts,
            freq: *freq,
            val: val,
        })
    }
    
    fn pop(&mut self) -> i32 {
        let data = self.heap.pop().unwrap();
        *self.freqs.get_mut(&data.val).unwrap() -= 1;
        
        data.val
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * let obj = FreqStack::new();
 * obj.push(val);
 * let ret_2: i32 = obj.pop();
 */
