impl Solution {
    #[inline(always)]
    fn calc_base(customers: &Vec<i32>, grumpy: &Vec<i32>) -> i32 {
        let mut base = 0_i32;

        for (i, c) in customers.iter().enumerate() {
            if (grumpy[i] == 0) {
                base += *c;
            }
        }

        base
    }

    pub fn max_satisfied(customers: Vec<i32>, grumpy: Vec<i32>, minutes: i32) -> i32 {
        let base = Self::calc_base(&customers, &grumpy);
        let len = customers.len();
        let windows_len = minutes as usize;
        let mut curr = 0_i32;

        for i in 0..windows_len {
            if grumpy[i] == 1 {
                curr += customers[i];
            }
        }

        let mut max = curr;

        for i in windows_len..len {
            if grumpy[i] == 1 {
                curr += customers[i];
            }

            if grumpy[i - windows_len] == 1 {
                curr -= customers[i - windows_len];
            }

            max = max.max(curr);
        }

        base + max
    }
}
