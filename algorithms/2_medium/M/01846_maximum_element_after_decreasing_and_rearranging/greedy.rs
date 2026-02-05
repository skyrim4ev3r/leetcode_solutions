impl Solution {
    pub fn maximum_element_after_decrementing_and_rearranging(mut arr: Vec<i32>) -> i32 {
        arr.sort_unstable();
        let mut curr = 0_i32;

        for num in arr.into_iter() {
            if num > curr {
                curr += 1;
            }
        }

        curr
    }
}
