struct MyHashMap {
    table: Box<[i32]>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyHashMap {
    const MAX_KEY: i32 = 1_000_000;
    const MIN_KEY: i32 = 0;
    const DELETED_CELL_VAL: i32 = -1;

    fn new() -> Self {
        Self {
            table: vec![Self::DELETED_CELL_VAL; Self::MAX_KEY as usize + 1].into_boxed_slice(),
        }
    }

    fn put(&mut self, key: i32, value: i32) {
        debug_assert!(key >= Self::MIN_KEY && key <= Self::MAX_KEY);
        self.table[key as usize] = value;
    }

    fn get(&self, key: i32) -> i32 {
        debug_assert!(key >= Self::MIN_KEY && key <= Self::MAX_KEY);
        self.table[key as usize]
    }

    fn remove(&mut self, key: i32) {
        debug_assert!(key >= Self::MIN_KEY && key <= Self::MAX_KEY);
        self.table[key as usize] = Self::DELETED_CELL_VAL;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * let obj = MyHashMap::new();
 * obj.put(key, value);
 * let ret_2: i32 = obj.get(key);
 * obj.remove(key);
 */
