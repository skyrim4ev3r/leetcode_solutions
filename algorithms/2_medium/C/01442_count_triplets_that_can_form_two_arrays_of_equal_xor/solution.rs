impl Solution {
    pub fn count_triplets(arr: Vec<i32>) -> i32 {
        let len = arr.len();
        let mut count = 0_i32;

        for i in 0..len {
            let mut curr_xor = 0_i32;

            for j in i..len {
                curr_xor ^= arr[j];

                if curr_xor == 0 {
                    count += (j - i) as i32;
                }
            }
        }

        count
    }
}
