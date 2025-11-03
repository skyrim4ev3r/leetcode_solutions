impl Solution {
    pub fn num_jewels_in_stones(jewels: String, stones: String) -> i32 {
        let mut jewels_map = [false; 128];
        for jewel in jewels.into_bytes().into_iter() {
            jewels_map[jewel as usize] = true;
        }

        let mut count = 0;

        for stone in stones.into_bytes().into_iter() {
            if jewels_map[stone as usize] {
                count += 1;
            }
        }

        count
    }
}
