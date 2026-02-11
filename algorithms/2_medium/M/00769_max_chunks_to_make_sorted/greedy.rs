impl Solution {
    pub fn max_chunks_to_sorted(arr: Vec<i32>) -> i32 {
        let len = arr.len();
        let mut curr_best = 0_usize;
        let mut count = 0_i32;

        for i in 0..len {
            curr_best = curr_best.max(arr[i] as usize);

            if i == curr_best {
                count += 1;
            }
        }

        count
    }
}
