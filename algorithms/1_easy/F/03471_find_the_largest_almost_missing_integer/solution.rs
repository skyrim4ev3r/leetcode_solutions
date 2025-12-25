use std::collections::HashMap;

impl Solution {
    pub fn largest_integer(nums: Vec<i32>, k: i32) -> i32 {
        let len = nums.len();

        if k as usize >= len {
            return nums.into_iter().max().unwrap();
        }

        if 1 < k {
            let freq_first = nums.iter().filter(|x| **x == nums[0]).count();
            let freq_last = nums.iter().filter(|x| **x == nums[len - 1]).count();

            if freq_first == 1 && freq_last == 1 {
                return nums[0].max(nums[len - 1]);
            } else if freq_first == 1 {
                return nums[0];
            } else if freq_last == 1 {
                return nums[len - 1];
            } else {
                return -1;
            }
        }

        let mut freqs: HashMap<i32, i32> = HashMap::new();

        for num in nums {
           *freqs.entry(num).or_insert(0) += 1;
        }

        let mut max = i32::MIN;
        let mut has_valid_ans = false;

        for (num, freq) in freqs.into_iter() {
            if freq == 1 {
                max = max.max(num);
                has_valid_ans = true;
            }
        }

        if !has_valid_ans {
            return -1;
        }

        max
    }
}
