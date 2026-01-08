impl Solution {
    pub fn sequential_digits(low: i32, high: i32) -> Vec<i32> {
        let mut res: Vec<i32> = Vec::new();

        for i in 1..10_i32 {
            let mut curr_num = 0_i32;
            let mut curr_dig = i;

            while curr_num <= high {
                if curr_num >= low {
                    res.push(curr_num);
                }

                if curr_dig > 9 {
                    break;
                }

                curr_num = curr_num * 10 + curr_dig;
                curr_dig += 1;
            }
        }

        res.sort_unstable();

        res
    }
}
