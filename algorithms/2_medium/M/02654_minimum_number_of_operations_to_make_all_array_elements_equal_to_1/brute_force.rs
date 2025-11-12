impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        fn gcd(a: i32, b: i32) -> i32 {
            if b == 0 {
                a
            } else {
                gcd(b, a % b)
            }
        }

        let len = nums.len();
        let mut all_gcd = 0_i32;
        let mut count_ones = 0_i32;

        for num in nums.iter() {
            if *num == 1 {
                count_ones += 1;
            }

            all_gcd = gcd(all_gcd, *num);
        }

        if all_gcd != 1 {
            return -1;
        } 

        if count_ones > 0 {
            return len as i32 - count_ones;
        }

        let mut min_len = usize::MAX;

        for i in 0..len {
            if min_len == 2 {
                break;
            }

            let mut curr_gcd = 0;

            for (index, it) in nums.iter().skip(i).enumerate() {
                curr_gcd = gcd(curr_gcd, *it);

                if curr_gcd == 1 {
                    min_len = index + 1;
                    break;
                }
            }
        }

        let op_need_to_make_one_x_one = min_len as i32 - 1;
        let op_need_after_it = len as i32 - 1;

        op_need_to_make_one_x_one + op_need_after_it
    }
}
