use std::collections::BTreeSet;

struct SmallestInfiniteSet {
    candidates_in_removed_range: BTreeSet<i32>,
    inf_set_min: i32,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl SmallestInfiniteSet {

    fn new() -> Self {
        Self {
            candidates_in_removed_range: BTreeSet::new(),
            inf_set_min: 1_i32,
        }
    }

    fn pop_smallest(&mut self) -> i32 {
        if let Some(&val) = self.candidates_in_removed_range.iter().next() {
            self.candidates_in_removed_range.remove(&val);
            return val;
        } else {
            let smallest = self.inf_set_min;
            self.inf_set_min += 1;
            return smallest;
        }
    }

    fn add_back(&mut self, num: i32) {
        if num < self.inf_set_min {
            self.candidates_in_removed_range.insert(num);

            while self.candidates_in_removed_range.remove(&(self.inf_set_min - 1)) {
                self.inf_set_min -= 1;
            }
        }
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * let obj = SmallestInfiniteSet::new();
 * let ret_1: i32 = obj.pop_smallest();
 * obj.add_back(num);
 */
