// BAD SOLUTION: only safe for single‑threaded use or with at most one live instance.
// If called concurrently from multiple threads, this will deadlock (all but one thread hang).
// However, deadlock is still better than undefined behavior or data races.

use std::sync::{Mutex, MutexGuard};

const MAX_KEY: i32 = 1_000_000;
const MIN_KEY: i32 = 0;
const DELETED_CELL_VAL: i32 = -1;

struct HashMapCustom {
    vals: [i32; MAX_KEY as usize + 1],
    stamps: [i32; MAX_KEY as usize + 1],
    gens: i32,
}

impl HashMapCustom {
    const fn new() -> Self {
        Self {
            vals: [-1; MAX_KEY as usize + 1],
            stamps: [0; MAX_KEY as usize + 1],
            gens: 0,
        }
    }
}

static HASH_MAP: Mutex::<HashMapCustom> = Mutex::new(HashMapCustom::new());

struct MyHashMap {
    table: MutexGuard<'static, HashMapCustom>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyHashMap {

    fn new() -> Self {
        let mut table = HASH_MAP.lock().unwrap();
        table.gens += 1;
        Self {
            table: table,
        }
    }

    fn put(&mut self, key: i32, value: i32) {
        debug_assert!(key >= MIN_KEY && key <= MAX_KEY);
        self.table.vals[key as usize] = value;
        self.table.stamps[key as usize] = self.table.gens;
    }

    fn get(&self, key: i32) -> i32 {
        debug_assert!(key >= MIN_KEY && key <= MAX_KEY);
        if self.table.stamps[key as usize] != self.table.gens { -1 } else { self.table.vals[key as usize] }
    }

    fn remove(&mut self, key: i32) {
        debug_assert!(key >= MIN_KEY && key <= MAX_KEY);
        self.table.vals[key as usize] = DELETED_CELL_VAL;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * let obj = MyHashMap::new();
 * obj.put(key, value);
 * let ret_2: i32 = obj.get(key);
 * obj.remove(key);
 */
