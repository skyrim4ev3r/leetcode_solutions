impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {
        let final_len = 1 + row_index as usize;
        let mut curr: Vec<i32> = Vec::with_capacity(final_len);
        curr.push(1);
        let mut next: Vec<i32> = Vec::with_capacity(final_len);

        while curr.len() != final_len {
            let curr_len = curr.len();

            next.clear();
            next.push(1); // First element always 1
            for i in 1..curr_len {
                next.push(curr[i] + curr[i - 1]);
            }
            next.push(1); // Last element always 1
 
            std::mem::swap(&mut curr, &mut next);
        }

        curr
    }
}
