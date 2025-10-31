impl Solution {
    pub fn third_max(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        
        let mut max_nums = [0_i32; 3];
        let mut max_nums_len = 0;
        
        for num in nums.into_iter() {
            let mut is_exist = false;

            for i in 0..max_nums_len {
                if max_nums[i] == num {
                    is_exist = true;
                    break;
                }
            }

            if is_exist {
                continue;
            }

            if max_nums_len < 3 {
                max_nums[max_nums_len] = num;
                max_nums_len += 1;
                for i in (1..max_nums_len).rev() {
                    if max_nums[i] < max_nums [i - 1] {
                        let tmp = max_nums[i];
                        max_nums[i] = max_nums[i - 1];
                        max_nums[i - 1] = tmp;
                    }
                }
            } else {
                if num > max_nums[2] {
                    max_nums[0] = max_nums[1];
                    max_nums[1] = max_nums[2];
                    max_nums[2] = num;
                } else if num > max_nums[1] {
                    max_nums[0] = max_nums[1];
                    max_nums[1] = num;
                } else if num > max_nums[0] {
                    max_nums[0] = num;
                }
            }
            
        }
        
        if max_nums_len == 2 {
            return max_nums[1];
        }

        max_nums[0]
    }
}
