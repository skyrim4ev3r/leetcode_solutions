impl Solution {
    pub fn max_sum_div_three(nums: Vec<i32>) -> i32 {
        let sum = nums.iter().map(|x| *x).sum::<i32>();

        if sum % 3 == 0 {
            return sum;
        }

        let (mut mod1_min1, mut mod1_min2, mut mod2_min1, mut mod2_min2) = (-1_i32, -1_i32, -1_i32, -1_i32);

        for num in nums.iter() {
            match *num % 3 {
                1 => {
                    if mod1_min1 == -1 || mod1_min1 > *num {
                        mod1_min2 = mod1_min1;
                        mod1_min1 = *num;
                    } else if mod1_min2 == -1 || mod1_min2 > *num {
                        mod1_min2 = *num;
                    }
                },
                2 => {
                    if mod2_min1 == -1 || mod2_min1 > *num {
                        mod2_min2 = mod2_min1;
                        mod2_min1 = *num;
                    } else if mod2_min2 == -1 || mod2_min2 > *num {
                        mod2_min2 = *num;
                    }
                },
                _ => {}
            }
        }

        match sum % 3 {
            1 => {
                let sum1 = if mod1_min1 != -1 {sum - mod1_min1} else {0};
                let sum2 = if mod2_min1 != -1 && mod2_min2 != -1 {sum - mod2_min1 - mod2_min2} else {0};

                return sum1.max(sum2);
            },
            2 => {
                let sum1 = if mod1_min1 != -1 && mod1_min2 != -1 {sum - mod1_min1 - mod1_min2} else {0};
                let sum2 = if mod2_min1 != -1 {sum - mod2_min1} else {0};

                return sum1.max(sum2);
            },
            _ => return -1
        }
    }
}
