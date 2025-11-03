impl Solution {
    pub fn decrypt(code: Vec<i32>, k: i32) -> Vec<i32> {
        
        let len = code.len();

        if k == 0 {
            return vec![0_i32; len];
        }

        let mut res: Vec<i32> = Vec::with_capacity(len);

        let mut left = 0_usize;
        let mut right = 0_usize;

        if k < 0 {
            right = len - 1;
            left = len - k.abs() as usize;
        } else {
            right = k as usize;
            left = 1;
        }

        let mut curr_sum = code[left..=right].iter().sum();

        for i in 0..len {
            res.push(curr_sum);

            curr_sum -= code[left];
            left += 1;
            if left == len {
                left = 0;
            }

            right += 1;
            if right == len {
                right = 0;
            }
            curr_sum += code[right];
        }

        res
    }
}
