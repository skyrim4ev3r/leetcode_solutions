struct MyHashSet {
    seen: Box<[bool]>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyHashSet {
    const MAX_KEY: i32 = 1_000_000;
    const MIN_KEY: i32 = 0;

    fn new() -> Self {
        Self {
            seen: vec![false; Self::MAX_KEY as usize + 1].into_boxed_slice(),
        }
    }

    fn add(&mut self, key: i32) {
        debug_assert!(key >= Self::MIN_KEY && key <= Self::MAX_KEY);
        self.seen[key as usize] = true;
    }

    fn remove(&mut self, key: i32) {
        debug_assert!(key >= Self::MIN_KEY && key <= Self::MAX_KEY);
        self.seen[key as usize] = false;
    }

    fn contains(&self, key: i32) -> bool {
        debug_assert!(key >= Self::MIN_KEY && key <= Self::MAX_KEY);
        self.seen[key as usize]
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * let obj = MyHashSet::new();
 * obj.add(key);
 * obj.remove(key);
 * let ret_3: bool = obj.contains(key);
 */
